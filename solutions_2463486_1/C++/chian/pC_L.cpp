#include<stdio.h>
int cnt=3;
long long int dp[1002];

void pal(long long int n,long long int tmp)
{
	int dig=0,rev=0,flg=1,j;
	int s[20];
	if(!tmp)return;
	while(tmp)
	{
		dig++;
		rev=rev*10+tmp%10;
		tmp/=10;
	}
	while(dig--)n*=10;
	n+=rev;//printf("%I64d\n",n*n);
	tmp=n*n;
	dig=0;
	while(tmp)
	{
		s[dig++]=tmp%10;
		tmp/=10;
	}
	for(j=0;j<dig/2&&flg;j++)if(s[j]!=s[dig-1-j])flg=0;
	if(flg)dp[cnt++]=n*n;
}
int main()
{
	freopen("C-large-1.txt","r",stdin);
	freopen("pC_out.txt","w",stdout);
	
	int i;
	dp[0]=1,dp[1]=4,dp[2]=9;
	for(i=1;i<=2001;i++)
	{
		pal(i,i);
		pal(i,i/10);
	}
	//printf("%d\n",cnt);
	//for(i=0;i<cnt;i++)printf("%I64d ",dp[i]);
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		long long int a,b;
		int ans=0;
		scanf("%I64d%I64d",&a,&b);
		for(i=0;i<cnt;i++)if(dp[i]>=a&&dp[i]<=b)ans++;
		printf("Case #%d: %d\n",cas++,ans);
	}
	return 0;
}
