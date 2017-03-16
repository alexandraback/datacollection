#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : (-(a)))
typedef long long int64;
const int maxN = 1000005;
int now, a[maxN], n;

void init()
{
	scanf("%d%d", &now, &n);
	rep(i, n) scanf("%d", a + i);
	sort(a + 1, a + 1 + n);
}

void work()
{
	int ans = 214748364, cnt = 0;
	if (now == 1)
	{
		printf("%d\n", n);
		return;
	}
	rep(i, n)
	{
		if (now <= a[i])
			ans = min(ans, cnt + (n - i + 1));
		while (now <= a[i])
		{
			now += now - 1;
			++cnt;
		}
		now += a[i];
	}
	ans = min(ans, cnt);
	printf("%d\n", ans);
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int ca;
	scanf("%d", &ca);
	rep(t, ca)
	{
		init();
		printf("Case #%d: ", t);
		work();
	}
	return 0;
}
