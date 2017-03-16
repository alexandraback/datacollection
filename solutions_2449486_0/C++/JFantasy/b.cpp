#include <cstdio>
#include <cstring>

const int maxn = 105;

int a[maxn][maxn], b[maxn][maxn], n, m;

void init() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) scanf("%d", &a[i][j]);
    }
}

bool check(int x, int y, int z) {
    if (z == 0) {
        for (int i = 1; i <= m; ++ i) {
            if (a[x][i] > a[x][y]) return 0;
        }
        return 1;
    } else {
        for (int i = 1; i <= n; ++ i) {
            if (a[i][y] > a[x][y]) return 0;
        }
        return 1;
    }
}

void work() {
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) b[i][j] = check(i, j, 0) + check(i, j, 1) * 2;
    }
    int ans = 1;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            ans &= (b[i][j] > 0);
        }
    }
    puts(ans ? "YES" : "NO");
}

int main() {
    int cas, t = 0;
    scanf("%d", &cas);
    while (cas --) {
        init();
        printf("Case #%d: ", ++ t);
        work();
    }
    return 0;
}
