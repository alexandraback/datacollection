#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
#include<vector>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 110
#define MM 10010
int a[NN][NN],n,m,f[NN][NN],c[NN][NN];
int main()
{
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);
	int tt,_;
	scanf("%d",&_);
	for(tt=1;tt<=_;tt++)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			c[i][j]=a[i][j];
		}
		int flag=1;
		for(int i=1;flag && i<=n;i++)
		for(int j=1;flag && j<=m;j++)
		{
			int f1=1,f2=1;
			for(int x=1;f1 && x<=n;x++)
				if(a[x][j]>a[i][j]) f1=0;
			for(int x=1;f2 && x<=m;x++)
				if(a[i][x]>a[i][j]) f2=0;
			flag=f1 || f2;
			if(f1 && f2) f[i][j]=3;
			else if(f1) f[i][j]=1;
			else if(f2) f[i][j]=2;
			//if(! flag) printf("%d %d\n",i,j);
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(f[i][j]==1 || f[i][j]==3)
			for(int x=1;x<=n;x++)
				c[x][j]=min(c[x][j],c[i][j]);
			if(f[i][j]==2 || f[i][j]==3)
			for(int x=1;x<=m;x++)
				c[i][x]=min(c[i][x],c[i][j]);
		}
		for(int i=1;flag && i<=n;i++)
		for(int j=1;flag && j<=m;j++)
			if(c[i][j]!=a[i][j]) flag=0;
		printf("Case #%d: ",tt);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
