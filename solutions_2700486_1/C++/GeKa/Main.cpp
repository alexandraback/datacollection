#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <memory.h>
#include <math.h>


using namespace std;

double CNM[3000][3000];

double power(double a, int n)
{
	double res = 1;
	double x = a;
	while (n > 0)
	{
		if (n % 2 == 1)
			res *= x;
		x *= x;
		n /= 2;
	}
	return res;
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	for (int i = 0; i < 3000; i++)
	{
		CNM[i][0] = 1;
		CNM[0][i] = 1;
	}
	for (int i = 1; i < 3000; i++)
		for (int j = 1; j < 3000; j++)
			CNM[i][j] = CNM[i-1][j]+CNM[i][j-1];

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int N, X, Y;
		scanf("%d%d%d", &N, &X, &Y);
		X = abs(X);
		int full = 0;
		while ( 2*(full + 1) * (full + 1) - (full+1) <= N)
			full++;
		int rest = N - (2*full * full - full);
		double res;
		int dist = 1 + (X+Y)/2;
		if (dist <= full)
			res = 1;
		else if (dist > full + 1)
			res = 0;
		else
		{			
			if (Y + 1 > rest)
				res = 0;
			else
			{
				int h = 2 * full;
				if (rest - h >= Y+1)
					res = 1;
				else
				{
					res = 1;
					double q = 0;
				
					double p = 1;
					for (int i = h - 1; rest - i < h && i >= 0; i--)
						p -= CNM[i][rest - i] * power(0.5, rest);
					p /= 2;

					for (int i = 0; i <= Y && i <= h; i++)
					{
						int left = rest - i;
						if (left > h)
							q += 0;
						else if (left == h && i == h)
						{
							q += p * 2;
						}
						else if (left == h || i == h)
						{
							q += p;
						}
						else
						{
							q += CNM[i][rest - i] * power(0.5, rest);
						}
					}
					res -= q;
				}
				
					
			}
		}
		printf("Case #%d: %.6lf\n", t+1, res);

	}

	return 0;
}