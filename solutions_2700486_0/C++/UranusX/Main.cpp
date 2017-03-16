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
	double Ans = 0, Cur = 1;
	for (int i = 0; i <= R; i ++)
	{
		if (i != 0)
		{
			Cur *= (double) (R - i + 1);
			Cur /= (double) i;
		}
		if (i >= x)
		{
			Ans += Cur;
		}
		else
		{
			int an = R - i;
			if (an > P)
			{
				if (an - P + i >= x)
					Ans += Cur;
			}
		}
	}
	for (int i = 0; i < R; i ++)
		Ans *= 0.5;
	return Ans;
}

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);

	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
		printf("Case #%d: %.8lf\n", Case, Work());
	return 0;
}