#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Stack of pancakes
 */
class Stack {
private:
    vector<bool> pancakes;
    unsigned int size;
    friend ostream& operator<<(ostream& strm, const Stack& stack);

public:
    /*
     * Construct stack from a sequence of '+' and '-' signs
     */
    Stack(string str) {
        size = str.length();
        for (int i = 0; i < str.length(); i++) {
            pancakes.push_back((str[i] == '+') ? true : false);
        }
    }

    /*
     * Flip n pancakes on the top of the stack
     */
    void flip(unsigned int n) {
        for (int i = 0; i < n; i++) {
            pancakes[i] = !pancakes[i];
        }
        reverse(pancakes.begin(), pancakes.begin() + n);
    }

    /*
     * Test if all pancakes are happy side up
     */
    bool isHappy() {
        for (int i = 0; i < size; i++) {
            if (!pancakes[i]) {
                return false;
            }
        }
        return true;
    }

    /*
     * Compute the minimum number of flips necessary to have all the pancakes
     * happy side up
     */
    unsigned int compute() {
        unsigned int flips = 0;
        unsigned int flipAt;
        while (!isHappy()) {
            flipAt = size;
            for (int i = 0; i < size; i++) {
                if (pancakes[i] != pancakes[0]) {
                    flipAt = i;
                    break;
                }
            }
            flip(flipAt);
            flips++;
        }
        return flips;
    }
};

/*
 * Print stack of pancakes as a sequence of '+' and '-' signs
 */
ostream& operator<<(ostream& strm, const Stack& stack) {
    for (int i = 0; i < stack.size; i++) {
        strm << (stack.pancakes[i] ? '+' : '-');
    }
    return strm;
}

int main() {
    unsigned short t;
    string stack_str;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> stack_str;
        Stack stack(stack_str);
        cout << "Case #" << i + 1 << ": " << stack.compute() << endl;
    }

    return 0;
}
