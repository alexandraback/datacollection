#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define Maxn 100005
int n, m;
double p[Maxn], s[Maxn];

void Init()
{
	scanf("%d%d", &n, &m);
	s[0] = 1;
	rep(i, n)
	{
		scanf("%lf", p + i);
		s[i] = s[i - 1] * p[i];
	}
}

void Work(int ca)
{
	double ans = m + 2;
	rep(i, n)
	{
		double d;
		d = (n - i + m - i + 1) * s[i] + (n - i + m - i + 1 + m + 1) * (1 - s[i]);
		//printf("%.5lf\n", d);
		ans = min(ans, d);
	}
	printf("Case #%d: %.5lf\n", ca, ans);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	rep(ca, T)
	{
		Init();
		Work(ca);
	}
	return 0;
}