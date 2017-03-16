#include <bits/stdc++.h>

using namespace std;

int cnt[2501];

main () {

    freopen ("b-small.in", "r", stdin);
    freopen ("b.out", "w", stdout);

    int T;
    cin >> T;

    for (int num = 1; num <= T; ++num) {
        cout << "Case #" << num <<  ": ";
        int n;
        cin >> n;
        for (int i = 0; i <= 2500; ++i) cnt[i] = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int a;
                cin >> a;
                cnt[a]++;
            }
        }
        for (int i = 0; i <= 2500; ++i) {
            if (cnt[i] % 2 == 1) cout << i << " ";
        }
        cout << "\n";
    }
}
