#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

#pragma comment(linker,"/STACK:100000000")

int use[2000500];
int a[30];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T, tt;
	scanf("%d", &T);
	for (tt = 0; tt < T; ++tt)
	{
		int n;
		int i, j;
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		memset(use, 0, sizeof(use));
		printf("Case #%d:\n", tt + 1);
		for (i = 1; i < (1 << n); ++i)
		{
			int sum = 0;
			for (j = 0; j < n; ++j)
				if ((i >> j)&1)
					sum += a[j];
			if (use[sum] > 0)
			{
				for (j = 0; j < n; ++j)
					if ((i >> j)&1)
						printf("%d ", a[j]);
				printf("\n");
				for (j = 0; j < n; ++j)
					if ((use[sum] >> j)&1)
						printf("%d ", a[j]);
				printf("\n");
				break;
			}
			use[sum] = i;
		}
		if (i == (1 << n))
			printf("Impossible\n");
	}
	return 0;
}