#include <cstdio>
#include <algorithm>
using namespace std;

#define N 1024

int T, ans1, ans2, n, t;
double d[N], e[N];

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lf", d + i);
		for (int i = 0; i < n; ++i)
			scanf("%lf", e + i);
		sort(d, d + n);
		sort(e, e + n);
		ans1 = 0;
		for (int i = 0; i < n; ++i)
			if (d[i] > e[ans1]) ++ans1;
		ans2 = 0; t = 0;
		for (int i = 0; i < n; ++i) {
			while (t < n && d[i] > e[t]) ++t;
			if (t < n) ++ans2;
			++t;
		}
		printf("%d %d\n", ans1, n - ans2);
	}
	return 0;
}
