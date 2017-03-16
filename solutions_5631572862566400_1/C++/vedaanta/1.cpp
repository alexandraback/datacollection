#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define pb push_back
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%I64d",&x)
#define F first
#define S second
#define maxn 1005
#define mod 1000000007
vector<int>g[maxn];
vector<int>rg[maxn];
int ans;
int vis[maxn];
int dep[maxn];
void dfs(int v,int p){
	vis[v]=1;
	dep[v]=1+dep[p];
	for(auto u:g[v]){
		if(vis[u]==0){
			dfs(u,v);
		}
		else{
			int cur=1+dep[v]-dep[u];
			ans=max(ans,cur);
		}
	}
}
int cmax;
void dfs2(int v,int p){
	vis[v]=1;
	dep[v]=1+dep[p];
	cmax=max(cmax,dep[v]);
	for(auto u:rg[v]){
		if(vis[u]==0){
			dfs2(u,v);
		}
	}
}

int mark[maxn];

int main(){

	int t;
	cin>>t;
	rep(tc,t){
		cout<<"Case #"<<tc+1<<": ";
		int n;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			g[i].clear();
			rg[i].clear();
		}
		memset(mark,0,sizeof mark);
		vector<pair<int,int> > v;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			g[i].pb(x);
			rg[x].pb(i);
			mark[i]=x;
			if(mark[x]==i){
				v.pb({i,x});
			}
		}
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof vis);
			memset(dep,0,sizeof dep);
			dfs(i,0);
		}
		int sum=0;
		for(auto i:v){
			int x=i.F;
			int y=i.S;
			
			cmax=0;
			memset(vis,0,sizeof vis);
			vis[y]=1;
			memset(dep,0,sizeof dep);
			dfs2(x,y);
			sum+=cmax;
			cmax=0;
			memset(vis,0,sizeof vis);
			vis[x]=1;
			memset(dep,0,sizeof dep);
			dfs2(y,x);
			sum+=cmax;
		}
		ans=max(ans,sum);
		cout<<ans<<"\n";
	}

	return 0;
}