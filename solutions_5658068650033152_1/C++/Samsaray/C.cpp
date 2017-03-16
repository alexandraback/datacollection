#include<cstdio>
#include<cstring>
#include<algorithm>
int N, M, K;
void process() {
	int ans = K;
	for(int i = 3; i <= N; i ++) {
		for(int j = i; j <= M; j ++) {
			int used = 2 * (i + j) - 4, tot = i * j;
			if(tot < K) continue;

			int max = 4 * ((i + 1) / 2) + (i % 2 == 0 ? 2 : 0) + 1, min = 0, mid;
			for(;;) {
				mid = (max - min) / 2 + min;
				if(mid == min) break;

				int n = mid / 4, sum = 0;
				if(n > 0) {
					sum += (1 + n) * n * 2;
				}
				sum += (mid - 4 * n) * (n + 1);

				if(tot - sum >= K) min = mid;
				else max = mid;
			}

			ans = std::min(used - mid, ans);
		}
	}
	printf("%d\n", ans);
}
int main() {
	freopen("C-large.in", "rb", stdin);
	freopen("C-large.out", "wb", stdout);
	int t;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt ++) {
		scanf("%d%d%d", &N, &M, &K);
		if(N > M) std::swap(N, M);

		printf("Case #%d: ", tt);
		if(N <= 2) {
			printf("%d\n", K);
			continue;
		}
		process();
	}
	return 0;
}
