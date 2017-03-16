#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[20][10];

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; ++cas) {
		int e, r, n; scanf("%d%d%d", &e, &r, &n);
		memset(f, 0x80, sizeof f);
		f[0][e] = 0;
		for (int i = 0; i < n; ++i) {
			int v; scanf("%d", &v);
			for (int j = 0; j <= e; ++j) {
				for (int k = 0; k <= j; ++k) {
					int h = min(j - k + r, e);
					f[i + 1][h] = max(f[i + 1][h], f[i][j] + k * v);
				}
			}
		}
		int ans = 0;
		for (int j = 0; j <= e; ++j) {
			ans = max(ans, f[n][j]);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
