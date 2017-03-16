#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 1001
#define eps 1e-12

int n;
int a[MAXN];
double x;

inline bool check(int ind, double p)
{
	double score = a[ind] + x * p;
	double need = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i == ind) continue;
		if (score - a[i] < 0) continue;
		need += (score - a[i] + eps) / x;
	}
	return need > 1 - p;
}

inline void solve(int cas)
{
	x = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		x += a[i];
	}
	printf("Case #%d: ", cas + 1);
	for (int i = 0; i < n; ++i)
	{
		double l = 0, r = 1;
		while(l + eps < r)
		{
			double m = (l + r) / 2.0;
			if (check(i, m))
				r = m;
			else
				l = m;
		}
		printf("%.15lf%c", r * 100, " \n"[i + 1 == n]);
	}
}

int main()
{
	int tt;
   scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
	{
		solve(t);
	}
	return 0;
}
