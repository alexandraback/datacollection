#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

int T, N, M;
char lawn[100][100];

bool allUnderColumn(int column, int value)
{
	for(int i = 0; i < N; i++)
		if(lawn[i][column] > value) return false;
	return true;
}

bool allUnderRow(int row, int value)
{
	for(int i = 0; i < M; i++)
		if(lawn[row][i] > value) return false;
	return true;
}

bool naiveSolution()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(allUnderColumn(j, lawn[i][j]) == false
				&& allUnderRow(i, lawn[i][j]) == false)
				return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d", &T);

	for(int c = 1; c <= T; c++)
	{
		scanf("%d %d", &N, &M);

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				scanf("%d", &lawn[i][j]);
			}
		}
		printf("Case #%d: %s\n", c, naiveSolution() ? "YES":"NO");
	}


	return 0;
}
