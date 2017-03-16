#include <bits/stdc++.h>

using LL = long long ;
const int N = 50;
int n;
LL m;
bool graph[N][N];

void work() {
    memset(graph,0,sizeof(graph));
    for (int i = 0; i < n - 1; ++ i) {
        for (int j = i + 1; j < n - 1; ++ j) {
            graph[i][j] = true;
        }
    }
    for (int link = 0; link < 2; ++ link) {
        LL left = m - link;
        graph[0][n - 1] = link;

        for (int v = n - 2; v > 0; -- v) {
            if (left >> v - 1 & 1) {
                graph[v][n - 1] = true;
                left ^= 1 << v - 1;
            } else {
                graph[v][n - 1] = false;
            }
        }
        if (left) continue;
        puts("POSSIBLE");
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                printf("%d",graph[i][j]);
            }
            puts("");
        }
        return ;
    }
    puts("IMPOSSIBLE");
}

int main() {
    freopen("large.in","r",stdin);
    freopen("large.out","w",stdout);
    int cas,ca = 0;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d%I64d",&n,&m);
        printf("Case #%d: ",++ca);
        work();
    }
}
