#include <iostream>

using namespace std;

bool done(string s) {
    for (char c: s) {
        if (c == '-') return false;
    }
    return true;
}

void flip(string &s) {
    int i = 0;
    while (i < s.size() && (i == 0 || s[i - 1] != s[i])) {
        if (s[i] == '+') s[i] = '-';
        else if (s[i] == '-') s[i] = '+';
        i += 1;
    }
}

int main() {
    int t;
    cin >> t;

    for (int q = 0; q < t; ++q) {
        string s;
        cin >> s;

        int flips = 0;

        while (!done(s)) {
            flip(s);
            flips += 1;
        }

        cout << "Case #" << q + 1 << ": " << flips << endl;
    }
}
