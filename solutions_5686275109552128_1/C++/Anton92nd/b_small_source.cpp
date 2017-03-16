#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int maxN = 1010;

int p[maxN], d;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		scanf("%d", &d);
		int maxH = 0;
		for (int i = 0; i < d; i++)
		{
			scanf("%d", &p[i]);
			maxH = max(maxH, p[i]);
		}
		int best = maxH;
		for (int h = 1; h < maxH; h++)
		{
			int curAns = 0;
			for (int j = 0; j < d; j++)
			{
				if (p[j] > h)
				{
					curAns += p[j] / h - (p[j] % h == 0);
				}
			}
			best = min(best, curAns + h);
		}
		printf("Case #%d: %d\n", q + 1, best);
	}
	return 0;
}
