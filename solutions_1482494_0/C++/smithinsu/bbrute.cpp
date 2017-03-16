#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
void precompute(void)
{
}
int i,j,k,shi,t,test,n,a[1024],b[1024],dp[1024][1024][35],l;
int main()
{
	precompute();
	while(scanf("%d",&t)!=EOF)
	{
		test=0;
		while(t--)
		{
			test++;
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%d%d",&a[i],&b[i]);
			}
		//	for(i=0;i<n;i++)
		//		printf("%d %d \n",a[i],b[i]);
			for(i=0;i<(1<<n);i++)
			{
				for(j=0;j<(1<<n);j++)
					dp[i][j][0]=INF;
			}
			for(k=0;k<(1<<n);k++)
			{
				for(l=0;l<35;l++)
				{
					l=0;
					dp[k][0][l]=0;
					break;
				}
			}
			for(l=1;l<(3*n+1);l++)
			{
				for(i=0;i<(1<<n);i++)
				{
					for(j=0;j<(1<<n);j++)
					{
				//		if(i+j==0)
				//			continue;
						dp[i][j][l]=INF;
						for(k=0;k<n;k++)
						{
							if(l-2>=b[k]&&((i>>k)%2)>=0)
							{
								if((j>>k)%2==1)
								{
									shi=(j&(~(1<<k)));
									if(l>1)
									{
										dp[i][j][l]=min(dp[i][shi][l-2]+1,dp[i][j][l]);
									}
								}
						/*		if(i==31&&j==16&&l==2)
								{
									printf("%d %d %d %d %d %d\n",l,b[k],j,k,shi,dp[i][j][l]);
								}*/
							}
							if(l-1>=a[k]&&((j>>k)%2)>=0)
							{
								if((i>>k)%2==1)
								{
									shi=(i&(~(1<<k)));
									dp[i][j][l]=min(dp[shi][j][l-1]+1,dp[i][j][l]);
								}
							}
							if(l-1>=b[k]&&((i>>k)%2)==0)
							{
								if((j>>k)%2==1)
								{
									shi=(j&(~(1<<k)));
									{
										dp[i][j][l]=min(dp[i][shi][l-1]+1,dp[i][j][l]);
									}
								}
							}
							/*	if(i==31&&j==23&&l==10)
								{
									printf("%d %d %d %d\n",j,k,shi,dp[i][j][l]);
								}*/
						}
					}
				}
			}
//			printf("%d %d %d %d\n",dp[3][3][5],dp[3][1][3],dp[3][0][1],dp[1][0][0]);
	//		printf("%d %d %d %d\n",dp[31][31][10],dp[29][29][8],dp[28][28][6],dp[12][12][4]);
	//		printf("%d %d %d %d\n",dp[7][7][6],dp[7][3][4],dp[7][1][2],dp[7][0][0]);
			int ans=INF;
			for(i=1;i<(3*n+1);i++)
			{
			//	printf("%d %d\n",ans,i);
			//	for(j=0;j<(1<<n);j++)
			//	{
					j=(1<<n)-1;
					ans=min(ans,dp[j][(1<<n)-1][i]);
			//	}
			}
			if(ans!=INF)
			{
				printf("Case #%d: %d\n",test,ans);
				fprintf(stderr,"Case #%d: %d\n",test,ans);
			}
			else
			{
				printf("Case #%d: Too Bad\n",test);
				fprintf(stderr,"Case #%d: Too Bad\n",test);
			}
		}
	}
	return 0;
}
