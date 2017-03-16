#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <map>
using namespace std;

int main()
{
	freopen("A-small-attempt3.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt, ii = 0;
	scanf("%d", &tt);
	while(tt--)
	{
		int n;
		scanf("%d", &n);
		int i;
		int J[205];
		int X = 0;
		for(i = 1; i <= n; i++)
		{
			scanf("%d", J + i);
			X += J[i];
		}
		ii++;
		printf("Case #%d:", ii);
		for(i = 1; i <= n; i++)
		{
			long double st = 0.0, end = 1.0;
			long double ans = 0.0;
			int it;
			for(it = 0; it < 400; it++)
			{
				long double t = (st + end) / 2.0;
				bool ok = true;
				long double poi = J[i] + X * t;
				long double rem = 0.0;
				int j;
				for(j = 1; j <= n; j++)
				{
					if(j == i) continue;
					if((poi - J[j]) / X > 1e-11)
					{
						rem += (poi - J[j]) / X;
					}
				}
				if(rem + 1e-11 + t < 1.0)
				{
					ok = false;
				}
				if(ok)
				{
					ans = t;
					end = t;
				}
				else
				{
					st = t;
				}
			}
			printf(" %.9lf", (double)(ans * 100.0));
		}
		printf("\n");
	}
	return 0;
}
