#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define inf 10000000

int p[20], a[20], b[20];
int f[1 << 20];

int main() {
	p[0] = 1;
	for (int i = 1; i < 20; ++i)
		p[i] = p[i - 1] * 3;
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; ++cas) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", a + i, b + i);
		fill(f, f + p[n], inf);
		f[0] = 0;
		for (int s = 0; s < p[n]; ++s) {
			int star = 0;
			for (int i = 0; i < n; ++i)
				star += s / p[i] % 3;
			for (int i = 0; i < n; ++i) {
				int d = s / p[i] % 3;
				if (d < 1 && star >= a[i]) {
					f[s + p[i]] = min(f[s + p[i]], f[s] + 1);
				}
				if (d < 2 && star >= b[i]) {
					f[s + (2 - d) * p[i]] = min(f[s + (2 - d) * p[i]], f[s] + 1);
				}
			}
		}
		if (f[p[n] - 1] < inf)
			printf("Case #%d: %d\n", cas, f[p[n] - 1]);
		else
			printf("Case #%d: Too Bad\n", cas);
	}
	return 0;
}
