#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 55;
long long m, mm;
int T, b, bb;
int g[N][N];

int vis[N];
int cao;

void dfs(int u) {
    if (u == bb) {
        cao++;
        return;
    }
    vis[u] = 1;
    for (int i = 1; i <= bb; i++) {
        if (g[u][i] && !vis[i]) {
            dfs(i);
        }
    }
    vis[u] = 0;
}

bool judge() {
    cao = 0;
    dfs(1);
    return cao == mm;
}

int main() {
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("B-small-attempt2.out", "w", stdout);
    int cas = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lld", &b, &m);
        bb = b, mm = m;
        if (b == 2) {
            printf("Case #%d: ", ++cas);
            if (m != 1) printf("IMPOSSIBLE\n");
            else {
                printf("POSSIBLE\n");
                printf("01\n00\n");
            }
            continue;
        }
        int s = 1, t = b;
        b -= 2;
        long long sum = 0, sb = 1;
        for (int i = 1; i <= b; i++) {
            sum += sb;
            if (sum + 1 >= m) {
                b = i + 1;
                break;
            }
            sb *= 2;
        }
        printf("Case #%d: ", ++cas);
        memset(g, 0, sizeof(g));
        for (int i = 2; i <= b; i++) {
            g[s][i] = g[i][t] = 1;
            for (int j = i + 1; j <= b; j++)
                g[i][j] = 1;
        }
        if (sum < m) {
            if (sum + 1 == m) {
                g[s][t] = 1;
                printf("POSSIBLE\n");
//                if (!judge()) printf("%d %lld %d!!\n", bb, mm, cao);
                for (int i = 1; i <= t; i++) {
                    for (int j = 1; j <= t; j++) {
                        printf("%d", g[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("IMPOSSIBLE\n");
            }
        }
        else {
            printf("POSSIBLE\n");
            sum -= m;
            for (int i = 0; ; i++) {
                if (sum&(1LL<<i)) {
                    g[i + 2][t] = 0;
                    sum -= (1LL<<i);
                }
                if (sum == 0) break;
            }
           // if (!judge()) printf("%d %lld!!\n", bb, mm);
            for (int i = 1; i <= t; i++) {
                for (int j = 1; j <= t; j++) {
                    printf("%d", g[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
