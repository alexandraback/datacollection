#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int E, R, N, v[10];
int dp[2][6];

inline void upt(int &des, int src) {
	des = max(des, src);
}

int main() {
	int TST;
	scanf("%d", &TST);
	for (int _ = 0; _ < TST; ++ _) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 0; i < N; ++ i)
			scanf("%d", &v[i]);
		int des = 0, src = 1;
		memset(dp[des], 0xf3, sizeof(dp[des]));
		dp[des][E] = 0;
		for (int i = 0; i < N; ++ i) {
			des ^= 1, src ^= 1;
			memset(dp[des], 0xf3, sizeof(dp[des]));
			for (int j = 0; j <= E; ++ j)
				if (dp[src][j] >= 0)
					for (int k = 0; k <= j; ++ k)
						upt(dp[des][min(E, j - k + R)], dp[src][j] + k * v[i]);
		}
		int res = 0;
		for (int j = 0; j <= E; ++ j) upt(res, dp[des][j]);
		printf("Case #%d: %d\n", _ + 1, res);
	}
	return 0;
}
