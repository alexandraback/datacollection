#include <cstdio>

int a[1010], b[1010], c[1010], n, my;

int makeOut() {
	int ret = 0;

	return ret;
}

int main() {
	freopen("B03.in", "r", stdin);
	freopen("B03.txt", "w",stdout);
	int task; scanf("%d", &task);
	for (int cas = 1; cas <= task; ++cas) {
		scanf("%d", &n); my = 0;
		for (int i = 1; i <= n; ++i) c[i] = 0;
		int ans = 0;
		for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]);
		int left = n;
		while (left > 0) {
			bool done = true;
			while (done) {
				done = false;
				for (int i = 1; i <= n; ++i) 
					if (c[i] < 2 && b[i] <= my) {
						my += 2 - c[i];
						c[i] = 2;
						ans ++; left --;
						done = true;
					} 
			}
			if (left == 0) break;
			int p = -1;
			for (int i = 1; i <= n; ++i) 
				if (c[i] == 0 && my >= a[i]) {
					if (p == -1 || b[i] > b[p]) p = i;
				}
			if (p == -1) break;
			c[p] = 1;
			my += 1;
			++ans;
		}
		
		printf("Case #%d: ", cas);
		if (left > 0) puts("Too Bad"); else
			printf("%d\n", ans);
	}
	return 0;
}
