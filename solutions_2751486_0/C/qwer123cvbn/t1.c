#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char c;
int i,j,dp[200000],pos[200000],n,m,t,r;
long long int ans;
int main()
{
	freopen("text.in","r",stdin);
	freopen("text.out","w",stdout);
	scanf("%d",&t);
	for (r=1;r<=t;r++)
	{
		m=0;
		ans=0;
		memset(dp,0,sizeof(dp));
		memset(pos,0,sizeof(pos));
		scanf("%c",&c);
		while (1)
		{
			m++;
			scanf("%c",&c);
			if (c==' ') break;
			if ((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u'))
			{
				dp[m]=0;
			}else dp[m]=dp[m-1]+1;
			
		}
		scanf("%d",&n);
		for (i=1;i<m;i++)
		{
			if (dp[i]>=n)
			pos[i]=i-n+1;
			if (dp[i]<n)
			pos[i]=pos[i-1];
			ans=ans+pos[i];
		}
		printf("Case #%d: %lld\n",r
		
		,ans);
	}
}
