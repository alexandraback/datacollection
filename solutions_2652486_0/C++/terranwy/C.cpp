#include <cstdio>
#include <cstring>

int cases, R, N, M, K;
int cnt[100];
int ans[100];
long long v[100];

int count(long long now, long long num) {
	int cnt = 0;
	while (now % num == 0) {
		++cnt;
		now /= num;
	}
	return cnt;
}

int main() {
	scanf("%d%d%d%d%d", &cases, &R, &N, &M, &K);
	printf("Case #1:\n");
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < K; ++j) {
			scanf("%I64d", v + j);
			//printf("v[%d]:%I64d", j, v[j]);
		}
		
		memset(cnt, 0, sizeof cnt);
		for (int j = 0; j < K; ++j) 
			for (int t = 2; t < 9; ++t) {
				int c = count(v[j], t);
				if (c > cnt[t]) cnt[t] = c;
			}
		//printf("count:\n");
		//for (int j = 2; j < 9; ++j) printf("%d:%d\t", j, cnt[j]);
		//printf("\n");
		
		int len = 0;
		while (cnt[5]-- > 0) {
			ans[len++] = 5;
		}
		while (cnt[3]-- > 0) {
			ans[len++] = 3;
		}
		if (len == 2) {
			if (cnt[4] > 0) ans[len++] = 4;
			else ans[len++] = 2;
		}
		else if (len == 1) {
			if (cnt[2] > 2) {
				ans[len++] = 4;
				ans[len++] = 2 * (cnt[2] - 2);
			}
			else {
				ans[len++] = 2;
				ans[len++] = 2;
			}
		}
		else if (len == 0) {
			if (cnt[2] > 4) {
				ans[len++] = 4;
				ans[len++] = 4;
				ans[len++] = 2 * (cnt[2] - 4);
			}
			else if (cnt[2] == 4) {
				ans[len++] = 4;
				ans[len++] = 2;
				ans[len++] = 2;
			}
			else {
				ans[len++] = 2;
				ans[len++] = 2;
				ans[len++] = 2;
			}
		}
		
		for (int j = 0; j < 3; ++j) printf("%d", ans[j]);
		printf("\n");
	}

	return 0;
}
