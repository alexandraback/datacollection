#include <stdio.h>
#include <algorithm>
#include <assert.h>
using namespace std;
long long dp[110][110];
#define INF (1LL<<58)

main(){
	int testcase;
	scanf("%d ",&testcase);
	for(int casenum=1;casenum<=testcase;casenum++){
		printf("Case #%d: ",casenum);
		long long a,n;
		scanf("%lld%lld",&a,&n);
		long long x[110];
		for(int i=0;i<n;i++)scanf("%lld",&x[i]);
		sort(x,x+n);
		for(int i=0;i<=n;i++)for(int c=0;c<=n;c++)dp[i][c]=((i==0&&c==0)?a:-INF);
		for(int i=0;i<n;i++){
			for(int c=0;c<=n;c++){
				if(dp[i][c]<0)continue;
				//ganbaru
				if(dp[i][c]>1){
					int nc=c;
					long long s=dp[i][c];
					for(;;){
						if(s>x[i])break;
						nc++;
						s=2*s-1;
					}
					if(nc<=n)dp[i+1][nc]=max(dp[i+1][nc],s+x[i]);
				}
				//ganbaranai
				if(c<n)dp[i+1][c+1]=max(dp[i+1][c+1],dp[i][c]);
			}
		}
		int ans;
		for(ans=0;ans<=n;ans++){
			if(dp[n][ans]>=0)break;
		}
		assert(ans<=n);
		printf("%d\n",ans);
	}
}