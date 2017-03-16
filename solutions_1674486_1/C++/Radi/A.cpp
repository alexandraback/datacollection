#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <queue>
#include <cstring>
#include <string>
using namespace std;
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
inline int abs(int a){return a<0?-a:a;}
int visit[1005],True;
vector<int>v[1005];
bool stat;
void dfs(int u){
    int i;
    if(stat) return;
    visit[u]=True;
    for(i=0;i<v[u].size();++i){
        if(visit[v[u][i]]==True) break;
        dfs(v[u][i]);
    }
    if(i<v[u].size()) stat=true;
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t,n,i,m,j;
    scanf("%d",&t);
    for(int cc=1;cc<=t;++cc){
        memset(visit,0,sizeof visit);
        True=0;
        scanf("%d",&n);
        for(i=1;i<=n;++i){
            v[i].clear();
            scanf("%d",&m);
            while(m--){
                scanf("%d",&j);
                v[i].push_back(j);
            }
        }
        for(i=1;i<=n;++i){
            stat=false;
            ++True;
            dfs(i);
            if(stat) break;
        }
        printf("Case #%d: ",cc);
        if(i<=n) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
