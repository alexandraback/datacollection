#include <bits/stdc++.h>
using LL = long long ;

const int N = 6;
int n;
LL m;
bool graph[N][N];
LL dp[N];

bool search(int u) {
    if (u == n) {
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for (int u = 0; u < n; ++ u) {
            for (int v = u + 1; v < n; ++ v) {
                if (graph[u][v]) {
                    dp[v] += dp[u];
                }
            }
        }
        if (dp[n - 1] == m) {
            puts("POSSIBLE");
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < n; ++ j) {
                    printf("%d",graph[i][j]);
                }
                puts("");
            }
            return true;
        }
        return false;
    }

    for (int mask = 0; mask < 1 << u; ++ mask) {
        for (int v = 0; v < u; ++ v) {
            graph[v][u] = mask >> v & 1;
        }
        if (search(u + 1)) return true;
    }
    return false;
}

void work() {
    if (!search(0)) {
        puts("IMPOSSIBLE");
    }
}

int main() {
    freopen("small.in","r",stdin);
    freopen("small.out","w",stdout);
    int cas,ca = 0;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d",&n);
        scanf("%I64d",&m);
        printf("Case #%d: ",++ca);
        work();
    }
}
