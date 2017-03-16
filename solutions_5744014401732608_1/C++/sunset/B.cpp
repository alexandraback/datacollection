#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int mp[54][54];
	int T;
	scanf("%d", &T);
	int B;
	long long M;
	for(int NOWCASE=1; NOWCASE<=T; ++NOWCASE) {
		scanf("%d%lld", &B, &M);
		memset(mp, 0, sizeof(mp));
		long long dp[54] = {};
		memset(dp, 0, sizeof(dp));
		dp[B-1] = 1LL;
		long long nowSum = 0;
		for(int s=B-1; s>0; --s)
		for(int t=B-1; t>s && dp[s]<M; --t) {
			mp[s][t] = 1;
			dp[s] += dp[t];
		}
		for(int t=1; t<B; ++t)
			if( M>=dp[t] ) {
				mp[0][t] = 1;
				M -= dp[t];
			}





		printf("Case #%d: ", NOWCASE);
		if( M!=0 ) puts("IMPOSSIBLE");
		else {
			puts("POSSIBLE");
			for(int i=0; i<B; ++i) {
				for(int j=0; j<B; ++j)
					printf("%d", mp[i][j]);
				puts("");
			}
		}
	}
	return 0;
}
