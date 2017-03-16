#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char s[N];

int main() {
    ios::sync_with_stdio(false);
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int ntest; cin >> ntest;
    for (int it = 1; it <= ntest; ++it) {
        cout << "Case #" << it << ": ";
        cin >> s;
        int n = strlen(s);
        int lastPos = n;
        vector<bool> was(n, 0);
        while (lastPos > 0) {
            char best = 'A';
            for (int i = lastPos - 1; i >= 0; --i)
                best = max(best, s[i]);

            int nxtPos = 0;
            for (int i = lastPos - 1; i >= 0; --i) if (s[i] == best) {
                nxtPos = i;
                break;
            }
            was[nxtPos] = true;
            lastPos = nxtPos;
        }
        for (int i = n - 1; i >= 0; --i) if (was[i]) cout << s[i];
        for (int i = 0; i < n; ++i) if (!was[i]) cout << s[i];
        cout << endl;
    }
    return 0;
}
