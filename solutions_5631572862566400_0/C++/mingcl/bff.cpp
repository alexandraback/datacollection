
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define INVALID (2)
#define RING (3)

using namespace std ; 

typedef long long ll ; 

int to[1111] ; 
int totVis[1111] ; 
int vis[1111] ;
int curSize ; 

int findRing(int sp){
    int cur = sp ; 
    int cnt = 1 ; 
    vis[cur] = true ; 
    while(true){
        cur = to[cur] ; 
        if(totVis[cur])
            //fprintf(stderr, "SOMETHING WRONG RING (sp = %d)\n", sp) ; 
            return INVALID ; 
        if(vis[cur]){
            if(cur == sp){
                if(cnt > 2){
                    curSize = cnt ; 
                    return RING ;
                }
                return INVALID ; 
            }
            return INVALID ; 
        }
        vis[cur] = true ; 
        cnt++ ; 
    }
}

int N ; 

int dfs(int now, int forbid){
    totVis[now] = true ; 
    int rtn = 0 ; 
    for(int i = 1 ; i <= N ; i++) if(i != forbid && to[i] == now){
        if(totVis[i])
            fprintf(stderr, "SOMETHING WRONG DFS\n") ; 
        rtn = max(rtn, dfs(i, -1)) ; 
    }
    return rtn+1 ; 
}

void sol(){
    scanf("%d", &N) ; 
    memset(to, 0, sizeof(to)) ; 
    memset(totVis, 0, sizeof(totVis)) ; 
    for(int i = 1 ; i <= N ; i++)
        scanf("%d", to+i) ; 
    int ans = 0 ; 
    for(int i = 1 ; i <= N ; i++){
        if(totVis[i])
            continue ; 
        memset(vis, 0, sizeof(vis)) ; 
        int res = findRing(i) ; 
        if(res == INVALID)
            continue ; 
        if(res == RING){
            ans = max(ans, curSize) ; 
            for(int j = 1 ; j <= N ; j++)
                totVis[j] |= vis[j] ; 
        }
    }
    int sum = 0 ; 
    for(int i = 1 ; i <= N ; i++) if(to[to[i]] == i && i < to[i]){
        int a = i ; 
        int b = to[i] ; 
        sum += dfs(a, b)+dfs(b, a) ; 
    }
    ans = max(ans, sum) ; 
    printf("%d\n", ans) ; 
}

int main()
{
    int T ; 
    scanf("%d", &T) ; 
    for(int time = 1 ; time <= T ; time++){
        fprintf(stderr, "solving case (%d / %d)...\n", time, T) ; 
        printf("Case #%d: ", time) ; 
        sol() ; 
    }
    return 0 ; 
}


