#include <iostream>
#include <cstdio>
using namespace std;
#define N 4
int main()
{
	char State[][30] = {"X won", "O won", "Draw", "Game has not completed"};
	char map[N][N] = {'0'};
	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		bool empty = false;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '.')
					empty = true;
			}
		char state = '.';
		for (int i = 0; i < N; i++)
		{
			char winner = 'T';
			for (int j = 0; j < N && winner != '.'; j++)
				switch (map[i][j])
				{
				case '.':
					winner = '.';
					break;
				case 'T':
					break;
				case 'O':
					if (winner == 'X')
						winner = '.';
					else
						winner = 'O';
					break;
				case 'X':
					if (winner == 'O')
						winner = '.';
					else
						winner = 'X';
					break;
				}
			if (winner != '.')
			{
				state = winner;
				break;
			}
		}
		if (state == '.') for (int j = 0; j < N; j++)
		{
			char winner = 'T';
			for (int i = 0; i < N && winner != '.'; i++)
				switch (map[i][j])
				{
				case '.':
					winner = '.';
					break;
				case 'T':
					break;
				case 'O':
					if (winner == 'X')
						winner = '.';
					else
						winner = 'O';
					break;
				case 'X':
					if (winner == 'O')
						winner = '.';
					else
						winner = 'X';
					break;
				}
			if (winner != '.')
			{
				state = winner;
				break;
			}
		}
		if (state == '.')
		{
			char winner = 'T';
			for (int i = 0; i < N && winner != '.'; i++)
				switch (map[i][i])
				{
				case '.':
					winner = '.';
					break;
				case 'T':
					break;
				case 'O':
					if (winner == 'X')
						winner = '.';
					else
						winner = 'O';
					break;
				case 'X':
					if (winner == 'O')
						winner = '.';
					else
						winner = 'X';
					break;
				}
			if (winner != '.')
				state = winner;
		}
		if (state == '.')
		{
			char winner = 'T';
			for (int i = 0; i < N && winner != '.'; i++)
				switch (map[i][N-i-1])
				{
				case '.':
					winner = '.';
					break;
				case 'T':
					break;
				case 'O':
					if (winner == 'X')
						winner = '.';
					else
						winner = 'O';
					break;
				case 'X':
					if (winner == 'O')
						winner = '.';
					else
						winner = 'X';
					break;
				}
			if (winner != '.')
				state = winner;
		}
		char* ans = NULL;
		if (state == 'X')
			ans = State[0];
		else if (state == 'O')
			ans = State[1];
		else if (!empty)
			ans = State[2];
		else
			ans = State[3];
		printf("Case #%d: %s\n", t+1, ans);
	}
	return 0;
}

