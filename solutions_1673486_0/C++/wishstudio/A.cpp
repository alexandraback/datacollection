#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxA 100000

using namespace std;

double p[maxA];
double g[maxA];

int main()
{
	int T;
	scanf("%d", &T);
	for (int z = 1; z <= T; z++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		for (int i = 1; i <= a; i++)
			scanf("%lf", &p[i]);
		g[0] = 1;
		for (int i = 1; i <= a; i++)
			g[i] = g[i - 1] * p[i];
		double best = b + 2;
		for (int i = 0; i <= a; i++)
		{
			best = min(best, a - i + g[i] * (b - i + 1) + (1 - g[i]) * (b - i + 1 + b + 1));
		}
		printf("Case #%d: %.8f\n", z, best);
	}
	return 0;
}
