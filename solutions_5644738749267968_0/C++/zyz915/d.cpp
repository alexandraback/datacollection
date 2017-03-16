#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1001;
double a[N], b[N];
int c[N];

int main(int argc, char **argv) {
	int cas, T;
	scanf("%d", &T);
	for (cas = 1; cas <= T; cas++) {
		int n, i, j;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%lf", a + i);
		for (i = 0; i < n; i++)
			scanf("%lf", b + i);
		std::sort(a, a + n);
		std::sort(b, b + n);
		memset(c, 0, sizeof(int) * n);
		int l2 = 0, ptr = 0;
		for (i = 0; i < n; i++) {
			while (ptr < n && b[ptr] < a[i]) ptr++;
			if (ptr < n && b[ptr] > a[i]) {
				l2++; ptr++;
			}
		}
		int w1 = 0, w2 = n - l2;
		ptr = 0;
		for (i = 0; i < n; i++) {
			while (ptr < n && a[ptr] < b[i]) ptr++;
			if (ptr < n && a[ptr] > b[i]) {
				w1++; ptr++;
			}
		}
		printf("Case #%d: %d %d\n", cas, w1, w2);
	}
	return 0;
}

