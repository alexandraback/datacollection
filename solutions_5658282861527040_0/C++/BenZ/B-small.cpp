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
int ca, n, m, k;

void work(int ca)
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if ((i & j) < k) ++ans;
		}
	printf("Case #%d: %d\n", ca, ans);
}

int main()
{
	scanf("%d", &ca);
	rep(t, ca)
	{
		scanf("%d%d%d", &n, &m, &k);
		work(t);
	}
	return 0;
}
