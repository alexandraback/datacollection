#include <cstdio>
#include <queue>

using namespace std;

int T;
int R, C, M;
int zeroCount;
char mines[50][50];

void init()
{
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			mines[i][j] = 0;
		}
	}
}

void addCount(int r, int c)
{
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			if(i == 0 && j == 0) continue;
			if(r+i < 0 || r+i >= R || c+j < 0 || c+j>=C) continue;
			if(mines[r+i][c+j] == -1) continue;
			mines[r+i][c+j]++;
		}
	}
}

void fillConnectedZeroToMinusTwo(int r, int c)
{
	if(r < 0 || r >= R || c < 0 || c >= C) return;
	if(mines[r][c] != 0) return;
	mines[r][c] = -2;
	fillConnectedZeroToMinusTwo(r-1, c);
	fillConnectedZeroToMinusTwo(r+1, c);
	fillConnectedZeroToMinusTwo(r, c-1);
	fillConnectedZeroToMinusTwo(r, c+1);
}

bool allZeroConnected(int r,int c)
{
	fillConnectedZeroToMinusTwo(r, c);
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(mines[i][j] == 0) return false;
		}
	}
	return true;
}

bool hasZeroNeighbor(int r, int c)
{
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			if(i == 0 && j == 0) continue;
			if(r+i < 0 || r+i >= R || c+j < 0 || c+j>=C) continue;
			if(mines[r+i][c+j] == 0) return true;
		}
	}
	return false;
}

bool check()
{
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(mines[i][j] == -1) continue;
			mines[i][j] = 0;
		}
	}

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(mines[i][j] == -1)
			{
				addCount(i, j);
			}
		}
	}


	zeroCount = 0;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(mines[i][j] == 0) zeroCount++;
		}
	}

	if(zeroCount == 0) return C*R-1 == M;

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(mines[i][j] > 0 && hasZeroNeighbor(i, j) == false) return false;
		}
	}

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(mines[i][j] != 0) continue;
			return allZeroConnected(i, j);
		}
	}
	return false;
}

bool solve(int r, int c, int remineMine)
{
	if(remineMine == 0){
		return check();
	}
	if(c == C) return solve(r+1, 0, remineMine);
	if(r == R) return false;

	bool result = solve(r, c+1, remineMine);
	if(result) return result;
	mines[r][c] = -1;
	result = solve(r, c+1, remineMine-1);
	if(result) return result;
	mines[r][c] = 0;
	return false;
}

int main()
{
	scanf("%d", &T);
	for(int Case = 1; Case <= T; Case++)
	{
		printf("Case #%d:\n", Case);
		scanf("%d %d %d", &R, &C, &M);
		init();
		if(solve(0, 0, M)) {
			bool printClick = false;
			for(int i = 0; i < R; i++) {
				for(int j = 0; j < C; j++) {
					if(mines[i][j] > 0){
						if(zeroCount == 0 && printClick == false) putchar('c');
						else putchar('.');
					}
					else if(mines[i][j] == -1) putchar('*');
					else if(mines[i][j] < -1) {
						putchar(printClick ? '.' : 'c');
						printClick = true;
					}
				}
				putchar('\n');
			}
		}
		else
		{
			puts("Impossible");
		}
	}
	return 0;
}

