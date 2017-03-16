#include <iostream>

using namespace std;

int t;
string s1, s2;
string ans1, ans2;
int ans = 1e9;
int n;

void go(int n, int x) {
    if (x == 2 * n) {
        int pw = 1;
        int sum1 = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum1 += (s1[i] - '0') * pw;
            pw *= 10;
        }
        pw = 1;
        int sum2 = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum2 += (s2[i] - '0') * pw;
            pw *= 10;
        }
        if (ans > abs(sum1 - sum2)) {
            ans = abs(sum1 - sum2);
            ans1 = s1;
            ans2 = s2;
        }
        return;
    }
    if (x < n) {
        if (s1[x] != '?') {
            go(n, x + 1);
        } else {
            for (int i = 0; i < 10; i++) {
                s1[x] = (char) ('0' + i);
                go(n, x + 1);
                s1[x] = '?';
            }
        }
    } else {
        if (s2[x - n] != '?') {
            go(n, x + 1);
        } else {
            for (int i = 0; i < 10; i++) {
                s2[x - n] = (char) ('0' + i);
                go(n, x + 1);
                s2[x - n] = '?';
            }
        }
    }
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int r = 0; r < t; r++) {
        cin >> s1 >> s2;
        n = s1.size();
        if (n == 3) {
            if (s1.compare("???") == 0 && s2.compare("???") == 0) {
                cout << "Case #" << r + 1 << ": 000 000\n";
                continue;
            }
        }
        ans = 1e9;
        go(n, 0);
        cout << "Case #" << r + 1 << ": " << ans1 << " " << ans2 << "\n";
    }
}

