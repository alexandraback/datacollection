#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


double eps = 1e-14;

bool Eq(double a, double b)
{
	return fabs(a - b) < eps;
}
bool Ls(double a, double b)
{
	return a < b && !Eq(a, b);
}
bool Gr(double a, double b)
{
	return a > b && !Eq(a, b);
}

struct H
{
	int s, t;
	H() : s(), t() {}
	H(int _s, int _t) : s(_s), t(_t) {}
	
	double getFinT() const
	{
		return (1. - s / 360.) * (double) t;
	}
	bool operator < (const H &A) const
	{
		return getFinT() < A.getFinT();
	}
	long long cnt(double et)
	{
		et -= getFinT();
		return 1 + (long long) (et / t + eps);
	}
};

vector <H> hs;

void solve()
{
	int n;
	scanf("%d", &n);
	hs.clear();

	for (int i = 0; i < n; i++)
	{
		int d, h, m;
		scanf("%d%d%d", &d, &h, &m);
		for (int j = 0; j < h; j++)
		{
			hs.push_back(H(d, m + j) );
		}
	}
	long long ans = (int) hs.size();
	sort(hs.begin(), hs.end() );
	for (int i = 0; i < (int) hs.size(); i++)
	{
		double t = hs[i].getFinT();
		long long cur = 0;
		for (int j = 0; j < (int) hs.size(); j++)
		{
			if (Gr(hs[j].getFinT(), t) )
				cur++;
			else
				cur += hs[j].cnt(t) - 1;
		}
//		eprintf("i = %d, cur = %lld, t = %.5lf\n", i, cur, t);
		ans = min(ans, cur);
	}
	printf("%lld\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		eprintf("Case %d .. %d\n", i, t);
		printf("Case #%d: ", i);
		solve();
	}
	

	return 0;
}
