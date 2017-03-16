#include <iostream>
#include <fstream>
using namespace std; 

char Board[50][50];
int row, col, mines;
int REMAIN;
bool POSSIBLE;
int m;
ofstream out ("OUT.txt");

void initBoard()
{
	for(int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			Board[i][j] = '*';
	}
}

void printBoard()
{
	Board[0][0] = 'c';
	for(int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			out << Board[i][j];
		out << endl;
	}
}

int MIN (int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

void ADJUSTBOARD()
{
	int start = 2;
	int index = 0;
	int lastindex = 0;
	while (REMAIN > 1 && index < col)
	{
		lastindex = index;
		Board[0][index] = '.';
		Board[1][index] = '.';
		index++;
		REMAIN -= 2;
	}
	index = 0;
	while (REMAIN > 0)
	{
		Board[start][index] = '.';
		index++;
		if (index == col)
		{
			index = 0;
			start++;
		}
		REMAIN--;
	}
	if(index == 1)
	{
		if(start > 2)
		{
			Board[start][1] = '.';
			Board[start-1][col-1] = '*';
		}
		else 
		{
			Board[start][1] = '.';
			Board[start][2] = '.';
			Board[0][lastindex] = '*';
			Board[1][lastindex] = '*';
		}
	}

}

int main()
{
	int CASES = 0;
	ifstream in ("C-large.in");
	in >> CASES;

	for (int i = 1; i <= CASES; i++)
	{	
		out << "Case #" << i << ":\n";
		in >> row;
		in >> col;
		in >> mines;

		initBoard();
		m = MIN(row, col);
		REMAIN = (row * col) - mines;

		if (m == 1) // If one row/col, always possible
		{
			POSSIBLE = true; 

			for (int i = 0; i < REMAIN;i++)
			{
				if (col == 1) // 1 column
				{
					Board[i][0] = '.';
				}
				else
				{
					Board[0][i] = '.';
				}
			}
			
			printBoard();
			continue;
		}

		if (REMAIN == 1)
		{
			printBoard();
			continue;
		}
		if (REMAIN < 4 || REMAIN == 5 || REMAIN == 7)
		{
			POSSIBLE = false;
			out << "Impossible\n";
			continue;
		}
		else if (m == 2 && REMAIN % 2 == 1)
		{
			POSSIBLE = false;
			out << "Impossible\n";
			continue;
		}
		ADJUSTBOARD();
		printBoard();


	}
	out.close();
	return 0; 
}