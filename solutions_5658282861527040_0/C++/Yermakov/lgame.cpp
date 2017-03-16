#include <iostream>
#include <cstdio>

using namespace std;

main () {
    freopen ("b.in", "r", stdin);
    freopen ("b.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int a, b, k;
        cin >> a >> b >> k;
        int ans = 0;
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                int x = i & j;
                if (x < k) ++ans;
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
