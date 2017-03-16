#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int mat[60][60];


int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int tcase = 1; tcase <= T; ++tcase)
	{
		memset(mat, 0, sizeof(mat));
		int B;
		LL M, LIM = 1;
		scanf("%d%lld", &B, &M);
		LIM <<= (B - 2);
		if (M > LIM)
		{
			printf("Case #%d: IMPOSSIBLE\n", tcase);
			continue;
		}
		//1 - B
		//construct
		int i, j;
		for (i = 2; i <= B; ++i)
			for (j = i + 1; j <= B; ++j)
				mat[i][j] = 1;
		LL bit = 1;
		for (j = B - 1; j >= 2; --j)
		{
			if (M & bit)
				mat[1][j] = 1;
			bit <<= 1;
		}
		if (M == LIM)
		{
			for (j = 2; j <= B; ++j)
				mat[1][j] = 1;
		}
		printf("Case #%d: POSSIBLE\n", tcase);
		for (i = 1; i <= B; ++i)
		{
			for (j = 1; j <= B; ++j)
				printf("%d", mat[i][j]);
			printf("\n");
		}
	}

	return 0;
}
