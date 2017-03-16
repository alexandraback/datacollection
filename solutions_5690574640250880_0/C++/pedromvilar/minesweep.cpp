#include <fstream>
//This standard library handles files
#include <sstream>
//This standard library handles stringstreams, useful generalisations of strings
#include <iostream>
//Standard library for talking to the user
using namespace std;

void reveal(char** field, int R, int C, int row, int col);

char** fillField(int R, int C, char c)
{
	/*
	This function creates a RxC field filled with dots
	*/
	char** field = new char*[R];
	for (int i = 0; i < R; i++)
	{
		field[i] = new char[C];
		for (int j = 0; j < C; j++)
		{
			field[i][j] = c;
		}
	}
	return field;
}

void printField(fstream* out, char** field, int R, int C)
{
	/*
	This function prints the solved field
	*/
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			(*out) << field[i][j];
		}
		(*out) << endl;
	}
}

bool isZero(char** field, int R, int C, int row, int col)
{
	/*
	Checks whether position (row, col) is a 0
	*/
	bool upedge = (row == 0), downedge = (row == R - 1), leftedge = (col == 0), rightedge = (col == C - 1);
	if (field[row][col] == '*')
		return false;
	if (!upedge)
	{
		if (!leftedge && field[row - 1][col - 1] == '*')
			return false;
		if (field[row - 1][col] == '*')
			return false;
		if (!rightedge && field[row - 1][col + 1] == '*')
			return false;
	}
	if (!downedge)
	{
		if (!leftedge && field[row + 1][col - 1] == '*')
			return false;
		if (field[row + 1][col] == '*')
			return false;
		if (!rightedge && field[row + 1][col + 1] == '*')
			return false;
	}
	if (!leftedge && field[row][col - 1] == '*')
		return false;
	if (!rightedge && field[row][col + 1] == '*')
		return false;
	return true;
}

void revealAround(char** field, int R, int C, int row, int col)
{
	/*
	Reveals positions around (row, col)
	*/
	bool upedge = (row == 0), downedge = (row == R - 1), leftedge = (col == 0), rightedge = (col == C - 1);
	if (!upedge)
	{
		if (!leftedge)
			reveal(field, R, C, row - 1, col - 1);
		reveal(field, R, C, row - 1, col);
		if (!rightedge)
			reveal(field, R, C, row - 1, col + 1);
	}
	if (!downedge)
	{
		if (!leftedge)
			reveal(field, R, C, row + 1, col - 1);
		reveal(field, R, C, row + 1, col);
		if (!rightedge)
			reveal(field, R, C, row + 1, col + 1);
	}
	if (!leftedge)
		reveal(field, R, C, row, col - 1);
	if (!rightedge)
		reveal(field, R, C, row, col + 1);
}

void reveal(char** field, int R, int C, int row, int col)
{
	//"clicks" position (row, col)
	int bombno = 0;
	if (field[row][col] == '*')
		return;
	if (field[row][col] == '.')
	{
		field[row][col] = 'k';						//marks this position as already checked
		if (isZero(field, R, C, row, col))
			revealAround(field, R, C, row, col);	//if it's another zero, reveals around it
	}
}

bool check(char** field, int R, int C)
{
	/*
	This function checks whether this board is solved
	*/
	bool solved = true;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (field[i][j] == '.')									//this means there was a position that wasn't revealed
				solved = false;
			else if (field[i][j] == 'k')							//"unmarks" the position
				field[i][j] = '.';
		}
	}
	return solved;
}

bool clickOnFirstZero(char** field, int R, int C)
{
	/*
	What it says on the tin
	*/
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (isZero(field, R, C, i, j))						//checks whether that position is zero
			{
				field[i][j] = 'c';								//if it *is* zero we click it
				revealAround(field, R, C, i, j);				//then we call the recursive reveal function
				if (check(field, R, C))							//this function checks whether the board is solved
					return true;
				else
				{
					field[i][j] = '.';
					return false;
				}
			}
		}
	}
	//If it got here, that means it never even found a zero, so the board wasn't solved
	return false;
}

void printField(char** field, int R, int C)
{
	/*
	This function prints the solved field
	*/
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			(cout) << field[i][j];
		}
		(cout) << endl;
	}
}

bool sweep(char** field, int R, int C, int M, int pos)
{
	/*
	This function recursively places mines
	*/
	int k;
	if (M > 0)													//if there are still mines left to place
	{
		for (int i = pos; i < R*C - M; i++)
		{
			field[i / C][i % C] = '*';							//places mine on appropriate position
			if (sweep(field, R, C, M - 1, i + 1))				//places remaining mines
				return true;
			field[i / C][i % C] = '.';							//removes that mine
		}
	}
	else														//if all mines have been placed
		return clickOnFirstZero(field, R, C);					//clicks on the first available zero
	//if it got here, that means this disposition of mines didn't yield a solvable board
	return false;
}

void minesweep(fstream* out, int R, int C, int M)
{
	/*
	This function receives the parameters for the mine field and
	figures out whether it's possible to one-click solve it
	*/
	char** field;
	if (M == 0)
	{
		field = fillField(R, C, '.');
		field[0][0] = 'c';
		printField(out, field, R, C);
	}
	else if (M == R*C - 1)
	{
		field = fillField(R, C, '*');
		field[0][0] = 'c';
		printField(out, field, R, C);
	}
	else
	{
		field = fillField(R, C, '.');
		if (sweep(field, R, C, M, 0))
			printField(out, field, R, C);
		else
			(*out) << "Impossible" << endl;
	}
}

int main()
{
	fstream filein, fileout;
	int T, i, R, C, M;
	string s;
	cout << "Please type name of input file: ";
	cin >> s;
	filein.open(s.c_str(), fstream::in);
	cout << "Please type name of output file: ";
	cin >> s;
	fileout.open(s.c_str(), fstream::out);
	filein >> T;											//gets number of cases
	for (i = 0; i < T; i++)
	{
		//loops for each case
		fileout << "Case #" << (i + 1) << ":" << endl;		//starts building output file
		filein >> R;										//gets values of each case
		filein >> C;
		filein >> M;
		minesweep(&fileout, R, C, M);						//prints out value
	}
	filein.close();
	fileout.close();
	return 0;
}
