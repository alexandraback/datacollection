#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <assert.h>
using namespace std;
int sup[31][11];
int nsup[31][11];
int allow(int a,int b,int c)
{
	if (a<b) swap(a,b);
	if (a<c) swap(a,c);
	if (b<c) swap(b,c);
	if (a>c+2)
		return 0;
	if (a==c+2)
		return 1;
	return 2;
}
int f[200][200];
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);
	int i,j,k;
	int t;
	for (t=0;t<31;t++)
	{
		for (i=0;i<=10;i++)
			for (j=0;j<=i;j++)
			{
				k=t-i-j;
				if (k>i || k<0) continue;
				int s=allow(i,j,k);
				if (s==0)
					continue;
				if (s==1)
					sup[t][i]=1;
				if (s==2)
					nsup[t][i]=1;
			}
		for (i=10;i>0;i--)
		{
			sup[t][i-1] |= sup[t][i];
			nsup[t][i-1] |= nsup[t][i];
		}
	}
	memset(f,0,sizeof(f));
	int n,s,p;
	int cas=0,cass;
	for (scanf("%d",&cass);cass--;)
	{
		scanf("%d%d%d",&n,&s,&p);
		int a[200];
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		for (i=1;i<=n;i++)
			for (j=0;j<=s;j++)
			{
				if (f[i][j] < f[i-1][j] + nsup[a[i]][p])
					f[i][j] = f[i-1][j] + nsup[a[i]][p];
				if (j==0)continue;
				if (f[i][j] < f[i-1][j-1] + sup[a[i]][p])
					f[i][j] = f[i-1][j-1] + sup[a[i]][p];
			}
		++cas;
		printf("Case #%d: ",cas);
		printf("%d\n",f[n][s]);
	}
	return 0;
}


					