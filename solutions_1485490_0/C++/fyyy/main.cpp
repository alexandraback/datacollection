#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 128;

typedef long long LL;

LL a[N], A[N], b[N], B[N], qa[N], qb[N];
int n, m;

LL query(int l, int r)
{
	LL res = 0;
	int i;
	for (i = 0; i <= l; i++)
	{
		if (A[0] == B[i])
		{
			LL tmp = min(a[0], b[i]);
			res += tmp;
			a[0] -= tmp;
			b[i] -= tmp;
			if (a[0] <= 0)
				break;
		}
	}
	for (i = l; i < r; i++)
	{
		if (A[1] == B[i])
		{
			LL tmp = min(a[1], b[i]);
			res += tmp;
			a[1] -= tmp;
			b[i] -= tmp;
			if (a[1] <= 0)
				break;
		}
	}
	for (i = r; i < m; i++)
	{
		if (A[2] == B[i])
		{
			LL tmp = min(a[2], b[i]);
			res += tmp;
			a[2] -= tmp;
			b[i] -= tmp;
			if (a[2] <= 0)
				break;
		}
	}
	return res;
}

int main()
{
	int t;
	int l, r;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		LL ans = 0;
		memset(qa, 0, sizeof (qa));
		memset(a, 0, sizeof (a));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%lld %lld", qa + i, A + i);
		for (int i = 0; i < m; i++)
			scanf("%lld %lld", qb + i, B + i);
		if (n == 1)
		{
			ans = query(m - 1, m);
		}
		else if (n == 2)
		{
			for (int i = -1; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					a[j] = qa[j];
				for (int j = 0; j < m; j++)
					b[j] = qb[j];
				LL tmp = query(i, m);
				ans = max(ans, tmp);
			}
		}
		else
		{
			for (int l = -1; l < m; l++)
			{
				for (int r = m; r >= 0; r--)
				{
					for (int i = 0; i < n; i++)
						a[i] = qa[i];
					for (int i = 0; i < m; i++)
						b[i] = qb[i];
					LL tmp = query(l, r);
					ans = max(tmp, ans);
				}
			}
		}
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}
