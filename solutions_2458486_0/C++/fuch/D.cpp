#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <functional>

#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define ass(v) (v)||++*(int*)0;

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<double> VD;

int n, k;
VI a;
vector<VI> b;
VB ok;
int keys[200];

void dfs(int state, int p)
{
	if (p < n)
	{
		dfs(state, p + 1);
		foreach(it, b[p]) --keys[*it];
		++keys[a[p]];
		dfs(state | (1 << p), p + 1);
		foreach(it, b[p]) ++keys[*it];
		--keys[a[p]];
		return;
	}

	if (!ok[state]) return;

	for (int i = 0; i < n; ++i)
	{
		if (state & (1 << i)) continue;
		if (ok[state | (1 << i)]) continue;
		bool flag = true;
		foreach(it, b[i])
		{
//			printf("key=%d %d\n", *it, keys[*it]);
			if (--keys[*it] < 0) flag = false;
		}
		foreach(it, b[i])
		{
			++keys[*it];
		}
//		printf("state=%d i=%d flag=%d\n", state, i, flag);
		if (flag)
		{
			ok[state | (1 << i)] = true;
		}
	}
}

void solve()
{
	ok.clear();
	ok.resize(1 << n);
	ok[0] = true;
	for (int i = 0; i < n; ++i)
	{
		--keys[a[i]];
		foreach(it, b[i]) ++keys[*it];
	}
//	printf("%d,%d\n", keys[0], keys[1]);
	dfs(0, 0);

	if (!ok[(1 << n) - 1])
	{
		puts(" IMPOSSIBLE");
		return;
	}

	int curr = (1 << n) - 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((curr & (1 << j)) == 0) continue;
			if (ok[curr & ~(1 << j)])
			{
				printf(" %d", j + 1);
				curr &= ~(1 << j);
				break;
			}
		}
	}
	puts("");
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		scanf("%d%d", &k, &n);
		memset(keys, 0, sizeof(keys));
		for (int i = 0; i < k; ++i)
		{
			int t;
			scanf("%d", &t);
			//printf("t=%d\n", t);
			++keys[t - 1];
		}
		a.resize(n);
		b.resize(n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			--a[i];
			int m;
			scanf("%d", &m);
			b[i].resize(m);
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &b[i][j]);
				--b[i][j];
			}
		}
		printf("Case #%d:", cs);
		solve();
	}
	return 0;
}
