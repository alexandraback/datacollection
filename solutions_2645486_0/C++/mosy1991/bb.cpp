#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long LL;

#define MAXN 10005

struct node
{
	int v, id;
};

node f[MAXN];
int e, r, n;
LL ans;

bool cmp(node p, node q)
{
	return p.v > q.v;
}

void dfs(int k, LL tmp, int left)
{
	if (k > n)
	{
		if (tmp > ans)
			ans = tmp;
		return;
	}
	for (int i = 0; i <= left; ++i)
		dfs(k + 1, tmp + f[k].v * i, min(e, left - i + r));
}

int main()
{
	int T, cases = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &e, &r, &n);
		LL sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &f[i].v);
			f[i].id = i;
			sum += f[i].v;
		}
		printf("Case #%d: ", ++cases);
		ans = 0;
		if (e <= r)
		{
			ans = sum * e;
			printf("%lld\n", ans);
			continue;
		}
		dfs(1, 0, e);
		printf("%lld\n", ans);
	}
	return 0;
}
