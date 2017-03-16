#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1100;
int f[N], vis[N], n;
vector <int> g[N];
int dfs(int u, int v){
    int res = 0;
    //printf("%d\n", u);
    for (int i = 0; i < g[u].size(); ++ i){
        if (g[u][i] == v) continue;
        res = max(res, dfs(g[u][i], v));
    }
    return res + 1;
}
int main(){
    //freopen("in2.txt", "r", stdin);
    freopen("C-small-attempt3.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t; scanf("%d", &t);
    while (t --){
        static int ca = 0;
        printf("Case #%d: ", ++ ca);
        scanf("%d", &n);
        for (int i = 1; i <= n; ++ i) g[i].clear();
        for (int i = 1; i <= n; ++ i){
            scanf("%d", &f[i]);
            g[f[i]].push_back(i);
        }
        int ans = 0;
        int res = 0;
        for (int i = 1; i <= n; ++ i){
            memset(vis, 0, sizeof vis);
            int nx = 1, x = i;
            do{
                vis[x] = nx;
                x = f[x];
                nx ++;
            }while (vis[x] == 0);
            ans = max(nx - vis[x], ans);
            if (f[f[i]] == i && i <= f[i]){
                res += dfs(i, f[i]) + dfs(f[i], i);
            }
        }
        ans = max(ans, res);
        printf("%d\n", ans);
    }
}
