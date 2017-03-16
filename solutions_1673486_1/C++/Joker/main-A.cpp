#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int k=1; k<=T; ++k)
	{
		double a, b, p, res;
		scanf("%lf%lf", &a, &b);

		res = b+2;
		double prod = 1.0;
		for (int i=1; i<=(int)a; ++i)
		{
			double tmp;
			scanf("%lf", &tmp);

			prod *= tmp;

			tmp = (prod*(b-i+1))+(1-prod)*(2*b+2-i)+a-i;
			if (tmp <= res) res = tmp;
		}

		printf("Case #%d: %.6f\n", k, res);
	}

	return 0;
}
