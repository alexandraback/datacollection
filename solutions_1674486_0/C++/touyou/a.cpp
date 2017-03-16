#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int t, n;
vector<int> g[1000];
bool vis[1000];
bool dfs(int id) {
    if (vis[id]) return true;
    vis[id]=true;
    bool flag=false;
    for (int i=0; i<g[id].size(); i++) {
        flag=dfs(g[id][i]);
        if (flag) return true;
    }
    return false;
}
int main() {
    scanf("%d",&t);
    for (int ix=1; ix<=t; ix++) {
        scanf("%d",&n);
        for (int i=0; i<1000; i++) g[i].clear();
        for (int i=0; i<n; i++) {
            int m; scanf("%d",&m);
            for (int j=0; j<m; j++) {
                int c; scanf("%d",&c);
                g[i].push_back(c-1);
            }
        }
        bool flag=false;
        for (int i=0; i<n; i++) {
            if (g[i].size()==0) continue;
            memset(vis, 0, sizeof(vis));
            flag=dfs(i);
            if (flag) break;
        }
        printf("Case #%d: ",ix);
        if (flag) puts("Yes");
        else puts("No");
    }
}
