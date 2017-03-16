#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <string>

using namespace std;


int T;
int N, M;
long long dp[108][108];
long long toy[108][2];
long long box[108][2];

long long ans = 0;

long long calc() {
	long long ans = 0;
	for(int i = 0; i < M; ++i) {
		for(int j = i + 1; j <= M; ++j) {
			//a==1-i;
			//b==i + 1->j
			//c==j->n-1

			long long sum = 0;
			long long tmp = dp[i][box[1][1]];
			sum += min(tmp, box[1][0]);

			tmp = dp[j][box[2][1]] - dp[i][box[2][1]];
			sum += min(tmp, box[2][0]);

			tmp = dp[M + 1][box[3][1]] - dp[j][box[3][1]];
			sum += min(tmp, box[3][0]);

			ans = max(ans, sum);

		}
	}
	return ans;
}
int main() {
	freopen("input.in", "r", stdin);
	freopen("ans.txt", "w", stdout);

	scanf("%d", &T);
	
	for(int ca = 1; ca <= T; ++ca) {
		scanf("%d %d", &N, &M);
		memset(toy, 0, sizeof(toy));
		memset(box, 0, sizeof(box));

		for(int i = 1; i <= N; ++i) {
			scanf("%lld %lld", &box[i][0], &box[i][1]);
		}
		for(int i = 1; i <= M; ++i) {
			scanf("%lld %lld", &toy[i][0], &toy[i][1]);
		}
		
		ans = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= M + 1; ++i) {
			for(int j = 1; j < 101; ++j) {
				dp[i][j] = dp[i - 1][j];
			}
			dp[i][toy[i][1]] += toy[i][0];
		}

		if(N == 1) {
			ans = min(box[1][0], dp[M][box[1][1]]);
		} else if(N == 2) {
			if(box[1][1] == box[2][1]) {
				long long t1 = box[1][0] + box[2][0];
				ans = min(t1, dp[M][box[1][1]]);
			} else {
				ans = calc();
			}
		} else {
			ans = calc();
			if(box[1][1] != box[2][1] && box[2][1] != box[3][1] && box[1][1] != box[3][1]) {
				ans = calc();
			} else

			if(box[1][1] == box[2][1] && box[2][1] == box[3][1]) {
				long long t1 = box[1][0] + box[2][0] + box[3][0];
				t1 = min(t1, dp[M][box[2][1]]);
				ans = max(ans, t1);
			} else 

			if(box[1][1] == box[2][1] && box[2][1] != box[3][1]) {
				box[1][0] += box[2][0];
				box[2][1] = box[3][1];
				box[2][0] = box[3][0];
				box[3][0] = box[3][1] = 0;
				ans = max(ans, calc());
			} else if(box[1][1] != box[2][1] && box[2][1] == box[3][1]) {
				box[2][0] += box[3][0];
				box[3][0] = box[3][1] = 0;
				ans = max(ans, calc());
			} else if(box[1][1] == box[3][1] && box[2][1] != box[3][1]) {
				box[1][0] += box[3][0];
				box[2][0] = box[2][1] = 0;
				box[3][0] = box[3][1] = 0;
				long long t1 = box[1][0];
				t1 = min(t1, dp[M][box[1][1]]);
				ans = max(ans, t1);

			}
			

		}


		
		
		
		printf("Case #%d: %lld\n", ca, ans);
	}
	return 0;
}