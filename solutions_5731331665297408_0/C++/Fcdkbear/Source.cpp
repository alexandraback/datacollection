#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_map>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

int st[15];
int res[10];
int now[10];
int val[10];
int n;
vector<vector<int> > g;
void r(int mask, int top, int cnt, int sm)
{
	if (cnt == n)
	{
		int val = 0;
		bool f = true;
		FOR(i, 0, n)
		{
			if ((now[i] > res[i]))
			{
				f = false;
				break;
			}
			if (now[i] < res[i])
				break;
		}
		if (!f)
			return;
		FOR(i, 0, n)
			res[i] = now[i];
		return;
	}
	int v = st[top];
	if (top > 0)
	{
		r(mask, top - 1, cnt, sm);
		st[top] = v;
	}
	FOR(i, 0, g[v].size())
	{
		int to = g[v][i];
		if ((mask >> to) & 1)
			continue;
		int nmask = mask;
		nmask |= (1 << to);
		if ((val[to] > res[cnt]) && (sm==0))
			continue;
		int nsm = sm;
		if (val[to] < res[cnt])
			nsm = 1;
		now[cnt] = val[to];
		st[top + 1] = to;
		r(nmask, top + 1, cnt + 1,nsm);
	}
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif

	int t;
	scanf("%d", &t);
	FOR(it, 1, t + 1)
	{
		int m;
		scanf("%d%d", &n, &m);
		FOR(i, 0, n)
			scanf("%d", &val[i]);
		g.clear();
		g.resize(n);
		FOR(i, 0, m)
		{
			int v1, v2;
			scanf("%d%d", &v1, &v2);
			v1--;
			v2--;
			g[v1].push_back(v2);
			g[v2].push_back(v1);
		}
		FOR(i, 0, n)
			res[i] = 99999;
		FOR(i, 0, n)
		{
			int mask = (1 << i);
			if (val[i] > res[0])
				continue;
			int sm = 0;
			if (val[i] < res[0])
				sm = 1;
			now[0] = val[i];
			st[0] = i;
			r(mask, 0, 1, sm);
		}
		printf("Case #%d: ", it);
		FOR(i, 0, n)
			printf("%d", res[i]);
		printf("\n");
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
}