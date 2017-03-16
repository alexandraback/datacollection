#include <cstdio>
#include <cstring>
#include <cmath>

inline int min(int a, int b) { return a < b? a: b; }

int D;
int maxP;
int cnt[1005];

void findMax() {
	while (maxP > 0 && cnt[maxP] == 0) --maxP;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &D);
		for (int i = 0; i < D; ++i) {
			int tmp;
			scanf("%d", &tmp);
			cnt[tmp]++;
		}
		//
		int ans = 999999;
		for (int i = 1; i <= 1000; ++i) {
			int tmp = 0;
			for (int j = i + 1; j <= 1000; ++j) {
				tmp += (j - 1) / i * cnt[j];
			}
			ans = min(ans, tmp + i);
		}
		//
		/*
		maxP = 1000;
		findMax();
		int sum = 0, ans = maxP;
		while (maxP > 1) {
			int sq = int(sqrt(maxP) + 1e-8);
			cnt[maxP]--;
			int left = maxP;
			//printf("sq= %d\n", sq);
			while (left > sq) {
				cnt[sq]++;
				++sum;
				left -= sq;
			}
			cnt[left]++;
			findMax();
			//printf("maxp = %d, sum = %d\n", maxP, sum);
			ans = min(ans, sum + maxP);
		}*/
		printf("Case #%d: %d\n", t, ans);
	}
}