#include<stdio.h>
int a[600],n,mem[9999999];
bool b[600];
void dfs(int x,int sum,int now)
{
	if(x==n)
	{
		mem[now]=sum;
		return;
	}
	b[x]=0;
	dfs(x+1,sum,now);
	b[x]=1;
	dfs(x+1,sum+a[x],now+(1<<x));
}
main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int abc,i,j,T;
	scanf("%d",&T);
	for(abc=1;abc<=T;abc++)
	{
		printf("Case #%d:\n",abc);
		int ok=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		dfs(0,0,0);
		for(i=0;i< 1<<n && ok;i++)
		{
			for(j=i+1;j< 1<<n && ok;j++)
			{
				if(mem[i]==mem[j])
				{
					ok=0;
					int count=0;
					while(i)
					{
						if(i%2==1)
						{
							i-=1;
							printf("%d ",a[count]);
						}
						i/=2;
						count++;
					}
					count=0;
					puts("");
					while(j)
					{
						if(j%2==1)
						{
							j-=1;
							printf("%d ",a[count]);
						}
						j/=2;
						count++;
					}
				}
			}
		}
		puts("");
	}
}
