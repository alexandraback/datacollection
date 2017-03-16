#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Invertible {
private:
    deque<bool> data;
    bool inverted;
public:
    Invertible() {
        this->inverted = false;
    }

    void push_back(bool d) {
        // Only insert at the beginning, no inversions
        this->data.push_back(d);
    }

    void invert() {
        this->inverted = !this->inverted;
    }

    bool empty() {
        return this->data.empty();
    }

    bool back() {
        if (this->inverted)
            return !this->data.front();
        else
            return this->data.back();
    }

    void pop_back() {
        if (this->inverted)
            this->data.pop_front();
        else
            this->data.pop_back();
    }

    bool front() {
        if (this->inverted)
            return !this->data.back();
        else
            return this->data.front();
    }

    void pop_front() {
        if (this->inverted)
            this->data.pop_front();
        else
            this->data.pop_back();
    }

    // Not as lvalue!
    bool operator[](size_t index) {
        if (!this->inverted)
            return this->data[index];
        else
            return !this->data[this->data.size() - index - 1];
    }

    void flipFront(int n) {
        if (this->inverted) {
            int offset = this->data.size() - n;
            for (int i = 0; i < n / 2; i++) {
                bool tmp = this->data[i + offset];
                this->data[i + offset] = !this->data[this->data.size() - i - 1];
                this->data[this->data.size() - i - 1] = !tmp;
            }
            if (n % 2 == 1)
                this->data[offset + n / 2] = !this->data[offset + n / 2];
        }
        else {
            for (int i = 0; i < n / 2; i++) {
                bool tmp = this->data[i];
                this->data[i] = !this->data[n - i - 1];
                this->data[n - i - 1] = !tmp;
            }
            if (n % 2 == 1)
                this->data[n / 2] = !this->data[n / 2];
        }
    }

    void flipAllPositiveInFront() {
        int maxl = -1;

        while ((*this)[maxl + 1])
            maxl++;

        flipFront(maxl + 1);
    }

    void printDebug() {
        for (unsigned i = 0; i < this->data.size(); i++) {
            cout << (*this)[i];
        }
        cout << endl;
    }
};

void assert(bool x) {
    if (!x) {
        printf("ERROR ERROR ERROR\n");
    }
}

void test() {
    Invertible inv;

    inv.push_back(true);
    inv.push_back(true);
    inv.push_back(true);
    inv.push_back(true);
    inv.push_back(true);
    inv.push_back(true);
    inv.push_back(true);
    inv.push_back(true);
    inv.push_back(true);
    inv.push_back(true);
    inv.push_back(true);

    assert(!inv.empty());
    assert(inv[0]);
    assert(inv.front());
    assert(inv.back());

    inv.invert();
    assert(!inv.empty());
    assert(!inv[0]);
    assert(!inv.front());
    assert(!inv.back());

    inv.flipFront(2);
    assert(inv[0]);
    assert(inv[1]);
    assert(!inv[2]);

    inv.invert();
    assert(inv[0]);
    assert(inv[1]);
    assert(inv[2]);
    inv.flipFront(2);
    assert(!inv[0]);
    assert(!inv[1]);
    assert(inv[2]);

    inv.flipFront(4);
    assert(!inv[0]);
    assert(!inv[1]);
    assert(inv[2]);

    inv.flipFront(3);
    assert(!inv[0]);
    assert(inv[1]);
    assert(inv[2]);
}

int main(int argc, char *argv[]) {
    // test();

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        long flips = 0;

        Invertible pancakes;

        string line;
        cin >> line;
        for (char c : line)
            if (c == '+')
                pancakes.push_back(true);
            else
                pancakes.push_back(false);

        while (!pancakes.empty()) {
            // pancakes.printDebug();
            // Remove good side up from the back
            while (!pancakes.empty() && pancakes.back() == true)
                pancakes.pop_back();

            if (pancakes.empty()) break;

            if (pancakes.front() == false) {
                pancakes.invert();
                flips++;
            }
            else {
                pancakes.flipAllPositiveInFront();
                flips++;
            }
        }

        printf("Case #%d: %ld\n", i + 1, flips);
    }

    return 0;
}
