#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn=100+10;
int n,m;
int h[maxn][maxn];
int r[maxn],c[maxn];


void work(int kk)
{
	printf("Case #%d: ",kk);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  scanf("%d",&h[i][j]);
	for (int i=1;i<=n;i++)
	{
		r[i]=h[i][1];
		for (int j=2;j<=m;j++)
		 r[i]=(r[i]<h[i][j])?h[i][j]:r[i];
	}
	for (int j=1;j<=m;j++)
	{
		c[j]=h[1][j];
		for (int i=2;i<=n;i++)
		 c[j]=(c[j]<h[i][j])?h[i][j]:c[j];
	}
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	if (h[i][j]!=((r[i]<c[j])?r[i]:c[j])) 
		{
			printf("NO\n");
			return;
		}
	 }
	printf("YES\n");
}

int main()
{
	freopen(".in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++) work(i);
	return 0;
}
