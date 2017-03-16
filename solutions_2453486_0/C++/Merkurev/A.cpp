#include <iostream>
using namespace std;

char f[5][5];

int solve()
{
	for (int i = 0; i < 4; i++)
		f[4][i] = f[i][i];

	for (int i = 0; i < 5; i++)
	{
		int cW = 3;
		for (int j = 0; j < 4; j++)
		{
			if (f[i][j] != 'T' && f[i][j] != 'O')
				cW &= 2;
			if (f[i][j] != 'T' && f[i][j] != 'X')
				cW &= 1;
		}
		if (cW)
			return cW;
	}
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	/*
	"X won" (the game is over, and X won) 
	"O won" (the game is over, and O won) 
	"Draw" (the game is over, and it ended in a draw) 
	"Game has not completed" (the game is not over yet)

	*/

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		printf("Case #%d: ", t + 1);
		int winner = 0;
		for (int i = 0; i < 4; i++)
			scanf("%s", f[i] );

		winner |= solve();

		for (int i = 0; i < 4; i++)
			for (int j = i + 1; j < 4; j++)
				swap(f[i][j], f[j][i] );
		for (int i = 0; i < 4; i++)
			reverse(f[i], f[i] + 4);

		winner |= solve();

		if (winner == 3)
			throw 42;
		if (winner == 1)
		{
			printf("O won");
		}
		if (winner == 2)
		{
			printf("X won");
		}
		if (winner == 0)
		{
			bool draw = true;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (f[i][j] == '.')
						draw = false;
			if (draw)
				printf("Draw");
			else
				printf("Game has not completed");
		}
		printf("\n");
	}

	return 0;
}