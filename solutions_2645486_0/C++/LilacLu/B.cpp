#include <iostream>
#include <algorithm>
#include <cstdio>

#define SMALL
//#define LARGE

using namespace std;

int T;
int e, r, n, max_value, value[10005];
long long ans;

int main()
{
#ifdef SMALL
	freopen("B_small.in", "r", stdin);
	freopen("B_small.out", "w", stdout);
#endif

#ifdef LARGE
	freopen("B_large.in", "r", stdin);
	freopen("B_large.out", "w", stdout);
#endif

	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%d %d %d", &e, &r, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &value[i]);
		sort (value, value + n);
		ans = 0;
		long long en = 1LL * r * (n - 1) + e;
		for (int i = n - 1; i > -1; --i) {
			if (en == 0)
				break;
      if (en > e) {
				ans += e * value[i];
				en -= e;
			} else {
				ans += en * value[i];
				en = 0;
			}
		}
		printf("Case #%d: %lld\n", Case, ans);
	}
	return 0;
}

