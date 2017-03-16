#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>

using namespace std;

const int MAX_N = 12, MAX_E = 12;

int T, ans, e, r, n, v;
int f[MAX_N][MAX_E];

int main() {
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        memset(f, 0, sizeof f);
        ans = 0;
        cin >> e >> r >> n;
        r = min(r, e);
        for (int i = 1; i <= n; ++i) {
            cin >> v;
            for (int j = r, last; j <= e; ++j) {
                last = j - r;
                for (int k = last; k <= e; ++k) {
                    f[i][j] = max(f[i][j], f[i - 1][k] + (k - last) * v);
                }
                ans = max(f[i][j], ans);
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
