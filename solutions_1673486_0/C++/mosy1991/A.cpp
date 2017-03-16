#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100005
int n, m;
double p[MAXN];
double f[MAXN];

double cal()
{
	f[0] = p[0];
	for (int i = 1; i < n; ++i)
		f[i] = f[i - 1] * p[i];
	double step = f[n - 1] * (m - n + 1) + (1 - f[n - 1]) * (m - n + 1 + m + 1);
//	cout << step << m + 2 << endl;
	if (m + 2 < step)
		step = m + 2;
	
	for (int i = 1; i <= n; ++i)
	{
		double tmp;
		if (n - i - 1 >= 0)
			tmp = f[n - i - 1];
		else tmp = 1;
		double step0 = tmp * (i + i + m - n + 1) + (1 - tmp) * (i + i + m - n + 1 + m + 1);
		if (step0 < step)
			step = step0;
	}

	return step;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int cases = 0, T;
	scanf("%d", &T);
	while (T--)
	{
		printf("Case #%d: ", ++cases);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%lf", &p[i]);
		printf("%.6lf\n", cal());
	}
	return 0;
}