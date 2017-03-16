#include <bits/stdc++.h>
using namespace std;

string s;

int main(void) {
    if (fopen("a-small.in", "r")) {
        freopen("a-small.in", "r", stdin);
        freopen("a-small.out", "w", stdout);
    }
    if (fopen("a-large.in", "r")) {
        freopen("a-large.in", "r", stdin);
        freopen("a-large.out", "w", stdout);
    }
    int t;
    cin >> t;
    for (int ii = 1; ii <= t; ii++) {
        cin >> s;
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (i == 0) ans += s[i];
            else {
                if (s[i] >= ans[0]) ans = s[i] + ans;
                else ans += s[i];
            }
        }
        printf("Case #%d: ", ii);
        cout << ans << "\n";
    }
    return 0;
}
