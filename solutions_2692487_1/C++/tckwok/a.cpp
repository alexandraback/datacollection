#include <cstdio>
#include <algorithm>
using namespace std;

#define N 128

int T, x, n, d[N], ans, cnt;

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		scanf("%d%d", &x, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", d + i);
		sort(d, d + n);
		ans = n;
		cnt = 0;
		for (int i = 0; i < n; ++i) {
			while (x <= d[i] && cnt < ans) {
				++cnt;
				x += x - 1;
			}
			x += d[i];
			if (n - i - 1 + cnt < ans)
				ans = n - i - 1 + cnt;
		}
		printf("Case #%d: %d\n", r, ans);
	}
	return 0;
}
