#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
ll f[10020],Lc[10020],Rc[10020],sz[10020],v[10020],stk[10020];
ll vR,vE;
void dfs(int v)
{
	if(!v)
		return;
	dfs(Lc[v]);
	dfs(Rc[v]);
	sz[v]=1+sz[Lc[v]]+sz[Rc[v]];
}
pair<ll,ll>F(int u,ll e)
{
	if(!u)
		return make_pair(e,0);
	auto L=F(Lc[u],e);
	ll x=L.X+(1ll+sz[Rc[u]])*vR;
	ll y=min(max(x-vE,0ll),L.X);
	auto R=F(Rc[u],L.X-y+vR);
	return make_pair(R.X,L.Y+y*v[u]+R.Y);
}

ll G(int u,ll e)
{
	if(!u)
		return 0;
	auto L=F(Lc[u],e);
	auto R=G(Rc[u],vR);
	return L.Y+L.X*v[u]+R;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T,n;
	cin>>T;
	for(int tc=1;tc<=T;tc++)
	{
		cin>>vE>>vR>>n;
		memset(f,0,sizeof f);
		int ss=0,rt=0;
		for(int i=1;i<=n;i++)
		{
			int lx=0;
			cin >> v[i];
			for(;ss&&v[stk[ss]]<=v[i];--ss)
				lx=stk[ss];
			if(lx)
				f[lx]=i;
			f[i]=stk[ss];
			stk[++ss]=i;
		}
		memset(Lc,0,sizeof Lc);
		memset(Rc,0,sizeof Rc);
		for(int i=1;i<=n;i++)
		{
			if(f[i]>i)
				Lc[f[i]]=i;
			else
				Rc[f[i]]=i;
			if(!f[i])
				rt=i;
		}
		dfs(rt);
		cout << "Case #" << tc << ": " << G(rt,vE) << endl;
	}
	return 0; 
}
