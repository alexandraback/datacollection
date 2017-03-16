#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define eps 1e-6
int T, N, indeg[1010];
bool vis[1010];
vector <int> adj[1010];
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);
        memset(indeg, 0, sizeof(indeg));
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            int n;
            scanf("%d", &n);
            for (int j = 0; j < n; j++) {
                int v;
                scanf("%d", &v);
                adj[i].push_back(v);
                indeg[v]++;
            }
        }
        bool ok = 0;
        for (int i = 1; i <= N; i++) {
            if (indeg[i] == 0) {
               memset(vis, 0, sizeof(vis));
               queue<int> Q;
               Q.push(i);
               vis[i] = 1;
               while (!Q.empty()) {
                     int now = Q.front();
                     Q.pop();
                     for (int i = 0; i < adj[now].size(); i++) {
                         int next = adj[now][i];
                         if (vis[next]) {
                            ok = 1;
                            break;
                         } else {
                           vis[next] = 1;
                           Q.push(next);
                         }
                     }
                     if (ok) break;
               }
               if (ok) break;
            }
        }
        if (ok)
        printf("Case #%d: Yes\n",cas);
        else printf("Case #%d: No\n",cas);     
    }
}
