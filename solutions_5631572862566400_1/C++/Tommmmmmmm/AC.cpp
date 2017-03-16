#include<bits/stdc++.h>
using namespace std;
int n;
int a[1020];
vector<int>G[1020];
int dp[1020];
int done[1020];
int dfs(int u,int p){
    if(dp[u]>=0)return dp[u];
    int &t=dp[u];
    t=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==p)continue;
        t=max(t,dfs(v,u));
    }
    t++;
    return t;
}
int main(){
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int _,cas=1;scanf("%d",&_);    
    while(_--){
        printf("Case #%d: ",cas++);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            G[a[i]].push_back(i);
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            memset(done,0,sizeof(done));
            int j=i;
            int cnt=0;
            for(;!done[j];j=a[j]){
                done[j]=1;
                cnt++;
            }
            if(j==i)ans=max(ans,cnt);
        }
        memset(dp,-1,sizeof(dp));
        memset(done,0,sizeof(done));
        int tp=0;
        for(int i=1;i<=n;i++){
            if(done[i])continue;
            if(a[a[i]]==i){
                dfs(a[i],i);
                done[a[i]]=done[i]=1;
                dfs(i,a[i]);
                tp+=dp[a[i]]+dp[i];
            }
        }
        ans=max(ans,tp);
        //printf("%d %d\n",dp[3],dp[4]);
        printf("%d\n",ans);
    }
}
