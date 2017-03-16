#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1010
int T,casenum;
int n,m,x;
bool g[N][N],f[N][N];
int d[N],h[N];
bool flag;
void dfs(int v)
{
	h[v]++;
	if (h[v]>=2)
	{
		flag=true;
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (!g[v][i]||f[v][i]) continue;
		f[v][i]=1;
		dfs(i);
		if (flag) return;
	}
}
int main()
{
	freopen("gcj.in","r",stdin);
	freopen("gcj.out","w",stdout);
	cin>>T;
	for (casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<": ";
		memset(g,0,sizeof(g));
		memset(d,0,sizeof(d));
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>m;
			for (int j=1;j<=m;j++)
			{
				cin>>x;
				g[i][x]=1;
				d[x]++;
			}
		}
		flag=false;
		for (int i=1;i<=n;i++)
		{

			if (d[i]==0)
				{
				memset(h,0,sizeof(h));
				memset(f,0,sizeof(f));
				dfs(i);
				}
		}
		if (flag) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
}
