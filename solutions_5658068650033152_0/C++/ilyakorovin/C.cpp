#include <iostream>
#include <cstring>

using namespace std;

int a[30][30];
bool used[30][30];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int dfs(int x, int y, int n, int m)
{
    used[x][y] = true;
    int res = 1;
    for (int i = 0; i < 4; ++i) {
        int sx = x + dx[i];
        int sy = y + dy[i];
        if (sx < 0 || sy < 0 || sx >= n || sy >= m || used[sx][sy] || a[sx][sy]) {
            continue;
        }
        res += dfs(sx, sy, n, m);
    }
    return res;
}


int check(int n, int m)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            used[i][j] = false;
        }
    }
    int l = 0, r = 0; 
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i][0] && !a[i][0]) {
            res += dfs(i, 0, n, m);
        }
        if (!used[i][m - 1] && !a[i][m - 1]) {
            res += dfs(i, m - 1, n, m);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (!used[0][i] && !a[0][i]) {
            res += dfs(0, i, n, m);
        }
        if (!used[n - 1][i] && !a[n - 1][i]) {
            res += dfs(n - 1, i, n, m);
        }
    }
    res = n * m - res;
    return res;
}

int solve(int n, int m, int k)
{
    int nn = n * m;
    int nmask = 1 << nn;
    for (int kk = 1; kk <= k; ++kk) {
        for (int mask = 0; mask < nmask; ++mask) {
            int cnt = 0;
            for (int i = 0; i < nn; ++i) {
                if (mask & (1 << i)) {
                    ++cnt;   
                }
            }
            if (cnt != kk) {
                continue;
            }
            /*
            for (int i = 0; i <= n + 1; ++i) {
                for (int j = 0; j <= m + 1; ++j) {
                    a[i][j] = 0;
                }
            }
            */
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    a[i][j] = mask & (1 << (i * m + j));
                }
            }
            if (check(n, m) >= k) {
                return kk;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int n, m, k;
        cin >> n >> m >> k;
        int res = solve(n, m, k);
        cout << "Case #" << i + 1 << ": " << res << endl;
    }
    return 0;
}
