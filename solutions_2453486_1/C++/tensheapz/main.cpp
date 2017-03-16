#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

string problemFile = "A-large";

//Globals
fstream input;
fstream output;
int CaseNum; //track what case # we are up to

//Declarations
void SolveInstance();

template <class T>
void LoadVector(vector<T>& v, int n) 
{
	int i, x;
	for (i = 0; i < n; ++i)
	{
		input >> x;
		v.push_back(x);
	}
}


int main()
{
	input.open(problemFile+".in", ios::in);
	output.open(problemFile+".out", ios::out);

	int T;
	input >> T;
	for (CaseNum = 1; CaseNum <= T; ++CaseNum)
	{
		SolveInstance();
	}

	return 0;
}

bool HasWon(char board[4][4], char player);
bool HasCompleted(char board[4][4]);

void SolveInstance()
{
	//Discard prior newline
	char d = input.get();
	
	char B[4][4];

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			B[i][j] = input.get();
			//Discard the newline
			
		}
		d = input.get();
	}

	if(HasWon(B, 'X'))
		output << "Case #" << CaseNum << ": X won" << endl;
	else if (HasWon(B, 'O'))
		output << "Case #" << CaseNum << ": O won" << endl;
	else if (HasCompleted(B))
		output << "Case #" << CaseNum << ": Draw" << endl;
	else
		output << "Case #" << CaseNum << ": Game has not completed" << endl;
}

bool HasWon(char board[4][4], char player)
{
	//Horizontal
	for (int i = 0; i < 4; ++i)
	{
		bool win = true;
		for (int j = 0; j < 4; ++j)
		{
			if(board[i][j] != player && board[i][j] != 'T')
			{
				win = false;
				break;
			}
		}
		if (win)
			return true;
	}

	//Vertical
	for (int i = 0; i < 4; ++i)
	{
		bool win = true;
		for (int j = 0; j < 4; ++j)
		{
			if(board[j][i] != player && board[j][i] != 'T')
			{
				win = false;
				break;
			}
		}
		if (win)
			return true;
	}

	//Diags
	{
		bool win = true;
		for (int i = 0; i < 4; ++i)
		{
			if(board[i][i] != player && board[i][i] != 'T')
			{
				win = false;
				break;
			}
		}
		if (win)
			return true;
	}

	{
		bool win = true;
		for (int i = 0; i < 4; ++i)
		{
			if(board[i][3-i] != player && board[i][3-i] != 'T')
			{
				win = false;
				break;
			}
		}
		if (win)
			return true;
	}
}

bool HasCompleted(char board[4][4])
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (board[i][j] == '.')
				return false;

	return true;
}
