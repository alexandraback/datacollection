#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn=110;

int a[Maxn];
int f[Maxn][Maxn];
int n,m,lim,Test;

int main()
{
	//freopen("x.in","r",stdin);
	//freopen("b.out","w",stdout);
	
	scanf("%d",&Test);
	for (int ii=1;ii<=Test;++ii)
	{
		scanf("%d%d%d",&n,&m,&lim);
		for (int i=0;i<=n;++i)
			for (int j=0;j<=m;++j)
				f[i][j]=-999999999;
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
			
		f[0][0]=0;
		for (int i=1;i<=n;++i)
		{
			int ave=a[i]/3;
			//Not surprise
			int Max1=-1;
			if (a[i] % 3!=0) Max1=ave+1;
			else Max1=ave;
			//surprise
			int Max2=-1;
			if (a[i] % 3!=2 && ave>0) Max2=ave+1;
			if (a[i] % 3==2) Max2=ave+2;
			for (int j=0;j<=m;++j)
			{
				//Not suprise
				f[i][j]=max(f[i][j],f[i-1][j]+(Max1>=lim));
				//surprise
				if (j>0 && Max2!=-1)
					f[i][j]=max(f[i][j],f[i-1][j-1]+(Max2>=lim));
			}
		}
		printf("Case #%d: %d\n",ii,f[n][m]);
	}
	
	return 0;
}