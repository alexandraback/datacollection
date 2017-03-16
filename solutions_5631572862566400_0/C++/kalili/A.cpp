#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<string>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<iomanip>
#include<climits>
#include<fstream>
using namespace std;
int F[1010];
int ans ;
int n;
bool vis[1010];
void dfs(int root,int pre,int now,int cnt){
    if(F[now] == pre || F[now] == root){
        ans = max(ans,cnt);
    }
    if(F[now] == pre){
        for(int i=1;i<=n;++i){
            if(!vis[i])
            {
                vis[i] = true;
                dfs(root,now,i,cnt+1);
                vis[i] = false;
            }
        }
    }
    if(!vis[F[now]]){
        vis[F[now]] = true;
        dfs(root,now,F[now],cnt+1);
        vis[F[now]] = false;
    } 
}
int main(){
	freopen("C.in","r",stdin);
    freopen("A.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        printf("Case #%d: ",ca);
        scanf("%d",&n);
        memset(F,0,sizeof F);
        for(int i=1;i<=n;++i){
            scanf("%d",F+i);
        }
        ans = 1;
        for(int i=1;i<=n;++i){
            memset(vis,false,sizeof vis);
            vis[i] = true;
            dfs(i,-1,i,1);
            vis[i] = false;
        }
        printf("%d\n",ans);
    }
    return 0;
}


