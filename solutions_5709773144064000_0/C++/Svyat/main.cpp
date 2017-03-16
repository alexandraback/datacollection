#include <iostream>
#include <stdio.h>
using namespace std;

int T;
const double eps = 1e-8;

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		double c, f, x;
		cin >> c >> f >> x;
		double res = 0;
		double v = 1e9;
		int k = 0;
		while (v + eps > res + x / (2 + k * f))
		{
			v = min(v, res + x / (2 + k * f));
			res += c / (2 + k * f);
			++k;
		}
		printf("Case #%d: %.7lf\n", i, v);
		fflush(stdout);
	}
	return 0;
}