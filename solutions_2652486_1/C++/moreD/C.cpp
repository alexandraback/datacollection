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
			LL b = p;
			for (int k = 2; k < 9; k++) {
				p = b;
				while (p % k == 0) e[k]++, p /= k;
				cnt[k] += e[k];
				m[k] = max(m[k], e[k]);
			}
		}
			int w = N;
			for (int k = 2; k < 4; k++) {
				for (int v = 0; v < m[pr[k]]; v++) printf("%d", pr[k]);
				w -= m[pr[k]];
			}
			int ei = 0, si = 0;
			if (cnt[8] > 7 || m[8] > 2) ei++;
			if (cnt[8] > 14 || m[8] > 3) ei++;
			if (cnt[8] > 20 || m[8] > 4) ei++;
			if (cnt[8] > 27) ei++;
			if (cnt[6] > 8 || m[6] > 2) si++;
			if (cnt[6] > 16 || m[6] > 3) si++;
			if (cnt[6] > 23 || m[6] > 4) si++;
			if (cnt[6] > 30 || m[6] > 5) si++;
			w -= ei + si;
			if (w < 0) {
				int te = 30, ts = 34;
				while (w < 0) {
					if (cnt[8] < te) te -= 7, ei--, w++;
					if (cnt[6] < ts) ts -= 7, si--, w++;
				}
			}
			m[2] -= ei * 3;
			m[3] -= si;
			for (int v = 0; v < ei; v++) printf("8");
			for (int v = 0; v < si; v++) printf("6");
			for (int v = 0; v < min(w, m[3]); v++) printf("3");
			w -= m[3];
			if (m[2] > w && w > 0 && m[2] > 0) {
				for (int v = 0; v < min(w, m[2] - w); v++) printf("4");
				int ww = w - min(w, m[2] - w);
				for (int v = 0; v < min(ww, w + w - m[2]); v++) printf("2");
			} else for (int v = 0; v < w; v++) printf("2");

			printf("\n");
	}
}
