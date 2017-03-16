int dp[20][20],e,r,n,a[20],t;

main()
{
	int i,j,k,l,m;
	scanf("%*d");
	while(~scanf("%d%d%d",&e,&r,&n))
	{
		memset(dp,-1,sizeof(dp));
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=e;i++)
		{
			j=e-i+r<e?e-i+r:e;
			dp[1][j]=i*a[1];
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<=e;j++)
			{
				if(dp[i][j]==-1) continue;
				for(k=0;k<=j;k++)
				{
					l=j-k+r<e?j-k+r:e;
					m=dp[i][j]+a[i+1]*k;
					dp[i+1][l]=m>dp[i+1][l]?m:dp[i+1][l];
				}
			}
		}
		for(i=1,j=0;i<=e;i++) j=dp[n][i]>j?dp[n][i]:j;
		printf("Case #%d: %d\n",++t,j);
	}
}
