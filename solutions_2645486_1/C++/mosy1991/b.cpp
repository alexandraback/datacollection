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
map <int, pair<LL, LL> > mat;

bool cmp(node p, node q)
{
	return (p.v > q.v || p.v == q.v && p.id < q.id);
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
		sort(f + 1, f + n + 1, cmp);
		mat.clear();
		mat[0] = make_pair(0LL, LL(e));
		mat[n + 1] = make_pair(0LL, 0LL);
		for (int i = 1; i <= n; ++i)
		{
			int val = f[i].v;
			int idx = f[i].id;
			map <int, pair<LL, LL> >::iterator iter = mat.lower_bound(idx);
			LL valpos = iter->first;
			LL idxpos = iter->second.first;
			iter--;
			LL valpre = iter->first;
			LL idxpre = iter->second.second;
			LL pre = min(LL(e), LL(idxpre) + LL(idx - valpre) * r);
			LL pos = max(0LL, LL(idxpos) - LL(valpos - idx) * r);
			pos = min(pre, pos);
			ans += (pre - pos) * val;
			mat[i] = make_pair(pre, pos);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
