#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

#define D(x) x

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for (int testCase = 1; testCase <= numCases; testCase++) {
        string stack;
        cin >> stack;

        int plus = 0, minus = 0;
        for (char c : stack) {
            int newPlus, newMinus;

            if (c == '+') {
                newPlus = plus;
                newMinus = plus + 1;
            } else {
                newPlus = minus + 1;
                newMinus = minus;
            }

            plus = newPlus;
            minus = newMinus;
        }

        cout << "Case #" << testCase << ": " << plus << endl;
    }
}
