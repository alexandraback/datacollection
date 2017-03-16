#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=10000;
int all,n,num,tot,x;
int adj[maxn],next[maxn],vt[maxn];
bool pp[maxn];
bool ans;
void connect(int x,int y)
{
	++all;
	adj[all]=y;
	next[all]=vt[x];
	vt[x]=all;
}
void prepare()
{
	all=0;
	memset(vt,0,sizeof(vt));
}
void dfs(int x)
{
	pp[x]=true;
	int l=vt[x];
	while (l!=0)
	{
		if (!pp[adj[l]]) dfs(adj[l]); else ans=true;
		l=next[l];
	}
}
void solve()
{
	ans=false;
	for (int i=1; i<=n; i++)
	{
		memset(pp,0,sizeof(pp));
		dfs(i);
	}

	if (!ans) cout<<" No"<<endl; else cout<<" Yes"<<endl;
}
void init()
{
	cin>>num;
	for (int i=1; i<=num; i++)
	{
		prepare();
		cin>>n;
		for (int j=1; j<=n; j++)
		{
			cin>>tot;
			for (int l=1; l<=tot; l++)
			{
				cin>>x;
				connect(x,j);
			}
		}
		cout<<"Case #"<<i<<":";
		solve();
	}
}
int main()
{
	freopen("AAA.in","r",stdin);
	freopen("AAA.out","w",stdout);
	init();
	return 0;
}
