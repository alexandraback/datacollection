#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 111, INF = 1111111;

int a[MAXN], f[MAXN][MAXN];

inline void checkmax(int &x, int y) {
    if (y > x)
        x = y;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        memset(f, -1, sizeof f);
        int n;
        scanf("%d%d", &f[0][0], &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        sort(a, a + n + 1);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                if (~f[i][j]) {
                    if (f[i][j] > a[i])
                        checkmax(f[i + 1][j], f[i][j] + a[i]);
                    checkmax(f[i + 1][j + 1], f[i][j]);
                    checkmax(f[i][j + 1], (f[i][j] << 1) - 1);
                    if (f[i][j] > INF)
                        break;
                }
        for (int i = 0; i <= n; ++i)
            if (~f[n + 1][i]) {
                printf("Case #%d: %d\n", cs, i);
                break;
            }
    }
    return 0;
}
