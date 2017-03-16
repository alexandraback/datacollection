// GCJ2013R1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

int T;
vector<string> board;

void init()
{
	cin >> T;
	board.resize(4);
}

bool check(char x1, char x2, char x3, char x4, char judge)
{
	if (judge == x1 || x1 == 'T')
		if (judge == x2 || x2 == 'T')
			if (judge == x3 || x3 == 'T')
				if (judge == x4 || x4 == 'T')
				{
					return true;
				}
	return false;
}

void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		for (int i=0; i<4; i++)
		{
			cin >> board[i];
		}

		cout << "Case #" << ca << ": ";
		bool finish = true;
		bool win = false;
		for (int i=0; i<4; i++)
		{
			if (check(board[i][0], board[i][1], board[i][2], board[i][3], 'X') || 
				check(board[0][i], board[1][i], board[2][i], board[3][i], 'X'))
			{
				cout << "X won";
				win = true;
				break;
			}
			if (check(board[i][0], board[i][1], board[i][2], board[i][3], 'O') || 
				check(board[0][i], board[1][i], board[2][i], board[3][i], 'O'))
			{
				cout << "O won";
				win = true;
				break;
			}
			for (int j=0; j<4; j++)
			{
				if (board[i][j] == '.')
				{
					finish = false;
					break;
				}
			}
		}
		if ((!win) && (check(board[0][0], board[1][1], board[2][2], board[3][3], 'X') || 
			check(board[0][3], board[1][2], board[2][1], board[3][0], 'X')))
		{
			cout << "X won";
			win = true;
		}
		if ((!win) && (check(board[0][0], board[1][1], board[2][2], board[3][3], 'O') || 
			check(board[0][3], board[1][2], board[2][1], board[3][0], 'O')))
		{
			cout << "O won";
			win = true;
		}
		if (!win)
		{
			if (finish)
			{
				cout << "Draw";
			}
			else
			{
				cout << "Game has not completed";
			}
		}
		cout << endl;
	}
}

int main()
{
	freopen("c:\\backup\\A-large.in", "r", stdin);
	freopen("c:\\backup\\A-large.out", "w", stdout);
	init();
	work();

	return 0;
}

