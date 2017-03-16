#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> g[1010];
int vis[1010];
int dfs(int u) {
    vis[u] = 1;
    int ans = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!vis[v]) {
            ans = max(ans, dfs(v));
        }
    }
    return ans + 1;
}
int fa[1010];
int main() {
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", ca++);
        int n;
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
            g[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            g[x].push_back(i);
            fa[i] = x;
        }
        int ans = 0, res = 0, tmp = 0;
        for (int i = 1; i <= n; i++) {
            if (fa[fa[i]] == i && fa[i] >= i) {
                memset(vis, 0, sizeof(vis));
                vis[i] = vis[fa[i]] = 1;
                res += dfs(i);
                res += dfs(fa[i]);
            }
        }
        for (int i = 1; i <= n; i++) {
            tmp = 0;
            memset(vis, 0, sizeof(vis));
            int now = i;
            while (vis[now] == 0){ 
                vis[now] = ++tmp;
                now = fa[now];
            }
            ans = max(ans, tmp - vis[now] + 1);
        }
        printf("%d\n", max(ans, res));
    }
}
