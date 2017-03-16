#include <cstdio>

int T, d[20], ss[1 << 20], bk[1 << 21], n;

void output(int x) {
	bool f = 0;
	for (int i = 0; i < n; ++i)
		if (x&(1 << i)) {
			if (f) putchar(' '); f = 1;
			printf("%d", d[i]);
		}
	puts("");
}

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d:\n", r);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", d + i);
		for (int i = 0; i < 1 << n; ++i) {
			ss[i] = 0;
			for (int j = 0; j < n; ++j)
				if (i&(1 << j))
					ss[i] += d[j];
		}
		for (int i = 0; i <= ss[(1 << n) - 1]; ++i)
			bk[i] = -1;
		for (int i = 0; i < 1 << n; ++i)
			if (bk[ss[i]] == -1) bk[ss[i]] = i;
			else {
				output(bk[ss[i]]);
				output(i);
				break;
			}
	}
	return 0;
}
