#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

using namespace std;
const int maxn = 1300;
const int inf = 1e9+7;

int n;
int f[maxn];

int dis[maxn][maxn];
void init(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) 
            dis[i][j] = inf;

    static bool vis[maxn];
    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        int x = i , v = 0;
        while ( !vis[x] ){
            dis[i][x] = v; 
            vis[x] = true; 
            v++; x = f[x];
        }
    }
}

int circle(){
    int res = 0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if ( dis[i][j]<inf && dis[j][i]<inf )
                res = max( res, dis[i][j]+dis[j][i] );
    return res;
}

vector<int> e[maxn];
int gao(int s1, int s2){
    static int dis[maxn];
    static queue<int> que;

    for(int i=1;i<=n;i++) dis[i] = inf;
    while ( !que.empty() ) que.pop();
    dis[s1] = 0; que.push(s1); 
    while ( !que.empty() ){
        int x = que.front(); que.pop();
        

        for(int i=0;i<e[x].size();i++){
            int to = e[x][i];
            if ( to==s2 ) continue;
            if ( dis[to]==inf ) {
                que.push( to );
                dis[to] = dis[x] + 1;
            }
        }
    }
    int max1 = 0;
    for(int i=1;i<=n;i++) 
        if ( dis[i]<inf ) max1 = max(max1, dis[i]);

    for(int i=1;i<=n;i++) dis[i] = inf;
    while ( !que.empty() ) que.pop();
    dis[s2] = 0; que.push(s2); 
    while ( !que.empty() ){
        int x = que.front(); que.pop();
        if ( x==s1 ) continue;

        for(int i=0;i<e[x].size();i++){
            int to = e[x][i];
            if ( to==s1 ) continue;
            if ( dis[to]==inf ) {
                que.push( to );
                dis[to] = dis[x] + 1;
            }
        }
    }
    int max2 = 0;
    for(int i=1;i<=n;i++) 
        if ( dis[i]<inf ) max2 = max(max2, dis[i]);

    //cout<< max1 << ' ' <<max2 <<endl;
    return 2 + max1 + max2;
}
int bi(){
    static bool vis[maxn];
    memset(vis,false,sizeof(vis));

    int res = 0;
    for(int i=1;i<=n;i++){
        if ( vis[i] ) continue;
        if ( f[f[i]]==i ){
            vis[i] = vis[f[i]] = true;
            int v = gao(i, f[i]);
            res += v ;
        }
    }
    return res;
}

int main(){
    int t; scanf("%d", &t);
    for(int it=1;it<=t;it++){
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d", &f[i]); 
        }

        init();
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<=n;i++)
            e[ f[i] ].push_back( i );

        printf("Case #%d: %d\n", it, max(circle(), bi()) );
    }

    return 0;
}

