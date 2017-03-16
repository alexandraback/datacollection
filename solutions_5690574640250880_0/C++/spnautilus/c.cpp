#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN (64)

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;

int T;

char B[MAXN][MAXN];

int main()
{
	scanf("%d", &T);
	for(int tt = 1; tt <= T; ++tt)
	{
		int i, j;

		int R, C, M;
		scanf("%d %d %d", &R, &C, &M);
		int F = R * C - M;

		int transpose = 0;
		if(R > C)
		{
			swap(R, C);
			transpose = 1;
		}

		// assume R <= C
		int impossible = 0;

		if(F == 1)
		{
			for(i = 0; i < R; ++i)
			{
				for(j = 0; j < C; ++j)
					B[i][j] = '*';
			}
		}
		else if(R == 1)
		{
			for(j = 1; j < F; ++j)
				B[0][j] = '.';
			for(; j < C; ++j)
				B[0][j] = '*';
		}
		else if(R == 2)
		{
			if(F % 2 == 0 && F >= 4)
			{
				for(j = 0; j < F/2; ++j)
					B[0][j] = B[1][j] = '.';
				for(; j < C; ++j)
					B[0][j] = B[1][j] = '*';
			}
			else
				impossible = 1;
		}
		else // R >= 3
		{
			for(i = 0; i < R; ++i)
			{
				for(j = 0; j < C; ++j)
					B[i][j] = '*';
			}

			int later = 0;

			if(F & 1) // odd
			{
				if(F < 9)
					impossible = 1;
				else if(F > 2 * C + 3)
					later = 1;
				else
				{
					int c = (F - 3) / 2;
					B[2][0] = B[2][1] = B[2][2] = '.';
					for(i = 0; i < c; ++i)
						B[0][i] = B[1][i] = '.';
				}
			}
			else // even
			{
				if(F < 4)
					impossible = 1;
				else if(F > 2 * C)
					later = 1;
				else
				{
					int c = F / 2;
					for(i = 0; i < c; ++i)
						B[0][i] = B[1][i] = '.';
				}
			}

			if(later)
			{
				int r = F / C;
				int a = F % C;

				for(i = 0; i < r; ++i)
				{
					for(j = 0; j < C; ++j)
						B[i][j] = '.';
				}
				for(j = 0; j < a; ++j)
					B[r][j] = '.';

				if(a == 1)
				{
					B[r][1] = '.'; // make that row have 2 dots
					B[r - 1][C - 1] = '*'; // borrow
				}
			}
		}

		printf("Case #%d:\n", tt);

		if(impossible)
			printf("Impossible\n");
		else
		{
			B[0][0] = 'c';

			if(!transpose)
			{
				for(i = 0; i < R; ++i)
					printf("%s\n", B[i]);
			}
			else
			{
				for(i = 0; i < C; ++i)
				{
					for(j = 0; j < R; ++j)
						putchar(B[j][i]);
					putchar('\n');
				}
			}
		}

		memset(B, 0, sizeof(B));
	}

	return 0;
}
