#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int oo = 0x3f3f3f3f;

const int maxn = 1000, maxabs = 1000;

int n;
int a[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	static int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case)
	{
		scanf("%d", &n);
		REP(i, 0, n) scanf("%d", a + i);
		int ans = oo;
		REP(i, 1, maxabs + 1)
		{
			int tmp = 0;
			REP(j, 0, n)
				if (a[j] > i) tmp += (a[j] - 1) / i;
			ans = min(ans, tmp + i);
		}
		printf("Case #%d: %d\n", Case, ans);
	}
	return 0;
}
