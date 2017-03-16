#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int id,n,m,vis[N],pri[N],SCC[N],vis2[N];
vector<int> adj1[N],adj2[N],S[N];
void DFS(int pos){
    vis[pos]=1;
    for(int i=0;i<adj1[pos].size();i++)if(!vis[adj1[pos][i]])
        DFS(adj1[pos][i]);
    pri[id++]=pos;
}
void DFS2(int pos,int parent){
    vis[pos]=1,SCC[pos]=parent;
    for(int i=0;i<adj2[pos].size();i++)if(!vis[adj2[pos][i]])
        DFS2(adj2[pos][i],parent);
}
int cal(int pos,int t){
    int ret=0;
    vis2[pos]=1;
    for(int i=0;i<adj1[pos].size();i++)
        if(!vis2[adj1[pos][i]]&&adj1[pos][i]!=t)ret=max(ret,cal(adj1[pos][i],t));
    return ret+1;
}
main(){
    freopen("C-large.in","r",stdin);
    freopen("outC","w",stdout);
    int T,c=1;
    scanf("%d",&T);
    while(T--){
        int i,j,ans=0;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis)),id=0;
        memset(vis2,0,sizeof(vis2));
        for(i=0;i<=n;i++)adj1[i].clear(),adj2[i].clear(),S[i].clear();
        for(i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            adj1[x].push_back(i);
            adj2[i].push_back(x);
        }
        for(i=1;i<=n;i++)if(!vis[i])DFS(i);
        memset(vis,0,sizeof(vis)),id=0;
        for(i=n-1;i>=0;i--)if(!vis[pri[i]])DFS2(pri[i],id++);
        for(i=1;i<=n;i++)S[SCC[i]].push_back(i);
        for(i=0;i<id;i++){
            ans=max(ans,(int)S[i].size());
            if(S[i].size()>2)
                for(j=0;j<S[i].size();j++)vis2[S[i][j]]=1;
        }
        int cnt=0;
        for(i=0;i<id;i++)
            if(S[i].size()==2){
                int a=cal(S[i][0],S[i][1]),b=cal(S[i][1],S[i][0]);
                cnt+=a+b;
            }
        ans=max(ans,cnt);
        printf("Case #%d: %d\n",c++,ans);
    }
    return 0;
}
