#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1000
int T,casenum;
int n,m,x;
bool g[N][N],f[N][N];
int c[N][N];

int main()
{
	freopen("gcj.in","r",stdin);
	freopen("gcj.out","w",stdout);
	cin>>T;
	for (casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<": ";
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(c,0,sizeof(c));
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>m;
			for (int j=1;j<=m;j++)
			{
				cin>>x;
				g[i][x]=f[i][x]=true;
				c[i][x]=1;
			}
		}
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
				{
					if (i==j||j==k||k==i) continue;
					f[i][j]=f[i][j]||(f[i][k]&&f[k][j]);
				}
		bool flag=false;
		for (int i=1;i<=n;i++)
		{
			if (flag) break;
			for (int j=1;j<=n;j++)
							for (int k=1;k<=n;k++)
							{
								if (i==j||j==k||k==i) continue;
								if (f[i][k]&&g[k][j]) c[i][j]++;
								if (c[i][j]>1) flag=true;
							}
		}
		if (flag) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
}
