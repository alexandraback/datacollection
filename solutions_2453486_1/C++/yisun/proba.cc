#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

fstream in, out;

int t;

char grid[4][4];

bool is_win(char side) {
	bool ret = false;
	bool temp = true;
	for (int i = 0; i < 4; i++) {
		temp = true;
		for (int j = 0; j < 4; j++) {
			if (grid[i][j] != side && grid[i][j] != 'T') {
				temp = false;
			}
		}
		if (temp) {
			return true;
		}

		temp = true;
		for (int j = 0; j < 4; j++) {
			if (grid[j][i] != side && grid[j][i] != 'T') {
				temp = false;
			}
		}
		if (temp) {
			return true;
		}
	}

	temp = true;
	for (int i = 0; i < 4; i++) {
		if (grid[i][i] != side && grid[i][i] != 'T') {
			temp = false;
		}
	}
	if (temp) {
		return true;
	}

	temp = true;
	for (int i = 0; i < 4; i++) {
		if (grid[3 - i][i] != side && grid[3 - i][i] != 'T') {
			temp = false;
		}
	}
	if (temp) {
		return true;
	}
	return false;
}


int main() {
	in.open("A-large.in", fstream::in);
	out.open("proba-large.out", fstream::out);

	in >> t;

	string xwon = "X won";
	string owon = "O won";
	string draw = "Draw";
	string notcomplete = "Game has not completed";
	string ans;
	int count;

    for (int i = 0; i < t; i++) {
		count = 0;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				in >> grid[j][k];
				if (grid[j][k] != '.') {
					count++;
				}
			}
		}
		
		if (is_win('X')) {
			ans = xwon;
		} else if (is_win('O')) {
			ans = owon;
		} else if (count == 16) {
			ans = draw;
		} else {
			ans = notcomplete;
		}

		out << "Case #" << i + 1 << ": " << ans << endl;
	}
    
	in.close();
	out.close();

	return 0;
}
