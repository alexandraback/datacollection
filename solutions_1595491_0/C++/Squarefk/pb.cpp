#include <cstdio>
#include <algorithm>

using namespace std;

int times,n,s,p,a[110],dp[110][110];

int main()
{
    freopen("in","r",stdin);
	scanf("%d",&times);
	for (int t=1;t<=times;++t)
	{
		scanf("%d%d%d",&n,&s,&p);
		for (int i=1;i<=n;++i) scanf("%d",&a[i]);
		for (int i=0;i<=n;++i)
			for (int j=0;j<=s;++j) dp[i][j]=-1;
		dp[0][0]=0;
		for (int i=0;i<=n-1;++i)
			for (int j=0;j<=s;++j)
				if (dp[i][j]>=0)
				{
					int t1=-1,t2=-1;
					if (a[i+1]%3==0){
						t1=a[i+1]/3;
						if (a[i+1]>=3) t2=a[i+1]/3+1;
					}
					if (a[i+1]%3==1){
						t1=a[i+1]/3+1;
						if (a[i+1]>=4) t2=a[i+1]/3+1;
					}
					if (a[i+1]%3==2){
						t1=a[i+1]/3+1;
						t2=a[i+1]/3+2;
					}
					if (t1>=p) dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
						else dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
					if ((j<s)&&(t2>=0))
					if (t2>=p) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
						else dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
				}
		printf("Case #%d: %d\n",t,dp[n][s]);
	}
	return 0;
}
