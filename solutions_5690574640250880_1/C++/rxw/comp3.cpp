#include <iostream>
#include <fstream>

using namespace std;

//this function prints a winning board.
//it returns false if a winning board is impossible
//this DOESN'T handle the case where only one space is not a mine
//this DOESN'T handle the case where there is only one row or column
//this DOESN'T detect "staircase" solutions
bool printWinningBoard(int row, int col, int mines, ofstream& out)
{
	int emptySpaces = row * col - mines;

	//first try to create a rectangle of empty spaces
	//if the rectangle fits in the board, it is winnable
	//(rectangle must have a height and width of at least 2)
	int rectRows, rectCols;
	for (rectCols = col; rectCols >= 2; --rectCols)
	{
		//if you can create a rectangle of empty spaces
		//with this number of columns...
		if(emptySpaces % rectCols == 0) {
			rectRows = emptySpaces / rectCols;
			//if it fits in the board...
			if(rectRows <= row && rectRows >= 2) {
				//print the board!
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if(i == 0 && j == 0)
							out << "c";
						else if(i < rectRows && j < rectCols)
							out << ".";
						else
							out << "*";
					}
					out << endl;
				}
				return true;
			}
		}
	}

	//if the above didn't work, we'll have to try to
	//form a solution using two rectangles.
	//Example:
	//......A***
	//......****
	//**********
	//**********
	//(. = attempted first square)
	//(A = top-left of a spot where we'll try to place the other square)
	//hypothetical rectangle A must have height at least 2
	
	int rectOneRows, rectOneCols, rectTwoRows, rectTwoCols;

	//iterate through the number of empty spaces devoted to the Other rectangle
	for (int rectTwoSpaces = 2; rectTwoSpaces <= emptySpaces; ++rectTwoSpaces)
	{
		int rectOneSpaces = emptySpaces - rectTwoSpaces;

		//iterate through possible first rectangles of modified # of spaces
		for (rectOneCols = col; rectOneCols >= 2; --rectOneCols)
		{
			if(rectOneSpaces % rectOneCols == 0) {
				rectOneRows = rectOneSpaces / rectOneCols;
				//if it fits in the board...
				if(rectOneRows <= row && rectOneRows >= 2) {

					//now we must try to place the secondary rectangle
					//trying to put it in spot 'A' (see above)
					if(rectOneCols < col) {
						//number of 2nd rect rows is <= first rect rows, but >= 2
						for(rectTwoRows = rectOneRows; rectTwoRows >= 2; --rectTwoRows)
						{
							//make sure we can make a rectangle from that # of rows
							if(rectTwoSpaces % rectTwoRows == 0) {
								rectTwoCols = rectTwoSpaces / rectTwoRows;
								//would this secondary rectangle fit?
								if(rectOneCols + rectTwoCols <= col) {
									//then we have a winner, print out board

									for (int i = 0; i < row; ++i)
									{
										for (int j = 0; j < col; ++j)
										{
											if(i == 0 && j == 0)
												out << "c";
											else if((i < rectTwoRows && j < rectOneCols + rectTwoCols)
												 || (i < rectOneRows && j < rectOneCols))
												out << ".";
											else
												out << "*";
										}
										out << endl;
									}
									return true;
								}
							}
						}
					}
				}
			}
		}
	}

	return false;
}

//my algorithm above doesn't detect these sorts of solutions
//I get the feeling this is just a band-aid to a greater logical error however
///returns stair base
///returns -1 if not a staircase solution
int isStaircaseSolution(int r, int c, int m) {
	int lesser = (r < c)? r : c; //get r or c, whichever is lesser
	int stairSize = 3;
	//create staircases of at least "base" 2, up to 2 from the border
	for(int i = 2; i <= lesser - 2; ++i) {
		if(m == stairSize)
			return i;
		stairSize += (i + 2);
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	if(argc != 3) {
		cerr << "Usage: comp3 <inputFile> <outputFile>" << endl;
		return -1;
	}

	ifstream in(argv[1], ifstream::in);
	ofstream out(argv[2], ifstream::out);

	int numTests = 0;
	in >> numTests;

	for (int i = 0; i < numTests; ++i)
	{
		//r = rows of board
		//c = columns of board
		//m = number of mines
		int r, c, m;
		in >> r;
		in >> c;
		in >> m;

		out << "Case #" << i + 1 << ":" << endl;

		//these boards aren't possible...
		if(r == 0 || c == 0) {
			out << "Impossible" << endl;
		}

		//if mines are filling the board, it's impossible
		else if(m >= r * c) {
			out << "Impossible" << endl;
		}

		//always-win scenario, click the one spot without a mine
		else if(m == (r * c) - 1) {
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
				{
					if(i == 0 && j == 0)
						out << "c";
					else
						out << "*";
				}
				out << endl;
			}
		}

		//if the board is a single row it is winnable in one click
		//(as long as the board isn't filled)
		else if(r == 1) {
			out << "c";
			//print empty spaces
			for(int i = 0; i < (c - m) - 1; ++i)
				out << ".";
			//print mines
			for(int i = 0; i < m; ++i)
				out << "*";
			out << endl;
		}

		//if the board is a single column it is winnable in one click
		//(as long as the board isn't filled)
		else if(c == 1) {
			out << "c" << endl;
			//print empty spaces
			for(int i = 0; i < (r - m) - 1; ++i) {
				out << "." << endl;
			}
			//print mines
			for(int i = 0; i < m; ++i) {
				out << "*" << endl;
			}
		}

		else if(printWinningBoard(r, c, m, out)) {}


		else if(isStaircaseSolution(r, c, m) > 0) {
			int base = isStaircaseSolution(r, c, m); //
			for (int i = 0; i < r; ++i)
			{
				int bombsToPrintThisRow = (i - (r - base)) + 1;
				if(bombsToPrintThisRow < 0) bombsToPrintThisRow = 0; //abs
				for (int j = 0; j < c; ++j)
				{
					if(i == 0 && j == 0)
						out << "c";
					else if(i < r - base || j < c - bombsToPrintThisRow)
						out << ".";
					else
						out << "*";
				}
				out << endl;
			}
		}

		else
			out << "Impossible" << endl;
	}

	return 0;
}