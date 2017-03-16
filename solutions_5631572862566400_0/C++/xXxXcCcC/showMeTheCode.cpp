#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

int F[1005];
bool vis[1005];
int num[1005];
vector<int>G[1005];
int ans;

int dfs(int u,int dep){
    vis[u]=true;
    int maxdep=dep;
    for (int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if (vis[v]) continue;
        maxdep = max(maxdep,dfs(v,dep+1));
    }
    return maxdep;
}

void findcir(int u,int no){
    num[u]=no;
    int v=F[u];
    if (!vis[v]){
        if (num[v]){
            ans=max(ans,no-num[v]+1);
        }
        else {
            findcir(v,no+1);
        }
    }
    vis[u]=true;
}

void solve(){
    int n,x;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        G[i].clear();
    }
    for (int i=1;i<=n;i++){
        scanf("%d",F+i);
        G[F[i]].push_back(i);
    }
    memset(vis,0,sizeof(vis));
    ans=0;
    for (int i=1;i<=n;i++){
        if (F[F[i]]==i){
            if (vis[i]) continue;
            //printf("i=%d\n",i);
           // printf("F[i]=%d\n",F[i]);
            vis[i]=true;
            vis[F[i]]=true;
            ans+=dfs(i,1);
            ans+=dfs(F[i],1);
        }
    }
    //printf("ans=%d\n",ans);
    memset(num,0,sizeof(num));
    for (int i=1;i<=n;i++){
        if (!vis[i]) findcir(i,1);
    }
    printf("%d\n",ans);
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++){
        printf("Case #%d: ",kase);
        solve();
    }
    return 0;
}
