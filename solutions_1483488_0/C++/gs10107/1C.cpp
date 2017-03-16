#include <stdio.h>
int che[2000001][11];
int u[2000001];
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	int t,z,a,b,i,j,s,n,m,ans,check;
	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
		ans=0;
		printf("Case #%d: ",z);
		scanf("%d",&a);
		scanf("%d",&b);
		m=1;
		while(a/m!=0)
		{
			m=m*10;
		}
		for(i=a;i<=b;i++)
		{
			check=0;
			u[i]=0;
			s=10;
			n=0;
			while(m!=s)
			{
				n+=(i/s);
				n+=(i%s)*(m/s);
				s=s*10;
				for(j=0;j<u[i];j++)
				{
					if(n==che[i][j])
					{
						check=1;
						break;
					}
				}
				if(check==0)
				{
					che[i][u[i]]=n;
					u[i]++;
				}
				if(a<=n && n<=b && i<n && check==0)
				{
					ans++;
				}
				n=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}