#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
int sum[maxn],f[maxn][maxn];
int i,j,n,m,s,p,tests;

int w(int x,int id)
{
	if (id==0) if (max(3*p-2,0)<=x) return 1;
	if (id==1) if (max(3*p-4,2)<=x) return 1;
	return 0;
}

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&tests);
	for (int ii=1;ii<=tests;ii++)
	{
		scanf("%d%d%d",&n,&s,&p);
		for (i=1;i<=n;i++)
			scanf("%d",&sum[i]);
		memset(f,128,sizeof(f));
		f[0][0]=0;
		for (i=1;i<=n;i++)
			for (j=0;j<=s;j++)
				if (j>0)
					f[i][j]=max(f[i-1][j]+w(sum[i],0),f[i-1][j-1]+w(sum[i],1));
				else
					f[i][j]=f[i-1][j]+w(sum[i],0);
		printf("Case #%d: %d\n",ii,f[n][s]);
	}
	return 0;
}
