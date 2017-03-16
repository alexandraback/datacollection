#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
#define eps 1e-9
double C, F, X;


int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T; cin >> T;
	for (int Cas = 1; Cas <= T; ++Cas)
	{
		scanf("%lf%lf%lf", &C, &F, &X);
		double ans = 1e15;
		double t = 0, rest = 0;
		double speed = 2.0;
		if (X <= C) ans = X / 2.0;
		else
		{
			int k = 0;
			while (true) {
				double t1 = t + X / speed;
				double t2 = t + C / speed + X / (speed + F);
				ans = min(ans, min(t1, t2));
				if (t2 < t1-eps)
				{
					t += C / speed;
					++k;
					speed = 2.0+k*F;
				}
				else break;
			}
		}
		printf("Case #%d: %.8lf\n", Cas, ans);
	}
}