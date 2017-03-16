 //FUCK

#include<stdio.h>

int dp[20][10];
int value[20];

void clear()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<10;j++)
		{
			dp[i][j]=0;
		}
		value[i]=0;
	}
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	int t,e,r,n;
	scanf("%d",&t);
	for(int tt=0;tt<t;tt++)
	{
		clear();
		scanf("%d %d %d",&e,&r,&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&value[i]);
		}

		for(int i=0;i<n;i++)
		{
			for(int j=r;j<=e;j++)
			{
				for(int k=0;k<=j;k++)
				{
					int gain=value[i]*(j-k);
					int ran=dp[i][j]+gain;
					int kk=k+r;
					if(kk>e)
					{
						kk=e;
					}
					if(ran>dp[i+1][kk])
					{
						dp[i+1][kk]=ran;
					}
				}
			}
		}

		printf("Case #%d: %d\n",tt+1,dp[n][r]);

	}
}
