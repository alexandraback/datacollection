#include <bits/stdc++.h>

using namespace std;

main () {

    freopen ("D.in", "r", stdin);
    freopen ("out.txt", "w", stdout);

    int T;
    cin >> T;

    for (int num = 1; num <= T; ++num) {

        cout << "Case #" << num << ": ";

        int k, c, s;
        cin >> k >> c >> s;

        if (c == 1 || k == 1) {
            if (s < k) cout << "IMPOSSIBLE";
            else for (int i = 1; i <= k; ++i) cout << i << " ";
            cout << "\n";
        }
        else {
            if (s < k - 1) cout << "IMPOSSIBLE";
            else for (int i = 2; i <= k; ++i) cout << i << " ";
            cout << "\n";
        }

    }
}
