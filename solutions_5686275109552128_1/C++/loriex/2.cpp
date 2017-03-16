#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int T, n, x, a[1111], dp[1111];
int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		int res = 1111;
		for (int u = 1; u <= 1000; u++) {
			int rc = 0;
			for (int v = 1;  v<= n; v++)
				rc += (a[v] - 1) / u;
			res = min(res, rc + u);
		}
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}
