#include <cstdio>
#include <cstring>

int R, C, M;
char Ans[51][51];

void Work()
{
	scanf("%d%d%d", &R, &C, &M);
	if (R == 1)
	{
		printf("c");
		for (int i = 0; i < C - M - 1; i ++)
			printf(".");
		for (int i = 0; i < M; i ++)
			printf("*");
		printf("\n");
		return;
	}
	if (C == 1)
	{
		printf("c\n");
		for (int i = 0; i < R - M - 1; i ++)
			printf(".\n");
		for (int i = 0; i < M; i ++)
			printf("*\n");
		return;
	}
	int Spc = R * C - M;
	if (Spc == 1)
	{
		for (int i = 0; i < R; i ++)
		{
			for (int j = 0; j < C; j ++)
				printf((i + j == 0) ? "c" : "*");
			printf("\n");
		}
		return;
	}
	for (int i = 0; i < R; i ++)
	{
		for (int j = 0; j < C; j ++)
			Ans[i][j] = '*';
		Ans[i][C] = 0;
	}
	int HaveSolution = 0;
	for (int i = 2; i <= R; i ++)
		for (int j = 2; j <= C; j ++)
			if (i * j >= Spc && (i + j) * 2 - 4 <= Spc)
			{
				HaveSolution = 1;
				for (int k = 0; k < i; k ++)
					Ans[k][0] = Ans[k][1] = '.';
				for (int k = 0; k < j; k ++)
					Ans[0][k] = Ans[1][k] = '.';
				int RemainSpc = Spc - ((i + j) * 2 - 4);
				for (int ii = 2; ii < i; ii ++)
					for (int jj = 2; jj < j; jj ++)
						if (Spc)
						{
							Ans[ii][jj] = '.';
							Spc --;
						}
			}
	if (HaveSolution)
	{
		Ans[0][0] = 'c';
		for (int i = 0; i < R; i ++)
			printf("%s\n", Ans[i]);
	}
	else
		printf("Impossible\n");
}

int main()
{
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
    int Cases;
    scanf("%d", &Cases);
    for (int Case = 1; Case <= Cases; Case ++)
    {
		printf("Case #%d:\n", Case);
		Work();
    }
    return 0;
}