#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
vector<int>g[1500],rg[1500]; int ans,visited[1500],depth[1500]; void go(int v,int p){visited[v]=1; depth[v]=1+depth[p]; for(int i=0;i<g[v].size();i++){int u=g[v][i]; if(visited[u]==0){go(u,v); } else{int cur=1+depth[v]-depth[u]; ans=max(ans,cur); } } } int cmax;
void go2(int v,int p){visited[v]=1; depth[v]=1+depth[p]; cmax=max(cmax,depth[v]); for(int i=0;i<rg[v].size();i++){int u=rg[v][i]; if(visited[u]==0){go2(u,v); } } }int mark[1500];int main(){int t; cin>>t; rep(tc,t){cout<<"Case #"<<tc+1<<": "; int n; ans=0; cin>>n; for(int i=1;i<=n;i++){g[i].clear(); rg[i].clear(); } memset(mark,0,sizeof mark); vector<pair<int,int> > v; for(int i=1;i<=n;i++){int x; cin>>x; g[i].pb(x); rg[x].pb(i); mark[i]=x; if(mark[x]==i){v.pb({i,x}); } } for(int i=1;i<=n;i++){rep(i,n+1)visited[i]=0; rep(i,n+1)depth[i]=0; go(i,0); } int sum=0; for(auto i:v){int x=i.F; int y=i.S; cmax=0; rep(i,n+1)visited[i]=0; visited[y]=1; rep(i,n+1)depth[i]=0; go2(x,y); sum+=cmax; cmax=0; rep(i,n+1)visited[i]=0; visited[x]=1; rep(i,n+1)depth[i]=0; go2(y,x); sum+=cmax; } ans=max(ans,sum); cout<<ans<<"\n"; } return 0; }