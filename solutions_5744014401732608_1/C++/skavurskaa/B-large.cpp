#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		long long B, M;
		scanf("%lld %lld", &B, &M);
		printf("Case #%d: ", t);
		if (M > 1LL<<(B-2)) printf("IMPOSSIBLE\n");
		else
		{
			int mat[55][55]; memset(mat,0,sizeof(mat));
			printf("POSSIBLE\n");

			if (M == 1LL<<(B-2))
				for (int j = 1; j < B; j++)
					mat[0][j] = 1;
			else
				for (int j = 0; j < B-1; j++)
					if (M & 1LL<<(j))
						mat[0][B-2-j] = 1;

			for (int i = 1; i < B; i++)
				for (int j = i+1; j < B; j++)
					mat[i][j] = 1;

			for (int i = 0; i < B; i++)
			{
				for (int j = 0; j < B; j++)
					printf("%d", mat[i][j]);
				printf("\n");
			}
		}
	}
}
