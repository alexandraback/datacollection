#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

#define FIN freopen("C-small-attempt0.in", "r", stdin)
#define FOUT freopen("C-small-attempt0.out", "w", stdout)

const int N = 1005;

bool g[N][N];
bool gg[N][N];
bool vis[N];
bool ins[N];

int n, ans, V[N], cnt[N];

void dfs(int first, int pre, int u, bool dir, int dep)
{
    //printf("dfs<%d,%d,%d,%d,%d>\n", first,pre,u,dir,dep);
    if(dir) {
        if(g[u][first] || g[u][pre]) {
            //printf("--enter%d\n", dep);
            ans = max(ans, dep);
        }
    }
    else {
        ans = max(ans, dep);
    }
    for(int v = 1;v <= n; ++v) {
        bool e;
        if(dir) {
            e = g[u][v];
        }
        else {
            e = g[v][u];
        }
        if(!vis[v] && e) {
            vis[v] = true;
            dfs(first, u, v, true, dep + 1);
            vis[v] = false;
        }
    }
    if(dir && g[u][pre]) {
        for(int v = 1;v <= n; ++v) {
            bool e = g[v][u];
            if(!vis[v] && e) {
                vis[v] = true;
                dfs(first, u, v, true, dep + 1);
                vis[v] = false;
            }
        }
    }
    return ;
}

int main() {
    FIN;
    FOUT;
    int T, ncase = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        ans = 0;
        memset(g, false, sizeof(g));
        for(int u = 1; u <= n; ++u) {
            int v;
            scanf("%d", &v);
            g[u][v] = true;
        }
        for(int u = 1; u <= n; ++u) {
            memset(vis, false, sizeof(vis));
            vis[u] = true;
            dfs(u, 0, u, true, 1);
        }
        printf("Case #%d: %d\n", ++ncase, ans);
    }
    return 0;
}
