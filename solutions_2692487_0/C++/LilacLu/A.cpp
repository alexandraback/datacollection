#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define SMALL
//#define LARGE

using namespace std;

int t, a, n, ans;
int s[105];

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
  scanf("%d", &t);
	for (int Case = 1; Case <= t; ++Case) {
		printf("Case #%d: ", Case);
		scanf("%d %d", &a, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &s[i]);
		if (a == 1) {
			printf("%d\n", n);
			continue;
		}
    ans = n;
		sort(s, s + n);
		int temp = 0;
		for (int i = 0; i < n; ++i) {
			ans = min(temp + n - i, ans);
//			printf("%d %d\n", temp, ans);
			if (s[i] < a) {
				a += s[i];
				continue;
			}
			int m = ceil(log(s[i] * 1.0 / (a - 1)) / log(2));
      temp += m;
			m = (int)pow(2.0, m);
			a = a * m - (m - 1);
			a += s[i];
		}
//		printf("%d ", temp);
		printf("%d\n", min(temp, ans));
	}
	return 0;
}
