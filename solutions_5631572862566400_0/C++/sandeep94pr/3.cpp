#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define _ ios::sync_with_stdio(false);
#define mem(x,a) memset(x,(a),(int)(sizeof(x)))
#define pii pair<int,int>
#define fr(i,a,n) for(int i=(a);i<=(n);i++)
#define frd(i,a,n) for(int i=(a);i>=(n);i--)
#define nl printf("\n")
#define pb push_back
#define mp make_pair 
#define F first 
#define S second
#define V vector
ll mod=1e9+7;
V<int> st;
V<int> scc[1005];
V<int> g[1005];
V<int> ts;
int counter,dfsnum[1005],vis[1005],dfslow[1005],SCC;
void bridges(int u){
    dfsnum[u]=dfslow[u]= ++counter;
    int szz=g[u].size();
    st.pb(u);
    vis[u]=1;
    for(int i=0;i<szz;i++)
    {
    	int v=g[u][i];
    	if(dfsnum[v]==0)
    		bridges(v);
    	if(vis[v])	
    	 dfslow[u]=min(dfslow[u],dfslow[v]);
    }
    if(dfslow[u] == dfsnum[u])
    {
    	++SCC;
    	while(1)
    	{
    		int v=st.back();
    		st.pop_back();
    		vis[v]=0;
    		scc[SCC].pb(v);
    		//cout<<v<<" ";
    		//mark[v]=1;
    		if(u==v)break;
    	}
   // cout<<"\n";
    }
}
void dfstopo(int u){
    vis[u] = 1;
    
    for(int i=0;i<g[u].size();i++)
    {
        if(vis[g[u][i]] == 0)
        {
            vis[g[u][i]] = 1;
            dfstopo(g[u][i]);
        }
    }
    ts.pb(u);
    return ;
}
map<int,int> mark,save;
int dfslen[1005];
void dfs(int u,int d)
{
	vis[u]=1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(mark[v])
			{
				int next=save[v];
				if(!vis[next])dfslen[v]=max(dfslen[v],d);
			}
		if(vis[v])continue;
		dfs(v,d+1);
	}
}
int main() {_
	int t;
	cin>>t;
	fr(z,1,t)
	{
		int n,x;cin>>n;
		fr(i,1,n)
		{
			cin>>x;
			g[i].pb(x);
		}
		for(int i=1;i<=n;i++)if(!dfsnum[i])bridges(i);
		mem(vis,0);
		int ans=0;
		for(int i=1;i<=SCC;i++)
		{
			if(scc[i].size()>2)ans=max(ans,(int)scc[i].size());
			else if(scc[i].size()==2)
			{
				for(auto x:scc[i])mark[x]=1;
				int a=scc[i][0],b=scc[i][1];
				//cout<<a<<" "<<b<<endl;
				save[a]=b;
				save[b]=a;
			}
		}
		//for(auto x:save)cout<<x.F<<" "<<x.S<<endl;
		for(int i=1;i<=n;i++)
		{
			if(mark[i])continue;
			mem(vis,0);
			dfs(i,1);
		}
		//fr(i,1,n)cout<<dfslen[i]<<" ";nl;
		for(int i=1;i<=SCC;i++)
		{
			if(scc[i].size()==2)
			{
				int a=scc[i][0],b=scc[i][1];
				int val=dfslen[a]+dfslen[b]+2;
				ans=max(ans,val);
				//cout<<val<<endl;
			}
		}
		mem(vis,0);
		V<pii> fin;
		for(int i=1;i<=n;i++)
			{
				if(vis[i])continue;
				vis[i]=1;
				if(mark[i])fin.pb( mp (max(dfslen[i],dfslen[mark[i]]),i));
			}
		sort(fin.begin(),fin.end(),greater<pair<int,int> >());
		if(fin.size()>1)
		{
			int a=fin[0].F,b=fin[1].F;
			int cans= a+b+2;
			for(int i=1;i<(fin.size()-1);i++)cans+=2;
				ans=max(ans,cans);
		}
		cout<<"Case #"<<z<<": ";
		cout<<ans<<endl;
		fr(i,0,n)g[i].clear(),vis[i]=0,dfsnum[i]=0,dfslow[i]=0;
		save.clear();mark.clear();ts.clear();
		fr(i,0,SCC)scc[i].clear();
		SCC=0;counter=0;
		st.clear();
	}
	return 0;
}