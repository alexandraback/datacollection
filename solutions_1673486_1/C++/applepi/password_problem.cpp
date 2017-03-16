#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

double p[100010];
double lgp[100010], mul[100010];

int main ()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t; scanf("%d", &t);
	for (int k = 1; k <= t; k++)
	{
		int a, b; scanf("%d %d", &a, &b);
		for (int i = 1; i <= a; i++)
		{
			scanf("%lf", &p[i]);
			lgp[i] = log(p[i]);
		}
		mul[0] = 0;
		for (int i = 1; i <= a; i++) mul[i] = mul[i - 1] + lgp[i];
		double res = b + 2;
		for (int i = 0; i <= a; i++)
		{
			int cor = a - i;
			double rp = exp(mul[cor]);
			res = min(res, 2 * i - a + (b + 1) * (2 - rp));
		}
		printf("Case #%d: %.6f\n", k, res);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
