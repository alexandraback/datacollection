//============================================================================
// Name        : B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 2000;
const int inf = 2147483647/2;
int a[maxn], b[maxn];
int c[maxn];

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int casenum=1; casenum <= T; ++casenum)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d %d", &a[i], &b[i]);
		memset(c, 0, sizeof(c));
		int now = 0, cost = 0;
		while (true)
		{
			int bestid = -1, bestC = 2;
			for (int i = 1; i <= n; ++i)
				if (c[i] < 2 && now >= b[i])
				{
					if (c[i] < bestC)
					{
						bestid = i;
						bestC = c[i];
					}
				}
			if (bestid != -1)
			{
				cost++; now += 2 - c[bestid]; c[bestid] = 2;
			} else
			{
				bestC = 0;
				bestid = -1;
				for (int i = 1; i <= n; ++i)
					if (c[i] == 0 && now >= a[i])
					{
						if (b[i] > bestC)
						{
							bestC = b[i];
							bestid = i;
						}
					}
				if (bestid == -1)
					break;
				c[bestid] = 1;
				cost++;
				now++;
			}
		}
		bool ok = true;
		for (int i = 1; i <= n; ++i)
			if (c[i] != 2)
			{
				ok = false; break;
			}
		printf("Case #%d: ", casenum);
		if (ok)
			printf("%d\n", cost);
		else printf("Too Bad\n");
	}
	return 0;
}
