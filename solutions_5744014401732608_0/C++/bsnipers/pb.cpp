#include <stdio.h>
#include <string.h>

typedef long long ll;

int dp[55][55];

int main()
{
	int cas;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		ll n,m;
		scanf("%I64d %I64d",&n,&m);
		if((m-1)>>(n-2)){
			printf("Case #%d: IMPOSSIBLE\n",T);
			continue;
		}else{
			printf("Case #%d: POSSIBLE\n",T);
		}
		memset(dp,0,sizeof(dp));
		for(int i=0; i<n-1; i++){
			dp[i][i+1]=1;
		}
		m--;
		for(int i=2; i<n; i++){
			for(int j=i-3; j>=0; j--){
				if(m>=(1ll<<j)){
					dp[n-1-i][n-2-j]=1;
					m-=(1ll<<j);
				}
			}
			if(m>=1){
				dp[n-1-i][n-1]=1;
				m-=1;
			}
		}
		for(int i=0; i<n; i++,puts(""))
			for(int j=0; j<n; j++)
				printf("%d",dp[i][j]);
	}
	return 0;
}
