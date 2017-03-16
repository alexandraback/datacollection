#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 222
#define EPS 1e-8
int N, A;
double D;
double a, ans;
double t[MAXN], x[MAXN];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, cases = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf%d%d", &D, &N, &A);
		for (int i = 0; i < N; ++i)
		{
			scanf("%lf%lf", &t[i], &x[i]);
		}
		
		
		printf("Case #%d:\n", ++cases);
		for (int i = 0; i < A; ++i)
		{
			ans = 0;
			scanf("%lf", &a);
			for (int j = 1; j < N; ++j)
			{
				double v = (x[j] - x[j - 1]) / (t[j] - t[j - 1]);
				double tt = (2 * v + sqrt(4 * v * v + 8 * x[j - 1] * a)) / 2 / a;
				//cout << tt << ' ' << t[1] << endl;
				if (t[j] - tt > EPS)
				{
					ans += sqrt((x[j] - x[j - 1]) * 2 / a);
				}
				else
				{
					double dt = 0.5 * a * t[j] * t[j];
					double tt = (D - dt) / (a * t[j]);
					ans += t[j] + tt;
				}
			}
			printf("%.8lf\n", ans);
		}
		
	}
	return 0;
}