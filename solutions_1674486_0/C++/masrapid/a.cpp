
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define rep(i,s,n) for( int i = s; i < n; ++i)

#define MAX 1001

int reachable[MAX][MAX];
vector<int> adj[MAX], par[MAX];

bool testreachable(int u, int v){
    if(reachable[u][v] != -1) return reachable[u][v];
    if(u == v)
        return reachable[u][v] = 1;
    if(par[v].size() <= 0)
        return reachable[u][v] = 0;
    for(int i = 0; i < par[v].size(); i++)
        if(par[v][i] == u)
            return reachable[u][v] = 1;
    for(int i = 0; i < par[v].size(); i++)
        if(testreachable(u, par[v][i]))
            return reachable[u][v] = 1;
    return reachable[u][v] = 0;
}
int main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int n, t, kase = 0, v, ad;
    scanf("%d", &t);
    while(t--){
        rep(i, 0, MAX){
            adj[i].clear();
            par[i].clear();
        }
        memset(reachable, -1, sizeof(reachable));
        scanf("%d", &n);
        rep(u, 1, n+1){
            scanf("%d", &ad);
            rep(i, 0, ad){
                scanf("%d", &v);
                adj[u].push_back(v);
                par[v].push_back(u);
            }
        }
        printf("Case #%d: ", ++kase);
        bool found = false;
        rep(u, 1, n+1){
            if(found) break;
            rep(v, 1, n+1){
                if(found) break;
                if(u != v && testreachable(u, v)){
                    int cnt = 0;
                    for(int i = 0; i < adj[u].size(); i++){
                        if(testreachable(adj[u][i], v))
                            ++cnt;
                        if(cnt >= 2){
                            printf("Yes\n");
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        if(!found)
            printf("No\n");
    }

    return 0;
}
