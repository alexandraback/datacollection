#include <bits/stdc++.h>

using namespace  std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("2.txt", "w", stdout);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s;
        cin >> s;

        string ans = "";
        ans = ans + s[0];

        for (int i = 1; i < s.size(); i++) {
            if (s[i] >= ans[0]) {
                ans = s[i] + ans;
            } else {
                ans = ans + s[i];
            }
        }

        cout << "Case #" << cs + 1 << ": " << ans << endl;
    }

    return 0;
}


