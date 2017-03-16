#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main ()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int kase; scanf("%d", &kase); for (int _ = 1; _ <= kase; ++_)
	{
		double C, F, X;
		scanf("%lf %lf %lf", &C, &F, &X);
		double adder = 0, ans = X / 2;
		for (int k = 1; ; k++)
		{
			adder += C / (2 + F * (k - 1));
			double tt = adder + X / (2 + F * k);
			if (tt < ans) ans = tt;
			else break;
		}
		printf("Case #%d: %.7f\n", _, ans);
	}
}
