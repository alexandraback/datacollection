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
int bo[10000005], q[10000005];
int s[10000005];

long long re(long long x)
{
	long long s = 0;
	while (x > 0)
	{
		s = s * 10 + (x % 10);
		x /= 10;
	}
	return s;
}

int p = 0;
void work()
{
	++p;
	long long x, y;
	int h, t;
	h = t = 0;
	q[++t] = 1; s[1] = 0; bo[1] = p;
	while (h != t)
	{
		x = q[++h];
		y = x + 1;
		if (y <= 10000000 && bo[y] != p)
		{
			s[y] = s[x] + 1;
			q[++t] = y; bo[y] = p;
		}

		y = re(x);
		if (y <= 10000000 && bo[y] != p)
		{
			s[y] = s[x] + 1;
			q[++t] = y; bo[y] = p;
		}
	}

}

int main()
{
	int t, ca;
	work();
	scanf("%d", &ca);
	rep(t, ca)
	{
		cin >> k;
		printf("Case #%d: %d\n", t, s[k] + 1);
	}
	return 0;
}
