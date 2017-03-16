#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int pr[] = {2, 3, 5, 7};
int T, R, N, M, K, cnt[9], m[9], e[9];
LL p;

int main() {
	scanf("%d", &T);
	printf("Case #1:\n");
	scanf("%d%d%d%d", &R, &N, &M, &K);
	for (; R--;) {
		memset(cnt, 0, sizeof(cnt));
		memset(m, 0, sizeof(m));
		for (int i = 0; i < K; i++) {
			scanf("%I64d", &p);
			memset(e, 0, sizeof(e));
			for (int k = 0; k < 4; k++) {
				while (p % pr[k] == 0) e[pr[k]]++, p /= pr[k];
				cnt[pr[k]] += e[pr[k]];
				m[pr[k]] = max(m[pr[k]], e[pr[k]]);
			}
		}
			int w = N;
			for (int k = 1; k < 4; k++) {
				for (int v = 0; v < m[pr[k]]; v++) printf("%d", pr[k]);
				w -= m[pr[k]];
			}
			if (m[2] <= w) {
				for (int v = 0; v < w; v++) printf("%d", 2);
			} else {
				for (int v = 0; v < m[2] - w; v++) printf("%d", 4);
				for (int v = 0; v < w + w - m[2]; v++) printf("%d", 2);
			}

			printf("\n");
	}
}
