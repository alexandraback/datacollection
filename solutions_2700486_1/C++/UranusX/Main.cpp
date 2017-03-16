#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <iostream>
#include <functional>

using namespace std;

int N, X, Y;

int Abs(int x)
{
	return (x > 0) ? x : -x;
}

double Work()
{
	scanf("%d%d%d", &N, &X, &Y);
	int P = Abs(X) + Y;
	if ((P + 1) * (P + 2) / 2 <= N)
		return 1;
	if ((P - 1) * (P + 0) / 2 >= N)
		return 0;
	int R = N - (P - 1) * (P + 0) / 2;
	if (X == 0)
		return 0;

	int x = P - Abs(X) + 1;
	double Ans = 0, Cur = 0;
	for (int i = 0; i <= R; i ++)
	{
		if (i != 0)
			Cur += log((double) (R - i + 1)) - log((double) i);
		if (i >= x)
		{
			Ans += exp(Cur - R * log(2.0));
		}
		else
		{
			int an = R - i;
			if (an > P)
			{
				if (an - P + i >= x)
					Ans += exp(Cur - R * log(2.0));
			}
		}
	}
	return Ans;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
		printf("Case #%d: %.8lf\n", Case, Work());
	return 0;
}