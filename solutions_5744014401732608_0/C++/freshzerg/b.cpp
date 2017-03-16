#include <iostream>
#include <vector>
using namespace std;
long long B, M;
int mat[50][50];
int main()
{
	int T; cin >> T;
	for (int TT = 1; TT <= T; ++TT)
	{
		printf("Case #%d:", TT);
		cin >> B >> M;
		memset(mat, 0, sizeof(mat));
		for (int i = 0; i < B - 1; ++i)
		{
			for (int j = i + 1; j < B - 1; ++j)
			{
				mat[i][j] = 1;
			}
		}
		long long maxAns = 1ll << (B - 2);
		if (M > maxAns)
		{
			printf(" IMPOSSIBLE\n");
		}
		else
		{
			int ptr = 1;
			while (M)
			{
				if (M & 1ll)
				{
					if (ptr == B - 1)
					{
						for (int i = 0; i < B - 1; i++)
						{
							mat[i][B - 1] = 1;
						}
					}
					else mat[ptr][B - 1] = 1;
				}
				ptr++;
				M >>= 1;
			}
			printf(" POSSIBLE\n");
			for (int i = 0; i < B; ++i)
			{
				for (int j = 0; j < B; ++j)
				{
					printf("%d", mat[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}