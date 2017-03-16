#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MaxN = 11111;
int e, r, n, v[MaxN], p[MaxN], q[MaxN], t[MaxN];

void solve() {
	scanf("%d%d%d", &e, &r, &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &v[i]);
	}
	p[1] = q[1] = e;
	for (int i = 2; i <= n; ++ i) {
		p[i] = q[i] = min(q[i - 1] - p[i - 1] + r, e);
		int maxv = INT_MAX, j = i - 1;
		for (; j > 0 && v[j] < v[i]; -- j) {
			maxv = min(maxv, e - q[j + 1]);
			if (maxv <= 0) break;
			maxv -= t[j] = min(maxv, p[j]);
		}
		for (++ j; j < i; ++ j) {
			p[j] -= t[j];
			p[j + 1] += t[j];
			t[j + 1] += t[j];
			q[j + 1] += t[j];
		}
	}
	ll result = 0;
	for (int i = 1; i <= n; ++ i) {
		result += (ll)v[i] * p[i];
	}
	printf("%lld\n", result);
}

int main() {
	int test_cases;
	scanf("%d", &test_cases);
	for (int t = 1; t <= test_cases; ++ t) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}