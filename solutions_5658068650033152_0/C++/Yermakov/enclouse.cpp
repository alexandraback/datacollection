#include <iostream>
#include <cstdio>

using namespace std;

bool used[21][21];
int a[21][21], n, m;

bool ok(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (used[x][y]) return false;
    if (a[x][y] == 1) return false;
    return true;
}

void dfs(int x, int y) {
    used[x][y] = true;
    if (ok(x + 1, y)) dfs(x + 1, y);
    if (ok(x - 1, y)) dfs(x - 1, y);
    if (ok(x, y + 1)) dfs(x, y + 1);
    if (ok(x, y - 1)) dfs(x, y - 1);
}

main () {
    freopen ("c.in", "r", stdin);
    freopen ("c.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int k;
        cin >> n >> m >> k;
        int ans = k;
        for (int mask = 0; mask < 1 << (n * m); ++mask) {
            int x = mask;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    a[i][j] = x % 2;
                    x /= 2;
                    cnt += a[i][j];
                    used[i][j] = false;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (ok(i, 0)) dfs(i, 0);
                if (ok(i, m - 1)) dfs(i, m - 1);
            }
            for (int i = 0; i < m; ++i) {
                if (ok(0, i)) dfs(0, i);
                if (ok(n - 1,i)) dfs(n - 1, i);
            }
            int enc = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!used[i][j]) enc++;
                }
            }
            if (enc >= k && cnt < ans) ans = cnt;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
