#include <cstdio>
#include <algorithm>
using namespace std;

int T, n;
double a[1005], b[1005];

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%lf", &a[i]);
		for (int i = 0; i < n; ++i) scanf("%lf", &b[i]);
		sort(a, a + n);
		sort(b, b + n);
		printf("Case #%d: ", tc);
		{
			int i = 0, j = 0, k = n - 1, ans = 0;
			while (j <= k) {
				if (a[i] > b[j]) {
					++ans;
					++i;
					++j;
				}
				else {
					if (a[i] > b[k]) ++ans;
					++i;
					--k;
				}
			}
			printf("%d ", ans);
		}
		{
			int i = 0, j = 0;
			while (j < n) {
				if (a[i] < b[j]) {
					++i;
					++j;
				}
				else {
					++j;
				}
			}
			printf("%d\n", n - i);
		}
	}
	return 0;
}