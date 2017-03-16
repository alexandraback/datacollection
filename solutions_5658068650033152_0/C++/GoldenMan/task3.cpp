#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

const long long MD = 1000 * 1000 * 1000 + 7;

int try_(int i, int j, int a[100][100], int n, int m) {
    if (i < 0) {
        return 0;
    }
    if (j < 0) {
        return 0;
    }
    if (i >= n || j >=m ) {
        return 0;
    }
    if (a[i][j] == 1) {
        return 1;
    }
    if (a[i][j] == 0) {
        return 0;
    }
    if (a[i][j] == 2) {
        return 1;
    }
    a[i][j] = 2;
    int r = 1;
    r *= try_(i - 1, j, a, n, m);
    if (!r) {
        a[i][j] = r;
        return r;
    }
    r *= try_(i + 1, j, a, n, m);
    if (!r) {
        a[i][j] = r;
        return r;
    }
    r *= try_(i, j - 1, a, n, m);
    if (!r) {
        a[i][j] = r;
        return r;
    }
    r *= try_(i, j + 1, a, n, m);
    if (!r) {
        a[i][j] = r;
        return r;
    }
    a[i][j] = r;
    return r;
}

void dfs(int i, int j, int n, int m, int &ans, int a[100][100], int k) {
    int old_i = i;
    int old_j = j;
    ++j;
    if (j == m) {
        j = 0;
        ++i;
    }
    if (i == n) {
        int prc = 0;
        for (int i1 = 0; i1 < n; ++i1) {
            for (int j1 = 0; j1 < m; ++j1) {
                if (a[i1][j1]) {
                    ++prc;
                }
            }
        }
        if (prc >= ans) {
            return;
        }
        int cnt = 0;
        int ft[100][100];
        for (int i1 = 0; i1 < n; ++i1) {
            for (int j1 = 0; j1 < m; ++j1) {
                ft[i1][j1] = -1;
                if (a[i1][j1]) {
                    ft[i1][j1] = 1;
                }
            }
        }
        for (int i1 = 0; i1 < n; ++i1) {
            for (int j1 = 0; j1 < m; ++j1) {
                ft[i1][j1] = try_(i1, j1, ft, n, m);
            }
        }
        for (int i1 = 0; i1 < n; ++i1) {
            for (int j1 = 0; j1 < m; ++j1) {
                cnt += ft[i1][j1];
            }
        }
        if (cnt >= k)
            ans = prc;
    } else {
        a[old_i][old_j] = 0;
        dfs(i, j, n, m, ans, a, k);
        a[old_i][old_j] = 1;
        dfs(i, j, n, m, ans, a, k);
    }
}

int solve_2(int n, int m, int k) {
    int ans = k;
    int a[100][100];
    dfs(0, 0, n, m, ans, a, k);
    return ans;
}

int solve(int test) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int ans2 = solve_2(n, m, k);
    //cout << "Case #" << test << ": " << ans2 << endl;
    int ans = k;
    if (n > m) {
        swap(n, m);
    }
    if (n < 3) {
        goto lbl;
    }
    if (k < 5) {
        goto lbl;
    }
    for (int i = 3; i <= n; ++i) {
        for (int j = 3; j <= m; ++j) {
            int price = 2 * (i - 2) + 2 * (j - 2);
            int cnt = i * j - 4;
            if (cnt >= k && price < ans) {
                ans = price;
            }
        }
    }
    if (k > n * m - 4) {
        int price = 2 * (n - 2) + 2 * (m - 2) + (k - (n * m - 4));
        if (price < ans) {
            ans = price;
        }
    }
    lbl:
    cout << "Case #" << test << ": " << min(ans, ans2) << endl;
    if (ans != ans2) {
        cerr << test << " " << ans2 << " " << ans << endl;
    }
    return 0;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; ++_) {
        solve(_ + 1);
    }
    return 0;
}
