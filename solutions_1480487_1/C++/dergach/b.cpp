#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

int T, N, i, j, k, t, sum;
pair <int, int> a[205];
double b[205];
double L, C, R, level, sum2;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		sum = 0;
		scanf("%d", &N);
		for(i = 0; i < N; i++)
		{
			scanf("%d", &a[i].first);
			a[i].second = i;
			sum += a[i].first;
		}
		sort(a, a + N);
		for(i = 0; i < N; i++)
		{
			L = 0.0;
			R = 1.0;
			for(j = 0; j < 150; j++)
			{
				C = (L + R) / 2;
				level = a[i].first + sum * C;
				sum2 = sum * (1.0 - C);
				for(k = 0; k < N; k++)
				{
					if(k == i) continue;
					if(a[k].first < level)
						sum2 -= level - a[k].first;
				}

				if(sum2 > 0)
					L = C;
				else
					R = C;
			}
			b[a[i].second] = C * 100;
		}

		printf("Case #%d:", t);
		for(i = 0; i < N; i++)
			printf(" %.6lf", b[i]);
		puts("");
	}
	return 0;
}