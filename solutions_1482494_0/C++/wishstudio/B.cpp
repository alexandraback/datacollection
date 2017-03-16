#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxN 1010

using namespace std;

int a[maxN], b[maxN];
int earned[maxN];

int main()
{
	int T;
	scanf("%d", &T);
	for (int z = 1; z <= T; z++)
	{
		int N;
		memset(earned, 0, sizeof earned);
		int E = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d %d", &a[i], &b[i]);
		int ans = 1;
		for (;; ans++)
		{
			int m = 0, mi = -1;
			for (int i = 0; i < N; i++)
			{
				int e = 0;
				if (b[i] <= E)
					e = max(e, 2 - earned[i]);
				else if (a[i] <= E)
					e = max(e, 1 - earned[i]);
				if (e > 0 && e >= m)
					if (e == 2 || mi == -1 || (m == 1 && ((earned[mi] == 0 && earned[i] == 1) || (earned[mi] == earned[i] && b[i] > b[mi]))))
					{
						m = e;
						mi = i;
					}
			}
			if (mi == -1)
				break;
			if (b[mi] <= E)
				earned[mi] = 2;
			else
				earned[mi] = 1;
			E += m;
			if (E == 2 * N)
				break;
		}
		printf("Case #%d: ", z);
		if (E == 2 * N)
			printf("%d\n", ans);
		else
			puts("Too Bad");
	}
	return 0;
}
