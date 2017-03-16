//============================================================================
// Name        : Qual2013.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int T;
char board[5][5];

bool incomplete()
{
	for(int i = 0 ; i < 4 ; i++)
		for(int j = 0 ; j < 4 ; j++)
			if(board[i][j] == '.')
				return true;
	return false;
}

bool Xwon()
{
	int flag;
	for(int i = 0 ; i < 4 ; i++)
	{
		flag = 1;
		for(int j = 0 ; j < 4 ; j++)
			if(board[i][j] != 'X' && board[i][j] != 'T')
			{
				flag = 0;
				break;
			}
		if(flag) return true;
	}
	for(int i = 0 ; i < 4 ; i++)
	{
		flag = 1;
		for(int j = 0 ; j < 4 ; j++)
			if(board[j][i] != 'X' && board[j][i] != 'T')
			{
				flag = 0;
				break;
			}
		if(flag) return true;
	}
	flag = 1;
	for(int i = 0 ; i < 4 ; i++)
		if(board[i][i] != 'X' && board[i][i] != 'T')
		{
			flag = 0;
			break;
		}
	if(flag) return true;
	flag = 1;
	for(int i = 0 ; i < 4 ; i++)
		if(board[i][3-i] != 'X' && board[i][3-i] != 'T')
		{
			flag = 0;
			break;
		}
	if(flag) return true;
	return false;
}

bool Owon()
{
	int flag;
	for(int i = 0 ; i < 4 ; i++)
	{
		flag = 1;
		for(int j = 0 ; j < 4 ; j++)
			if(board[i][j] != 'O' && board[i][j] != 'T')
			{
				flag = 0;
				break;
			}
		if(flag) return true;
	}
	for(int i = 0 ; i < 4 ; i++)
	{
		flag = 1;
		for(int j = 0 ; j < 4 ; j++)
			if(board[j][i] != 'O' && board[j][i] != 'T')
			{
				flag = 0;
				break;
			}
		if(flag) return true;
	}
	flag = 1;
	for(int i = 0 ; i < 4 ; i++)
		if(board[i][i] != 'O' && board[i][i] != 'T')
		{
			flag = 0;
			break;
		}
	if(flag) return true;
	flag = 1;
	for(int i = 0 ; i < 4 ; i++)
		if(board[i][3-i] != 'O' && board[i][3-i] != 'T')
		{
			flag = 0;
			break;
		}
	if(flag) return true;
	return false;
}

int main()
{
	cin >> T;
	for(int i = 0 ; i < T ; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
			for(int k = 0 ; k < 4 ; k++)
				cin >> board[j][k];
		if(Xwon())
			cout << "Case #" << i + 1 << ": X won\n";
		else if(Owon())
			cout << "Case #" << i + 1 << ": O won\n";
		else if(incomplete())
			cout << "Case #" << i + 1 << ": Game has not completed\n";
		else
			cout << "Case #" << i + 1 << ": Draw\n";
	}
	return 0;
}

