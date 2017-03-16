#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int M = 1010;

vector<int> g[M];
bool vis[M];

bool dfs(int v)
{
    int l = g[v].size();
    bool ok = false;
    for(int i = 0; i < l; i++){
        if(!vis[g[v][i]]){
            vis[g[v][i]] = true;
            ok = dfs(g[v][i]);
            if(ok) return ok;
        }else return true;
    }
    return ok;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt.out", "w", stdout);
    int T, N;
    int m, v;
    int con = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i = 1; i <= N; i++){
            scanf("%d", &m);
            g[i].clear();
            for(int j = 1; j <= m; j++){
                scanf("%d", &v);
                g[i].push_back(v);
            }
        }
        bool ok = false;
        for(int i = 1; i <= N; i++){
            memset(vis, false, sizeof(vis));
            ok = dfs(i);
            if(ok) break;
        }
        printf("Case #%d: %s\n", con++, ok ? "Yes" : "No");
    }
    return 0;
}
