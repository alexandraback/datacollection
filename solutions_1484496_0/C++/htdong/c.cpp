#include <cstdio>
#include <cstring>

int t,q,i,j,k,sum,n;
int f[21][2000001]={1},a[21],x[21],y[21];

int main ()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&t);
	for(q=1;q<=t;q++)
	{
		memset(f,0,sizeof(f));
		f[0][0]=1;
		sum=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<a[i];j++)
				f[i][j]=f[i-1][j];
			for(j=a[i];j<=sum;j++)
				f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
		}
		int flag=0;
		for(j=1;j<=sum;j++)
			if(f[n][j]>=2)
			{
				flag=1;
				break;
			}
		printf("Case #%d:\n",q);
		if(! flag)
		{
			printf("Impossible\n");
			continue;
		}
		x[0]=y[0]=0;
		k=j; i=n;
		//return 0;
		while(i)
		{
			if(j-a[i]>=0 && f[i-1][j-a[i]])
			{
				x[++x[0]]=a[i];
				j-=a[i];
				i--;
			}
			else i--;
		}
		j=k; i=n;
		while(i)
		{
			if(f[i-1][j]) i--;
			else
			{
				y[++y[0]]=a[i];
				j-=a[i];
				i--;
			}
		}
		for(i=1;i<x[0];i++) printf("%d ",x[i]);
		printf("%d\n",x[i]);
		for(i=1;i<y[0];i++) printf("%d ",y[i]);
		printf("%d\n",y[i]);
	}
	
	return 0;
}

