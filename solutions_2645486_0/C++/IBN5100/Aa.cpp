#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=32,maxm=1200;
int dp[maxn][maxm],tmp[maxm],v[maxn];
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("data2.out","w",stdout);
	int T,ca=1;
	int d,r,n,e;
	scanf("%d",&T);
	while(T--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d%d%d",&e,&r,&n);
		for(int i=1;i<=n;i++)scanf("%d",&v[i]);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=e;j++) {
				for(int k=0;k<=j;k++) {
					int tmp=j-k+r;
					int val=k*v[i];
					if(tmp>e)tmp=e;
					dp[i+1][tmp]=max(dp[i+1][tmp],val+dp[i][j]);
				}
			}
		}
		int ans=0;
		for (int i=0;i<=e;i++) ans=max(ans,dp[n+1][i]);
		printf("Case #%d: ",ca++);
		printf("%d\n",ans);
	}

}

