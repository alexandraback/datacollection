#include <stdio.h>
#include <stdlib.h>
int cmp(const void *p,const void *q)
{
	return *(int *)p-*(int *)q;
}

int main()
{
	int t,b,a[110],ans,dp[110],n,i,test=0;
	freopen("Al.in","r",stdin);
	freopen("al.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&b,&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		qsort(a+1,n,sizeof(int),cmp);
		if(b==1)
		{
			printf("Case #%d: %d\n",++test,n);
			continue;
		}
		dp[0]=0;
		for(i=1;i<=n;i++)
		{
			dp[i]=dp[i-1];
			while(1)
			{
				if(b>a[i])
				{
					b+=a[i];
					break;
				}
				else
				{
					dp[i]++;
					b=b*2-1;
				}
			}
		}
		for(i=0,ans=n;i<=n;i++)
		{
			if(dp[i]+n-i<ans)
				ans=dp[i]+n-i;
		}
		printf("Case #%d: %d\n",++test,ans);
	}
	return 0;
}