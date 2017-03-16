#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int T, N, S, P, a[200], f[200][200];

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t)
	{
		printf("Case #%d: ", t);
		scanf("%d%d%d", &N, &S, &P);
		for (int i = 1; i <= N; ++ i) scanf("%d", &a[i]);
		memset(f, -1, sizeof(f));
		f[0][0] = 0;
		for (int i = 0; i < N; ++ i)
			for (int j = 0; j <= S; ++ j)
				if (f[i][j] != -1)
				{
					if (a[i + 1] >= 2 && a[i + 1] <= 28 && j < S)
					{
						if (a[i + 1] >= 3 * P - 4)
							f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + 1);
						else	f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j]);
					}
					if (a[i + 1] >= 3 * P - 2)
						f[i + 1][j] = max(f[i + 1][j], f[i][j] + 1);
					else	f[i + 1][j] = max(f[i + 1][j], f[i][j]);
				}
		printf("%d\n", f[N][S]);
	}
	return 0;
}
						
