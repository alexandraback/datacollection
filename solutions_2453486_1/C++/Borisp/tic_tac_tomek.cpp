#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

bool checkBoard(const vector<string>& board, char c)
{
	int steps[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
	int initialPositions[10][3] = {{0, 0, 0}, {0, 1, 0}, {0, 2, 0}, {0, 3, 0},
								   {0, 0, 1}, {1, 0, 1}, {2, 0, 1}, {3, 0, 1},
								   {0, 0, 2},
	                               {0, 3, 3}};

	for (int i = 0; i < 10; i++)
	{
		int x = initialPositions[i][0];
		int y = initialPositions[i][1];
		bool does = true;
		for (int j = 0; j < 4; j++)
		{
			if (board[x][y] != c && board[x][y] != 'T')
			{
				does = false;
				break;
			}
			x += steps[initialPositions[i][2]][0];
			y += steps[initialPositions[i][2]][1];
		}
		if (does) 
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);

		vector<string> board;
		string str;
		for (int i = 0; i < 4; i++)
		{
			cin >> str;
			board.push_back(str);
		}
		if (checkBoard(board, 'X'))
		{
			cout << "X won" << endl;
		} else if (checkBoard(board, 'O'))
		{
			cout << "O won" << endl;
		} else {
			bool filled = true;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (board[i][j] == '.')
					{
						filled = false;
						break;
					}
				}
			}
			if (filled)
			{
				cout << "Draw" << endl;
			} else
			{
				cout << "Game has not completed" << endl;
			}
		}
	}
	return 0;
}
