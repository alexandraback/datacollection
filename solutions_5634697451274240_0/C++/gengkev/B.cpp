#include <iostream>
using namespace std;

int solve(string s) {
    int len = s.length();
    int count = 0;
    for (int i = 1; i < len; i++) {
        if (s[i] != s[i-1]) {
            count++;
        }
    }
    if (s[len-1] == '-') {
        count++;
    }
    return count;
}

int main() {
    int T; cin >> T;
    cin.ignore(256, '\n');

    for (int i = 1; i <= T; i++) {
        string s; getline(cin, s);

        // ew windows
        int len = s.length();
        if (len && s[len-1] == '\r') {
            s.erase(len-1);
        }

        int res = solve(s);

        cout << "Case #" << i << ": ";
        cout << res << '\n';
    }
}
