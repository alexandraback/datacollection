
#include <iostream>
#include <string>

using namespace std;

int solve(const string &s) {
    int n = s.size();
    int cur = 0, added = 0;
    for (int i = 0; i < n; i++) {
        if (cur < i) {
            added += i - cur;
            cur = i;
        }
        cur += s[i] - '0';
    }
    return added;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int smax;
        string s;
        cin >> smax >> s;
        cout << "Case #" << t << ": " << solve(s) << endl;
    }
}