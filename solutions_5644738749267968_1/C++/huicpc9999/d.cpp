#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
double w1[1001], w2[1001];

int solve(double *a, double *b)
{
	int p1 = 0, p2 = 0, ans = 0;
	while (p1 < n && p2 < n)
	{
		if (a[p1] < b[p2])
		{
			p1++; p2++; ans++;	
		}	
		else
		{
			p2++;	
		}
	}
	return ans;
}

int main()
{
	//freopen("D-large.in", "r", stdin);
	//freopen("D-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%lf", &w1[i]);
		for (int i = 0; i < n; ++i) scanf("%lf", &w2[i]);
		sort(w1, w1+n);
		sort(w2, w2+n);
		printf("Case #%d: %d %d\n", cas, solve(w2, w1), n-solve(w1, w2));
	}
	return 0;
}
