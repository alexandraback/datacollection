#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> mp;
int T, E, R, N;
long long e[20005], en;
long long dp[2][20005];
long long v[10005];
long long f[20005];

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T ; ++tc) {
		scanf("%d%d%d", &E, &R, &N);
		en = 0;
		for (int i = 0;i < N;++i) {
			scanf("%lld", &v[i]);
			if (R*i <= E) {
				e[en++] = R*i;
				e[en++] = E-R*i;
			}
		}
		
		mp.clear();
		sort(e, e + en);
		for (int i=0;i<en;++i) {
			mp[e[i]] = i;
			f[i] = -1;
		}
		for (int i=0;i<en;++i) {
			if (mp.find(e[i] - R) != mp.end()) f[i] = mp[e[i] - R];
		}
		memset(dp, 0, sizeof(dp));
		
		for (int i=0;i<N;++i) {
			for (int j=en-1;j>=0;--j) {
				if (i && f[j] != -1) {
					dp[i&1][j] = max(dp[i&1][j], dp[(i+1)&1][ f[j] ]);
				}
				if (j < en-1) {
					
					dp[i&1][j] = max(dp[i&1][j], dp[i&1][j+1] + v[i] * (e[j+1] - e[j]));
				}
				//printf("%d %d %d %lld\n", i, j, e[j], dp[i&1][j]);
			}
		}
		printf("Case #%d: %lld\n", tc, dp[(N+1)&1][0]);
	}
}