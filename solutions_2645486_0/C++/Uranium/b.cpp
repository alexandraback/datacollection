#include <cstdio>
#include <algorithm>

#define MAXN 10
#define MAXE 10
typedef long long i64;

i64 solve() {
	i64 E, R, N;
	i64 v[MAXN];

	scanf("%lld%lld%lld", &E, &R, &N);
	for(int i = 0; i < N; ++i) {
		scanf("%lld", &v[i]);
	}

	i64 V[MAXN+1][MAXE];
	for(int i = 0; i <= MAXN; ++i) {
		for(int j = 0; j < MAXE; ++j) {
			V[i][j] = -1;
		}
	}
	V[0][E] = 0;

	for(int i = 1; i <= N; ++i) {
		for(int j = 0; j <= E; ++j) {
			if(V[i-1][j] < 0) continue;

			i64 startE = std::min(j + R, E);
			for(int k = 0; k <= startE; ++k) {
				V[i][startE - k] = std::max(V[i][startE - k],
						V[i-1][j] + v[i-1]*k);
			}
		}
	}

	i64 max_v = 0;
	for(int i = 0; i <= E; ++i) {
		max_v = std::max(max_v, V[N][i]);
	}
	return max_v;
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int i = 0; i < T; ++i) {
		printf("Case #%d: %lld\n", i+1, solve());
	}

	return 0;
}
