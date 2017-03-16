#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

template<typename T>
T min(T var1, T var2) {
	return (var1 < var2) ? var1 : var2;
}

template<typename T>
T max(T var1, T var2) {
	return (var1 > var2) ? var1 : var2;
}




void printBoard(vector<vector<char> >& board, int rows, int cols, ofstream& outfile) {
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			outfile << board[row][col];
		}
		outfile << endl;
	}
}

void printBoardTransposed(vector<vector<char> >& board, int rows, int cols, ofstream& outfile) {
	for (int col = 0; col < cols; ++col) {
		for (int row = 0; row < rows; ++row) {
			outfile << board[row][col];
		}
		outfile << endl;
	}
}


bool oneByN(vector<vector<char> >& board, int rows, int cols, int freespaces) {
	if (freespaces == 0) {
		return false;
	}
//	board[0][0] = false;
	int numEmpty = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (numEmpty < freespaces) {
				board[i][j] = '.';
				++numEmpty;
			}
			else {
				board[i][j] = '*';
			}
		}
	}

	board[0][0] = 'c';
	return true;
}

bool twoByN(vector<vector<char> >& board, int rows, int cols, int freespaces) {
	if (freespaces != 1 && freespaces % 2 == 1) {
		return false;
	}
	if (freespaces == 2) {
		return false;
	}

	if (freespaces == 1) {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				board[i][j] = '*';
			}
		}
		board[0][0] = 'c';
		return true;
	}
	else { //rows == 2
		int numColsFree = freespaces / 2;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < numColsFree; ++j) {
				board[i][j] = '.';
			}
		}

		board[0][0] = 'c';
		return true;
	}
}

bool fillBoard(vector< vector<char> >& board, int rows, int cols, int freespaces) {
//assume more cols than rows

//	printBoard(board, rows, cols);
	if (freespaces == 0) {
		return false;
	}
	if (freespaces == 1) {
		board[0][0] = 'c';
		return true;
	}

	if (rows == 1 || cols == 1) {
		return oneByN(board, rows, cols, freespaces);
	}
	if (rows == 2 || cols == 2) {
		return twoByN(board, rows, cols, freespaces);
	}

	if (freespaces == 2 || freespaces == 3 || freespaces == 5 || freespaces == 7) {
		return false;
	}

	int fullRowWidth = cols;
	int leftovers = freespaces % fullRowWidth;
	int filledRows = freespaces / fullRowWidth;

	//special case (might not cover all of them....)
	if (leftovers == 1 && filledRows >= 3) {
		for (int row = 0; row < filledRows; ++row) {
			for (int col = 0; col < fullRowWidth; ++col) {
				board[row][col] = '.';
			}
		}
		board[filledRows - 1][cols - 1] = '*';
		for (int col = 0; col < 2; ++col) {
			board[filledRows][col] = '.';
		}
		board[0][0] = 'c';
		return true;
	}

	while (filledRows < 2 || leftovers == 1) {
		--fullRowWidth;
		leftovers = freespaces % fullRowWidth;
		filledRows = freespaces / fullRowWidth;
	}

	for (int row = 0; row < filledRows; ++row) {
		for (int col = 0; col < fullRowWidth; ++col) {
			board[row][col] = '.';
		}
	}
	for (int col = 0; col < leftovers; ++col) {
		board[filledRows][col] = '.';
	}
	board[0][0] = 'c';
	return true;
}

int main() {
	string FILENAME = "C-large.in";
	string OUT_FILENAME = "C-large.out";

	ifstream inputfile;
	inputfile.open(FILENAME);
	int testCases;
	ofstream outfile;
	outfile.open(OUT_FILENAME);
	outfile.precision(10);

	inputfile >> testCases;

	int rows;
	int cols;
	int numMines;

	for (int i = 1; i <= testCases; ++i) {
		inputfile >> rows;
		inputfile >> cols;
		inputfile >> numMines;
		int freespaces = rows*cols - numMines;

		bool transposed = (rows > cols);
		if (transposed) {
			int temp = rows;
			rows = cols;
			cols = temp;
		}

		vector<vector<char> > board;
		board.resize(rows, vector<char>(cols, '*'));
		
//		printBoard(board, rows, cols);

		bool possible = fillBoard(board, rows, cols, freespaces);
		outfile << "Case #" << i << ":" << endl;
		if (!possible) {
			outfile << "Impossible" << endl;
		}
		else {
			if (transposed) {
				printBoardTransposed(board, rows, cols, outfile);
			}
			else {
				printBoard(board, rows, cols, outfile);
			}
		}
//		outfile << "Case #" << i << ": " << fixed << TimeToWin(C, F, X) << endl;
	}

	return 0;

}