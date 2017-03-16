#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T;
int N;
int M;
int table[100][100];
int case_index;

bool row_ok(int i, int j)
{
	int item = table[i][j];

	for (int x = 0; x < N; ++x)
	{
		if (item < table[x][j])
			return false;
	}
	return true;
}

bool col_ok(int i, int j)
{
	int item = table[i][j];

	for (int x = 0; x < M; ++x)
	{
		if (item < table[i][x])
			return false;
	}
	return true;
}

bool solvable()
{
	if (N == 1 || M == 1)
		return true;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!row_ok(i, j) &&
				 !col_ok(i, j))
				 return false;
		}
	}
	return true;
}

void do_case() 
{
	if (solvable())
		printf("Case #%d: YES\n", case_index + 1);
	else
		printf("Case #%d: NO\n", case_index + 1);
}

int main() 
{
	cin >> T;
	for (case_index = 0; case_index < T; ++case_index)
	{
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> table[i][j];
			}
		}
	/*	for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				printf("%d ", table[i][j]);
			}
			printf("\n");
		}*/
		do_case();
		//printf("\n");
	}

	return 0;
}