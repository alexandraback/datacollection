#include <cstdio>

void Open()
{
	freopen ("P1.in", "r", stdin);
	freopen("P1.out", "w", stdout);
}

void Close()
{
	fclose(stdin);
	fclose(stdout);
}

char board[4][4];

int Judge(const int start[2], const int step[2])
{
	char s[2] = {'X', 'O'};
	for (int k = 0; k < 2; k++)
	{
		int x = start[0], y = start[1];
		int tmp = 0;
		for (; tmp < 4; x += step[0], y+= step[1], tmp++)
			if (board[x][y] != s[k] && board[x][y] != 'T')
				break;
		if (tmp == 4) return k;
	}
	return 2;
}

void Run()
{
	int N;
	bool filled;
	scanf ("%d\n", &N);

	int allstart[][2] = {{0,0},{0,1},{0,2},{0,3},{0,0},{1,0},{2,0},{3,0},{0,0},{0,3}};
	int allstep[][2] = {{1,0},{1,0},{1,0},{1,0},{0,1},{0,1},{0,1},{0,1},{1,1},{1,-1}};
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < 4; k++)
			scanf ("%s\n", board[k]);
		filled = true;
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				if (board[x][y] == '.') 
				{
					filled = false;
					break;
				}
		int result;
		for (int k = 0; k < 10; k++)
		{
			result = Judge(allstart[k], allstep[k]);
			if (result != 2) break;
		}

		if (result == 2)
		{
			if (filled)
				printf ("Case \#%d: Draw\n", i+1);
			else
				printf ("Case \#%d: Game has not completed\n", i+1);
		}
		else
		{
			if (result == 0)
				printf ("Case \#%d: X won\n", i+1);
			else
				printf ("Case \#%d: O won\n", i+1);
		}
	}
}

int main()
{
	Open();
	Run();
	Close();
	return 0;
}