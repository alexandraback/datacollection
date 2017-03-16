#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<math.h>
using namespace std;


struct st 
{
	long long a, b, v;
	st(long long ae = 0, long long be = 0, long long ve = 0)
	{
		a = ae;
		b = be;
		v = ve;
	}

	bool operator< (const st& s) const
	{
		if(a != s.a)
			return a < s.a;
		
		return b < s.b;
	}
};

long long a[105][2] = {0};
long long b[105][2] = {0};
int n, m;


set<st > d[4][105];

long long dfs(int ia, long long ca, int ib, long long cb)
{
	if(ia == n || ib == m)
		return 0;

	set<st>::iterator it = d[ia][ib].lower_bound(st(ca, cb));

	if(it != d[ia][ib].end() && it->a == ca && it->b == cb)
		return it->v;


	long long mx = 0;


	if(a[ia][1] == b[ib][1])
	{
		long long t = 0;
		if(ca < cb)
			t = ca + dfs(ia + 1, a[ia+1][0], ib, cb - ca);
		else if(ca > cb)
			t = cb + dfs(ia, ca - cb, ib + 1, b[ib+1][0]);
		else
			t = cb + dfs(ia + 1, a[ia+1][0], ib + 1, b[ib+1][0]);
		if(t > mx)
			mx = t;
	}
	else
	{
	mx = dfs(ia+1, a[ia+1][0], ib, cb);
		long long tt = dfs(ia, ca, ib+1, b[ib+1][0]);
		if(tt > mx)
			mx = tt;

		d[ia][ib].insert(st(ca, cb, mx));
		
	}

	return mx;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	int tt;
	scanf("%d", &tt);

	for(int t = 0; t < tt; t++)
	{
		scanf("%d%d", &n,&m);


		for(int i = 0; i < n; i++)
		{
			scanf("%lld%lld", &a[i][0], &a[i][1]);
		}
		for(int i = 0; i < m; i++)
		{
			scanf("%lld%lld", &b[i][0], &b[i][1]);
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				d[i][j].clear();
			}
		}

		printf("Case #%d: %lld\n", t + 1, dfs(0, a[0][0], 0, b[0][0]));

	}

	return 0;
}


