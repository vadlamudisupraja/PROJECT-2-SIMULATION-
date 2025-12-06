#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;        // array to store queue elements
    int capacity;    // maximum capacity of the queue
    int front;       // index of front element
    int rear;        // index of last element
    int count;       // current size of the queue

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "\nQueue Overflow! No more customers can wait.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
        cout << "Customer with token " << x << " joined the queue.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "\nQueue Underflow! No customers to serve.\n";
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % capacity;
        count--;
        cout << "Customer with token " << x << " has been served.\n";
        return x;
    }

    int getFront() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[rear];
    }

    int size() const {
        return count;
    }

    void displayQueue() const {
        if (isEmpty()) {
            cout << "\nQueue is empty. No customers waiting.\n";
            return;
        }

        cout << "\nCurrent Queue (front -> rear):\n";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << arr[i] << "  ";
            i = (i + 1) % capacity;
        }
        cout << "\n";
        cout << "Front index: " << front << ", Rear index: " << rear << "\n";
    }
};

int main() {
    int maxSize;
    cout << "====== TICKET COUNTER QUEUE SIMULATION ======\n";
    cout << "Enter maximum number of customers that can wait in queue: ";
    cin >> maxSize;

    CircularQueue q(maxSize);
    int choice;
    int nextToken = 1; // token number generator

    do {
        cout << "\n------------- MENU -------------\n";
        cout << "1. New customer arrives (Enqueue)\n";
        cout << "2. Serve next customer (Dequeue)\n";
        cout << "3. Show all waiting customers\n";
        cout << "4. Show front & rear customer\n";
        cout << "5. Show queue size\n";
        cout << "6. Exit\n";
        cout << "--------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            q.enqueue(nextToken);
            nextToken++;
            q.displayQueue();
            break;

        case 2:
            q.dequeue();
            q.displayQueue();
            break;

        case 3:
            q.displayQueue();
            break;

        case 4: {
            int f = q.getFront();
            int r = q.getRear();
            if (!q.isEmpty()) {
                cout << "Front customer token: " << f << "\n";
                cout << "Rear  customer token: " << r << "\n";
            }
            break;
        }

        case 5:
            cout << "Number of customers waiting: " << q.size() << "\n";
            break;

        case 6:
            cout << "Exiting simulation...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}