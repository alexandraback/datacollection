#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,TT,E,R,N,i,a[100],dp[100][100],e,j,ans;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&TT);
	for(T=1;T<=TT;T++){
		scanf("%d%d%d",&E,&R,&N);
		for(i=1;i<=N;i++)scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		dp[0][E]=0;
		for(i=1;i<=N;i++)
			for(e=0;e<=E;e++){
				for(j=0;j<=e;j++)
					dp[i][min(e-j+R,E)]=
					max(dp[i][min(e-j+R,E)],dp[i-1][e]+j*a[i]);
			}
		ans=0;
		for(e=0;e<=E;e++)ans=max(ans,dp[N][e]);
		printf("Case #%d: %d\n",T,ans);
	}
}