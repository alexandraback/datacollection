#include<stdio.h>
int main()
{
	int t,n,s,p,i,k,ans,j;
	scanf("%d",&t);
	j=1;
	while(j<=t)
	{
		ans=0;
		scanf("%d%d%d",&n,&s,&p);
		p=3*p-2;
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			if(k>=p)ans++;
			else if(k<p&&k>p-3&&s&&k)
			{
				ans++;s--;
			}
		}
		printf("Case #%d: %d\n",j,ans);
		j++;
	}
	return 0;
}
