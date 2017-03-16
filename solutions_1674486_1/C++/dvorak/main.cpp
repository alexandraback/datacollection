#include <cstdio>
#define MAXN 1005
#include <vector>
using namespace std;
#include <cstring>



vector<int> G[MAXN];
bool vis[MAXN];
int n;

void init() {
    for (int i = 0; i < n; i++)
        G[i].clear();
}

bool dfs(int u) {
    vis[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!vis[v]) {
            if (!dfs(v))
                return false;
        } else
            return false;
    }
    return true;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);        
    int cas = 0;
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int tmp;
            scanf("%d", &tmp);
            for (int j = 0; j < tmp; j++) {
                int t;
                scanf("%d", &t);
                G[i].push_back(t);
            }
        }

        bool can = true;
        for (int i = 1; i <= n; i++) {
            memset(vis, false, sizeof (vis));
            if (!dfs(i)) {
                can = false;
                break;
            }
        }
        if (!can)
            printf("Case #%d: Yes\n", ++cas);
        else
            printf("Case #%d: No\n", ++cas);
    }
}