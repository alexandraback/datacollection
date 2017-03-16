#include <bits/stdc++.h>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define Afridi 0
#define NL printf("\n")
#define debug(x,y) cout << x << " " << y << "\n"
#define Max 5005
#define INF INT_MAX
#define mod 1000000007
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define PI 3.14159265358979323846

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;

using namespace std;

LL bigmod(LL b,int p)
{
    if(p == 0)return 1;
    LL my = bigmod(b,p/2);
    my*=my;
    my%=mod;
    if(p & 1)my*=b,my%=mod;
    return my;
}
int setb(int n,int pos)
{
    return n=n | (1 << pos);
}
int resb(int n,int pos)
{
    return n=n & ~(1 << pos);
}
bool checkb(int n,int pos)
{
    return (bool)(n & (1 << pos));
}

map <string,int> mpa,mpb;
int N,m;
int deg[Max],par[Max];
string ara[Max],bra[Max];
bool graph[Max][Max],taken[Max][Max];
vector <int> g[Max];

int visit[Max],cs;
void dfs(int u,int d,int prev)
{
	//printf("u %d d %d\n",u,d);
	visit[u] = cs;
	int len = sz(g[u]),i;
	Rep(i,len)
	{
		int v = g[u][i];
		if(v == par[u])continue;
		//if(graph[u][v] == 0)continue;
		//graph[u][v] = graph[v][u] = 0;
		//printf("next %d\n",v);
		if(visit[v] != cs)
		{
			par[v] = u;
			dfs(v,d+1,u);
			if(d && d % 2 == 0)
			{
				taken[u][prev] = taken[prev][u] = 1;
				//printf("%d %d yo\n",u,prev);
			}
		}
		else
		{
			if(d && d % 2)
			{
				taken[u][v] = taken[v][u] = 1;
				//printf("%d %d yoho\n",u,v);
			}
		}
	}
}

int lol(int mask,int idx)
{
	int i,f = 0,g = 0;
	Rep(i,N)
	{
		if(checkb(mask,i))
		{
			if(ara[i+1] == ara[idx+1])f = 1;
			if(bra[i+1] == bra[idx+1])g = 1;
		}
	}
	if(f && g)return 1;
	return 0;
}

int dp[ (1<<16) + 10 ],ff[ (1<<16) + 10 ],CS;
int go(int pos,int mask)
{
	if(pos == N)return 0;

	if(ff[mask] == CS)return dp[mask];

	int i,ret = 0;
	Rep(i,N)
	{
		if(checkb(mask,i) == 0)
		{
			int val = lol(mask,i);
			int my = val + go(pos+1,setb(mask,i));
			ret = max(ret,my);
		}
	}

	ff[mask] = CS;
	return dp[mask] = ret;
}

int main()
{
	//FI;
	freopen("C-small-attempt2.in","r",stdin);
	freopen("outCsmall.txt","w",stdout);
	int T,t,i,j;
	si(T);
	rep(t,T)
	{
		si(N);
		rep(i,N)cin >> ara[i] >> bra[i];

		mpa.clear();
		m = 0;
		rep(i,N)
		{
			if(mpa.find( ara[i] ) == mpa.end())
			{
				mpa[ ara[i] ] = ++m;
			}
		}
		int d = m;

		mpb.clear();
		rep(i,N)
		{
			if(mpb.find( bra[i] ) == mpb.end())
			{
				mpb[ bra[i] ] = ++m;
			}
		}

		mem(graph,0);
		mem(taken,0);
		mem(par,0);
		rep(i,m)g[i].clear(),deg[i] = 0;
		rep(i,N)
		{
			int x = mpa[ ara[i] ];
			int y = mpb[ bra[i] ];
			graph[x][y] = 1;
			graph[y][x] = 1;
			g[x].pb(y);
			g[y].pb(x);
			deg[x]++;
			deg[y]++;
			//printf("%d - %d\n",x,y);
		}

		/*int cnt = 0;
		for(i=1;i<=d;i++)
		{
			for(j=d+1;j<=m;j++)
			{
				if(graph[i][j] == 0)continue;
				//printf("deg %d = %d and deg %d = %d\n",i,deg[i],j-d,deg[j]);
				if(deg[i] > 1 && deg[j] > 1)
				{
					cnt++;
					deg[i]--;
					deg[j]--;
				}
			}
		}*/

		int C = 0;
		cs++;
		rep(i,m)
		{
			//cs++;
			dfs(i,0,0);
		}
		rep(i,m)
		{
			rep(j,m)
			{
				if(i == j)continue;
				if(taken[i][j])C++;
			}
		}

		//printf("Case #%d: %d\n",t,cnt);
		//printf("Case #%d: %d\n",t,C/2);
		CS++;
		int ret = go(0,0);
		printf("Case #%d: %d\n",t,ret);
	}
	return 0;
}
