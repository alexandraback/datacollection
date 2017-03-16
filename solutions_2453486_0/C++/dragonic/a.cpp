#include <cstdio>

const int N = 4;
char board[N][N];

const int VERDICT_DRAW = 0,
		  VERDICT_X_WON = 1,
		  VERDICT_O_WON = 2,
		  VERDICT_NOT_COMPLETED = 3;

const char* verdictToSring[] = { "Draw", "X won", "O won", "Game has not completed" };

bool wins (char c, int x, int y, int vx, int vy)
{
	for (int t = 0; t < 4; t++)
	{
		if (x < 0 || x >= 4 || y < 0 || y >= 4) return false;

		if (board[x][y] != c && board[x][y] != 'T') return false;

		x += vx;
		y += vy;
	}

	return true;
}

bool wins (char c)
{
	for (int x = 0; x < 4; x++)
		if (wins (c, x, 0, 0, 1))
			return true;

	for (int y = 0; y < 4; y++)
		if (wins (c, 0, y, 1, 0))
			return true;

	return wins (c, 0, 0, 1, 1) || wins (c, 3, 0, -1, 1);
}

int solve()
{
	if (wins ('X')) return VERDICT_X_WON;
	if (wins ('O')) return VERDICT_O_WON;

	bool gameOver = true;
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			if (board[x][y] == '.')
			{
				gameOver = false;
				break;
			}

	if (gameOver) return VERDICT_DRAW;
	return VERDICT_NOT_COMPLETED;
}

int main()
{
	int nTests;
	scanf ("%i", &nTests);

	for (int i = 0; i < nTests; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			char buffer[256];
			scanf ("%s", buffer);

			for (int x = 0; x < 4; x++)
				board[x][y] = buffer[x];
		}

		int answer = solve();
		printf ("Case #%i: %s\n", i + 1, verdictToSring[answer]);
	}

	return 0;
}