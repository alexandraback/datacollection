#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <vector>
#include <map>
#include <list>
#include <cmath>

using namespace std;

char checkVictory(char* board, int start, int stride)
{
	char winning = board[start];
	for (size_t i = 1; i < 4; i++) {
		char cur = board[start + i * stride];
		if (winning == 'T') {
			winning = cur;
		}
		if (cur == 'T') {
			cur = winning;
		}
		if (cur != winning) {
			return '.';
		}
	}
	return winning;
}

void setResult(char& result, char newResult)
{
	if (result == '.') {
		result = newResult;
	}
}

void processCase(istream& in, ostream& out)
{
	char buffer[1024];
	char board[16];
	for (size_t i = 0; i < 4; i++) {
		in.getline(buffer, 1024);
		memcpy(board + i * 4, buffer, 4);
	}
	in.getline(buffer, 1024);

	char result = '.';
	// Rows
	for (size_t i = 0; i < 4; i++) {
		setResult(result, checkVictory(board, i * 4, 1));
	}
	// Cols
	for (size_t i = 0; i < 4; i++) {
		setResult(result, checkVictory(board, i, 4));
	}
	// Diagonals
	setResult(result, checkVictory(board, 0, 5));
	setResult(result, checkVictory(board, 3, 3));

	if (result == '.') {
		// Check for draw
		for (size_t i = 0; i < 16; i++) {
			if (board[i] == '.') {
				out << "Game has not completed";
				return;
			}
		}
		out << "Draw";
	} else {
		// Victory
		out << result << " won";
	}
}

int main()
{
	ifstream in("A-large.in");
	//ostream& out = cout;
	ofstream out("A-large.out", std::ios_base::out);

	int nCases;
	in >> nCases;
	char buffer[1024];
	in.getline(buffer, 1024);

	for (int i=0; i<nCases; i++) {
		out << "Case #" << (i+1) << ": ";
		processCase(in, out);
		out << endl;
	}

	out.flush();
}