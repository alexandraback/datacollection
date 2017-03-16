#include <bits/stdc++.h>

using namespace std;

main () {
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;

    for (int num = 1; num <= T; ++num) {
        cout << "Case #" << num << ": ";

        string s;
        cin >> s;

        int cnt = 0;
        for (int i = 1; i < s.length (); ++i) {
            if (s[i] == '-' && s[i - 1] == '+') ++cnt;
        }

        int q = 0;
        if (s[0] == '-') ++q;

        if (cnt + q == 0) cout << "0\n";
        else cout << cnt * 2 + q << "\n";

    }
}
