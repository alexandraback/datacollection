#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define pb push_back
using namespace std;

vector<ll> adj[1001];
ll f[1001],g[1001];
bool vst[1001];

void addedge(ll x,ll y)
{
	adj[x].pb(y);
	adj[y].pb(x);
}

void DFS(ll v)
{
    vst[v]=true;
	f[v]=1;
	g[v]=1;
	vector<ll> vv;
    for(ll i=0;i<adj[v].size();++i)
	{
		if(!vst[adj[v][i]])
		{
			DFS(adj[v][i]);
			vv.pb(f[adj[v][i]]);
		}
	}
	sort(vv.begin(),vv.end());
	if(vv.size()>=1)
	f[v]+=vv[vv.size()-1];
	if(vv.size()>=2)
	g[v]=g[v]+vv[vv.size()-1]+vv[vv.size()-2];
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out7.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	for(ll x=1;x<=t;++x)
	{
		ll n;
		scanf("%lld",&n);
		for(ll i=1;i<=n;++i)
		{
			ll tt;
			cin>>tt;
			addedge(tt,i);
		}
		for(ll i=0;i<=n;++i)
		vst[i]=false;
	//	cout<<"x"<<endl;
		for(ll i=1;i<=n;++i)
		{
			if(!vst[i])
			DFS(i);
	//		cout<<"d"<<endl;
		}
		ll max=0;
		for(ll i=1;i<=n;++i)
		{
			if(f[i]>max)
			max=f[i];
			if(g[i]>max)
			max=g[i];
		}
	//	cout<<"x"<<endl;
		printf("Case #%lld: %lld\n",x,max);
		for(ll i=0;i<=n;++i)
		adj[i].clear();
	}
	return 0;
}
