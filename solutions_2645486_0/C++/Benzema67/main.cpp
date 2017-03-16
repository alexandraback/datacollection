#include <cstdio>
#include <algorithm>
using namespace std;
int E,R,N;
int val[100];
int ans;
void dfs(int now,int nowe,int nowa){
    if(now==N+1) {
        ans=max(ans,nowa);
        return;
    }
    for(int i=0;i<=nowe;i++){
        dfs(now+1,min(nowe-i+R,E),nowa+val[now]*i);
    }
}
int main(){
    int t,T;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("a.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d %d %d",&E,&R,&N);
        for(int i=1;i<=N;i++) scanf("%d",&val[i]);
        ans=0;
        dfs(1,E,0);
        printf("Case #%d: %d\n",t,ans);
    }

    return 0;
}
