#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 15;

int f[maxn][maxn], v[maxn], e, r, n; 

void init() {
    scanf("%d%d%d", &e, &r, &n);
    for (int i = 1; i <= n; ++ i) scanf("%d", &v[i]);
}

void work() {
    memset(f, -1, sizeof(f));
    f[0][e] = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j <= e; ++ j) {
            if (f[i - 1][j] == -1) continue;
            for (int h = 0; h <= j; ++ h) {
                f[i][min(j - h + r, e)] = max(f[i][min(j - h + r, e)], f[i - 1][j] + h * v[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= e; ++ i) ans = max(ans, f[n][i]);
    printf("%d\n", ans);
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
