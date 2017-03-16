#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 111111;

double a[N], b[N];
int n;

int main() {
	freopen("D-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	while(test--) {
		static int testCount = 0;
		printf("Case #%d: ", ++testCount);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lf", &a[i]);
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i++)
			scanf("%lf", &b[i]);
		sort(b + 1, b + n + 1);
		int ans1 = 0, ans2 = 0;
		for(int i = 1, p = 1; i <= n; i++) {
			while(p <= n && b[p] < a[i])
				p++;
			ans2 += (p > n);
			p++;
		}
		int l = 1, r = n;
		for(int i = n; i >= 1; i--) {
			if (a[r] > b[i]) {
				r--;
				ans1++;
			} else {
				l++;
			}
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
