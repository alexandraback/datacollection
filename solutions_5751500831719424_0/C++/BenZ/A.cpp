#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
struct edge{int a, l;};
const int maxN = 105;
const int maxL = 105;
int ca, n;
char s[maxN][maxL], p[maxN], l[maxN];
int a[maxN];

void init()
{
	scanf("%d", &n);
	rep(i, n)
	{
		scanf("%s", s[i]);
		l[i] = strlen(s[i]);
		p[i] = 0;
	}

}

void work(int ca)
{
	int ans = 0;
	while (p[1] < l[1])
	{
		char now = s[1][p[1]];

		rep(i, n)
		{
			if (s[i][p[i]] != now)
			{
				ans = -1;
				break;
			}
			a[i] = 0;
			while (s[i][p[i]] == now)
			{
				++a[i];
				++p[i];	
			}
		}

		if (ans == -1) break;

		sort(a + 1, a + 1 + n);
		rep(i, n) ans += abs(a[i] - a[(n + 1) / 2]);
	}

	rep(i, n) if (p[i] != l[i])
	{
		ans = -1;
	}

	if (ans == -1) printf("Case #%d: Fegla Won\n", ca);
	else printf("Case #%d: %d\n", ca, ans);
}

int main()
{
	scanf("%d", &ca);
	rep(t, ca)
	{
		init();
		work(t);
	}
	return 0;
}
