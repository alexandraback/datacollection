#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

vector<int> road[1001];
int num[1001], t[1001];

bool bfs(int start){
    
    queue<int> que;
    while(!que.empty()) que.pop();
    que.push(start);
    memset(t,0,sizeof(t));
    int now, tmp;
    
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(int i=0; i<num[now]; ++i){
            ++t[road[now][i]];
            que.push(road[now][i]);
        }
    }
    int i;
    for(i=1; i<1001; ++i)
    if( t[i]>=2 )   break;
    if( i<1001 )    return true;
    else            return false;
}


int main(void){
    
    freopen("AS.txt", "r", stdin);
    freopen("Aout.txt", "w", stdout);
    
    int cas, c=0, n;
    
    scanf("%d", &cas);
    while(cas--){
        
        scanf("%d", &n);
        for(int i=1; i<=n; ++i){
            road[i].clear();
            int tmp;
            scanf("%d", &num[i]);
            for(int j=0; j<num[i]; ++j){
                scanf("%d", &tmp);
                road[i].push_back(tmp);
            }
        }
        
        int i;
        for(i=1; i<=n; ++i)
        if( bfs(i) )    break;
        
        if( i<=n )  printf("Case #%d: Yes\n", ++c);
        else        printf("Case #%d: No\n", ++c);
        
    }
    
    return 0;
}
