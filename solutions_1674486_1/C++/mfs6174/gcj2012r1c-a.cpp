#include <cstdio>
#include <cstring>
using namespace std;

int t,q,i,j,k,l,n,zz,zu;
int f[1100][1100];
int dd[1000][1000];

bool floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
          f[i][j]+=f[i][k]*f[k][j];
          if(f[i][j]>1)return 1;
        }
	return 0;
}

int main()
{
	freopen("ti.in","r",stdin);
	freopen("ti.out","w",stdout);
	scanf("%d",&zu);
	for(zz=1;zz<=zu;zz++)
	{
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			for(j=1;j<=k;j++)
			{
				scanf("%d",&l);
				f[i][l]=1;
			}
		}
		printf("Case #%d: ",zz);
		if(floyd())printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}

