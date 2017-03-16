#include <stdio.h>
#include <limits.h>
#include <algorithm>

int n;
const int MAXN = 100;
int sz[MAXN];
long long a;

void init()
{
	scanf("%lld%d", &a, &n);
	for (int i = 0; i < n; ++i) scanf("%d", &sz[i]);
	std::sort(sz, sz + n);
}

int solve(int m)
{
	int ret = 0;
	long long s = a;
	for (int i = 0; i < m; ++i) {
		if (sz[i] < s) {
			s += sz[i];
		} else {
			if (s == 1) return INT_MAX;
			while (s <= sz[i]) {
				++ret;
				s += s - 1;
			}
			s += sz[i];
		}
	}
	return ret + (n - m);
}

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int k = 1; k <= dat; ++k) {
		init();
		int ans = INT_MAX;
		for (int i = 0; i <= n; ++i) ans = std::min(ans, solve(i));
		printf("Case #%d: %d\n", k, ans);
	}
}
