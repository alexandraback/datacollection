#include <iostream>
#include <cstdio>
#include <cmath>

#define SMALL
//#define LARGE

using namespace std;

#define eps 1e-9

int T;
long long r, t;

int main()
{
#ifdef SMALL
	freopen("A_small.in", "r", stdin);
	freopen("A_small.out", "w", stdout);
#endif

#ifdef LARGE
	freopen("A_large.in", "r", stdin);
	freopen("A_large.out", "w", stdout);
#endif
	
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%lld %lld", &r, &t);
		int mid, top, bot;
		bot = 1, top = 1000000000;
		while (true) {
			mid = (top + bot) >> 1;
			if (mid == bot)
				break;
			if (2.0 * mid * mid + (2.0 * r - 1) * mid - t < eps)
				bot = mid;
			else
				top = mid - 1;
		}
//		printf("%lld %lld\n", r, t);
//		double ans = (sqrt((2.0 * r - 1) * (2.0 * r - 1) + 8.0 * t) - (2.0 * r - 1)) / 4.0;
//		printf("%.6lf\n", ans);
		printf("Case #%d: ", Case);
    if (2.0 * top * top + (2.0 * r - 1) * top - t < eps)
		  printf("%d\n", top);
		else
			printf("%d\n", bot);
	}
	return 0;
}
