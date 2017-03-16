/*input

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PII pair<ll, ll>
#define f first
#define s second
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define inf LLONG_MAX
#define mod 1000000007
#define MAXN 1005
#define pb(x) push_back(x)

ll t, n, x, u, ans, U, V, cnt;
vector < vector < ll > > g;
vector < vector < ll > > grev;
vector < bool > vis;
vector < vector < ll > > head;
vector < ll > source;
stack < ll > st;
ll src;

void dfs1(ll u)
{
	vis[u]=1;
	ll sz=grev[u].size();
	F(v,0,sz-1)
		if(!vis[grev[u][v]])
			dfs1(grev[u][v]);
	st.push(u);
}

void dfs2(ll u)
{
	vis[u]=1;
	head[src].pb(u);
	ll sz=g[u].size();
	F(v,0,sz-1)
		if(!vis[g[u][v]])
			dfs2(g[u][v]);
}

ll dfs(ll u)
{
	vis[u]=1;
	ll sz=g[u].size(), v, res=0;
	F(i,0,sz-1)
	{
		v=g[u][i];
		if(!vis[v])
			res=max(res,dfs(v));
	}
	return 1+res;
}
int main() 
{
	freopen("Cinp.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	F(count,1,t)
	{
		cnt=ans=0;
		cout<<"Case #"<<count<<": ";
		cin>>n;
		g=vector < vector < ll > >(n+1);
		grev=vector < vector < ll > >(n+1);
		head=vector < vector < ll > >(n+1);
		vis=vector < bool >(n+1,0);
		source.clear();
		F(i,1,n)
		{
			cin>>u;
			g[u].pb(i);
			grev[i].pb(u);
		}
		F(i,1,n)
			if(!vis[i])
				dfs1(i);
		vis=vector < bool >(n+1,0);
		while(!st.empty())
		{
			src=st.top();
			st.pop();
			if(!vis[src])
			{
				dfs2(src);
				source.pb(src);
			}
		}
		vis=vector < bool >(n+1,0);
		ll sz=source.size();
		F(i,0,sz-1)
		{
			src=source[i];
			ll Sz=head[src].size();
			if(Sz==1)
				continue;
			if(Sz>2)
				ans=max(ans,Sz);
			if(Sz==2)
			{
				U=head[src][0];
				V=head[src][1];
				vis[U]=vis[V]=1;
				cnt = cnt + dfs(U)+dfs(V);
			}
		}
		ans=max(ans,cnt);
		cout<<ans<<endl;
	}
	return 0;
}