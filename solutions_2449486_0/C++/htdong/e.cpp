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
int a[NN][NN],n,m;
int main()
{
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);
	int tt,_;
	scanf("%d",&_);
	for(tt=1;tt<=_;tt++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
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
			//if(! flag) printf("%d %d\n",i,j);
		}
		printf("Case #%d: ",tt);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
