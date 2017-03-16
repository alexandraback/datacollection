#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int64;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
struct edge{int a, l;};
long long k;

long long calc(long long k)
{
	if (k < 10) return k;
	int a[30], t = 0;
	long long x = k, y;
	while (x > 0)
	{
		a[++t] = x % 10;
		x /= 10;
	}
	for (int i = 1; i <= (t + 1) / 2; ++i)
		if (i == 1) a[i] = 1;
			else a[i] = 0;

	x = y = 0;
	rep(i, t) x = x * 10 + a[i];
	zrp(i, t) y = y * 10 + a[i];

	if (k >= y && y > x) return calc(x) + k - y + 1;
	y = 1;

	zrp(i, t / 2 - 1) y = y * 10;
	if (k % y == 0 || k % y == 1) return calc(k - 1) + 1;

	y = 1;
	for (int i = t; i > 1; --i) y = y * 10;

	return calc(y - 1) + k - y + 1;

}

int main()
{
	int t, ca;
	scanf("%d", &ca);
	rep(t, ca)
	{
		cin >> k;
		cout << "Case #" << t << ": " << calc(k) << endl;
	}
	return 0;
}