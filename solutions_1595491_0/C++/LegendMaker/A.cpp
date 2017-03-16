#include<cstdio>
#include<cstring>
#define maxn 110
int dp[maxn][maxn],a[maxn];
inline int MAX(int x,int y)
{
	return x>y?x:y;
}
int Surprise(int val)
{
	if(val<2)
		return -1;
	if(!((val-2)%3))
		return (val-2)/3+2;
	if(!((val-3)%3))
		return (val-3)/3+2;
	return (val-4)/3+2;
}
int Ordinary(int val)
{
	if(!((val+2)%3))
		return (val+2)/3;
	if(!((val+1)%3))
		return (val+1)/3;
	return val/3;
}
int main()
{
	int c,n,s,p,i,j,temp,ca=1;
	freopen("B-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d%d%d",&n,&s,&p);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=s&&j<=i;j++)
			{
				if(i!=j)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=dp[i-1][j-1];
				temp=Surprise(a[i]);
				if(temp>=p&&j)
					dp[i][j]=MAX(dp[i][j],dp[i-1][j-1]+1);
				temp=Ordinary(a[i]);
				if(temp>=p&&j!=i)
					dp[i][j]=MAX(dp[i][j],dp[i-1][j]+1);
			}
		}
		printf("Case #%d: %d\n",ca++,dp[n][s]);
	}
	return 0;
}