#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int N = 4;

typedef vector<vector<char>> GameBoard;

enum Result {
	X,
	O,
	Draw,
	Continue
};

void AddRow(GameBoard &board, const string & row) {
	vector<char> vec;
	vec.push_back(row[0]);
	vec.push_back(row[1]);
	vec.push_back(row[2]);
	vec.push_back(row[3]);
	board.push_back(vec);
}

Result CheckRow(GameBoard &board, int row) {
	char result[256] = {0};
	for(int i = 0; i < N; ++i ) {
		result[board[row][i]]++;
	}
	if(result['X'] == 4 || (result['X'] == 3 && result['T'] == 1))
		return X;
	if(result['O'] == 4 || (result['O'] == 3 && result['T'] == 1))
		return O;
	if(result['.'] > 0)
		return Continue;
	return Draw;
}

Result CheckCol(GameBoard &board, int col) {
	char result[256] = {0};
	for(int i = 0; i < N; ++i ) {
		result[board[i][col]]++;
	}
	if(result['X'] == 4 || (result['X'] == 3 && result['T'] == 1))
		return X;
	if(result['O'] == 4 || (result['O'] == 3 && result['T'] == 1))
		return O;
	if(result['.'] > 0)
		return Continue;
	return Draw;
}

Result CheckDiagonal(GameBoard &board, bool forward) {
	char result[256] = {0};
	for(int i = 0; i < N; ++i ) {
		result[board[i][forward ? i : N-i-1]]++;
	}
	if(result['X'] == 4 || (result['X'] == 3 && result['T'] == 1))
		return X;
	if(result['O'] == 4 || (result['O'] == 3 && result['T'] == 1))
		return O;
	if(result['.'] > 0)
		return Continue;
	return Draw;
}

Result CheckGame(GameBoard &board) {

	Result result;
	bool finished(true);
	for(int i = 0; i < N; ++i) {
		result = CheckRow(board, i);
		if(X == result || O == result)
			return result;
		if(Continue == result)
			finished = false;
		result = CheckCol(board, i);
		if(X == result || O == result)
			return result;
		if(Continue == result)
			finished = false;
	}

	result = CheckDiagonal(board, true);
	if(X == result || O == result)
		return result;
	if(Continue == result)
		finished = false;

	result = CheckDiagonal(board, false);
	if(X == result || O == result)
		return result;
	if(Continue == result)
		finished = false;

	return finished ? Draw : Continue;
}

int main(int argc, char *argv[]) {
	fstream infile(argv[1]);
	if(!infile.is_open()) {
		cerr << "Could not open file " << argv[0] << endl;
		return -1;
	}

	string line;
	getline(infile, line);
	GameBoard board;
	int testCase = atoi(line.c_str());
	for(int i = 1; i <= testCase; ++i) {
		cout << "Case #" << i << ": ";
		getline(infile, line);
		AddRow(board, line);
		getline(infile, line);
		AddRow(board, line);
		getline(infile, line);
		AddRow(board, line);
		getline(infile, line);
		AddRow(board, line);
		Result result = CheckGame(board);
		switch (result)
		{
		case X:
			cout << "X won" << endl;
			break;
		case O:
			cout << "O won" << endl;
			break;
		case Continue:
			cout << "Game has not completed" << endl;
			break;
		case Draw:
			cout << "Draw" << endl;
			break;
		default:
			break;
		}
		board.clear();
		getline(infile, line);
	}

	return 0;
}