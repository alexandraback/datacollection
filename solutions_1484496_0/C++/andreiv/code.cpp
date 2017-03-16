#include <cstdio>
#include <cstring>
int ok[1<<21];

int main()
{
	int tt,n,t,i,j,v[30],bit,sum,k;
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt)
	{
		scanf("%d",&n);
		for (i=0;i<n;++i) scanf("%d",&v[i]);
		memset(ok,0,sizeof(ok));
		bit=sum=0;
		i=0;
		while (i<n)
		{
			for (i=0;i<n;++i)
				if (!(bit&(1<<i)))
				{
					bit^=(1<<i);
					sum+=v[i];
					break;
				} else
				{
					bit^=(1<<i);
					sum-=v[i];
				}
			ok[bit]=sum;	
		}
		for (i=1;i<(1<<20);++i)
			for (j=i+1;j<(1<<20);++j)
				if (ok[i]==ok[j])
				{
					printf("Case #%d:\n",tt);
					for (k=0;k<20;++k)
						if (i&(1<<k))
							printf("%d ",v[k]);
					printf("\n");
					for (k=0;k<20;++k)
						if (j&(1<<k))
							printf("%d ",v[k]);
					printf("\n");
					n=0;
					i=j=1<<20;
				}
		if (n)
			printf("Case #%d:\nImpossible\n");
			
	}
return 0;
}
					
				
		
		