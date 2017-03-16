#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <numeric>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <functional>
#include <queue>
#include <stack>
#include <list>
using namespace std;

const int MAX_N = 1111;
int T,N;
vector<int> RG[MAX_N];
int F[MAX_N];
int max_circle = 0;
int dfn[MAX_N];
int maxlinkcnt = 0;
bool vis[MAX_N];

void clear() {
    max_circle = 0;
    for(int i = 0 ; i < MAX_N;i ++ ) {
        RG[i].clear();
    }
    memset(vis,0,sizeof(vis));
}

void dfs(int u,int cnt) {
    dfn[u] = cnt;
    for(int i = 0 ; i < RG[u].size();i++ ) {
        int v = RG[u][i];
        if(!dfn[v]) {
            dfs(v,cnt+1);
        } else {
            max_circle = max(max_circle,cnt - dfn[v] + 1);
        }
    }
    dfn[u] = 0;
}

void maxlink(int u,int fa,int cnt,int ignore) {
    maxlinkcnt = max(maxlinkcnt,cnt);
    for(int i = 0 ; i < RG[u].size(); i++ ) {
        int v = RG[u][i];
        if( v!=fa&& v!=ignore ) {
            maxlink(v,u,cnt+1,ignore);
        }
    }
}

int main() {
    scanf("%d",&T);
    int cases = 1;
    while( T-- ) {
        clear();
        scanf("%d",&N);
        for(int i =1 ; i<= N; i++ ) {
            scanf("%d",&F[i]);
            RG[F[i]].push_back(i);
        }
        for(int i = 1;  i <= N; i++ ) {
            dfs(i,1);
        }
        if( max_circle == N ) {
            printf("Case #%d: %d\n",cases++,N);
            continue;
        }
        for(int i = 1; i <= N ;i++ ) {
            if( !vis[i] && i == F[F[i]] ) {
                //printf("i = %d, F[F[i]] = %d\n",i,F[F[i]]);
                vis[i] = vis[F[i]] = true;
                maxlinkcnt = 0;
                maxlink(i,-1,1,F[i]);
                int t = 0;
                t+=maxlinkcnt;
                maxlinkcnt = 0;
                maxlink(F[i],-1,1,i);
                t+=maxlinkcnt;
                max_circle = max(max_circle,t);
            }
        }
        printf("Case #%d: %d\n",cases++,max_circle);
    }
    return 0;
}