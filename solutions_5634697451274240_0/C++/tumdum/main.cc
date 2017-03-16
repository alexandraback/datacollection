#include <iostream>
#include <string>

using namespace std;

void solve(const int C) {
    string input;
    cin >> input;
    char last = input[0];
    int groups = 0;
    for (const char c : input) {
        if (last != c) {
            ++groups;
            last = c;
        }
    }
    if (input.back() == '-') {
        ++groups;
    }
    cout << "Case #" << C << ": " << groups << endl;
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
}
