
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream input;
ofstream output;

void process(int C, char area[4][4]) {
	char adjX_x[4][4];
	char adjX_y[4][4];
	char adjX_lr[4][4];
	char adjX_rl[4][4];

	char adjO_x[4][4];
	char adjO_y[4][4];
	char adjO_lr[4][4];
	char adjO_rl[4][4];

	bool has_empty = false;
	bool X_won = false;
	bool O_won = false;

	output 	<< "Case #" << C << ": ";

	for(int r = 0; r < 4; r++) {
		for(int c = 0; c < 4; c++) {
			char cell = area[r][c];
			if(cell == '.') has_empty=true;

			bool is_X = cell=='X' || cell =='T';
			bool is_O = cell=='O' || cell =='T';

			adjX_x[r][c]  = is_X ? (c>0 ? adjX_x[r][c-1]+1 : 1) : 0;
			adjX_y[r][c]  = is_X ? (r>0 ? adjX_y[r-1][c]+1 : 1) : 0;
			adjX_lr[r][c] = is_X ? (c>0 && r>0 ? adjX_lr[r-1][c-1]+1 : 1) : 0;
			adjX_rl[r][c] = is_X ? (c<3 && r>0 ? adjX_rl[r-1][c+1]+1 : 1) : 0;

			X_won |= (adjX_x[r][c] >= 4 || adjX_y[r][c] >= 4 ||
					adjX_lr[r][c] >= 4 || adjX_rl[r][c] >= 4);

			adjO_x[r][c]  = is_O ? (c>0 ? adjO_x[r][c-1]+1 : 1) : 0;
			adjO_y[r][c]  = is_O ? (r>0 ? adjO_y[r-1][c]+1 : 1) : 0;
			adjO_lr[r][c] = is_O ? (c>0 && r>0 ? adjO_lr[r-1][c-1]+1 : 1) : 0;
			adjO_rl[r][c] = is_O ? (c<3 && r>0 ? adjO_rl[r-1][c+1]+1 : 1) : 0;

			O_won |= (adjO_x[r][c] >= 4 || adjO_y[r][c] >= 4 ||
					adjO_lr[r][c] >= 4 || adjO_rl[r][c] >= 4);
		}
	}

	if(X_won) {
		if(O_won) 		output << "Draw"; // Should not happen
		else			output << "X won";
	} else if(O_won)	output << "O won";
	else if(has_empty)	output << "Game has not completed";
	else 				output << "Draw";

	output << endl;
}

int main() {
	input.open("a.in");
	output.open("a.out");

	string line;
	getline(input, line);

	int N = atoi(line.c_str());

	for(int idx = 0; idx < N; idx++) {
		char area[4][4];

		for(int l = 0; l < 4; l++) {
			getline(input, line);
			line.copy(area[l], 4, 0);
		}

		getline(input, line);

		process(idx + 1, area);
	}

	output.close();
	input.close();

	return 0;
}
