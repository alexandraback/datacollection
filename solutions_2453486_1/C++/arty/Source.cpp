#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin("A-large.in");
ofstream fout("output.txt");

void read_game(vector<string>& vec) {
	vec.clear();
	vec.resize(4);
	for (int i=0;i<4;i++) {
		string line;
		fin >> line;
		vec[i] = line;
	}
}

bool is_game_over(vector<string>& vec) {
	for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			if (vec[i][j] == '.') return false;
		}
	}
	return true;
}

int who_won(vector<string>& vec) {
	//check lines
	for (int i=0;i<4;i++) {
		char c = vec[i][0];
		if (c == 'T') 
			c = vec[i][1];
		if (c == '.') continue;
		int count = 0;
		for (int j=0;j<4;j++) {
			if (vec[i][j] == c || vec[i][j] == 'T') count += 1;
		}
		if (count == 4) {
			if (c == 'X') return 0;
			if (c == 'O') return 1;
		}
	}

	//check columns
	for (int i=0;i<4;i++) {
		char c = vec[0][i];
		if (c == 'T') 
			c = vec[1][i];
		if (c == '.') continue;
		int count = 0;
		for (int j=0;j<4;j++) {
			if (vec[j][i] == c || vec[j][i] == 'T') count += 1;
		}
		if (count == 4) {
			if (c == 'X') return 0;
			if (c == 'O') return 1;
		}
	}

	//check main diagonal
	char c = vec[0][0];
	if (c == 'T') c = vec[1][1];
	if (c != '.') {
		int count = 0;
		for (int i=0;i<4;i++)
			if (vec[i][i] == c || vec[i][i] == 'T') count += 1;
		if (count == 4) {
			if (c == 'X') return 0;
			if (c == 'O') return 1;
		}
	}

	c = vec[0][3];
	if (c == 'T') c = vec[1][2];
	if (c != '.') {
		int count = 0;
		for (int i=0;i<4;i++) {
			if (vec[i][3-i] == c || vec[i][3-i] == 'T') count += 1;
		}
		if (count == 4) {
			if (c == 'X') return 0;
			if (c == 'O') return 1;
		}
	}

	return -1;
}

int main() {

	int T;
	fin >> T;

	for (int t=1;t<=T;t++) {
			vector<string> lines(4);
			read_game(lines);
			int result = who_won(lines);
			switch (result) {
			case 0:
				fout << "Case #" << t << ": X won" << endl;
				break;
			case 1:
				fout << "Case #" << t << ": O won" << endl;
				break;
			default:
				if (is_game_over(lines)) {
					fout << "Case #" << t << ": Draw" << endl;
				} else {
					fout << "Case #" << t << ": Game has not completed" << endl;
				}
			}
			
	}

	fin.close();
	fout.close();

	return 0;
}