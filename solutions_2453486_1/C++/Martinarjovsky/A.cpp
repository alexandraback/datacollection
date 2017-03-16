#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("A.in");
ofstream fout ("A.out");

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define pb push_back
#define sz(a) int((a).size()
#define all(c) (c).begin(),(c).end()

int main() {
	int T, c, i, j, count_rx, count_ro, count_cx, count_co, count_d1o, count_d2o, count_d1x, count_d2x;
	vvi board;
	char temp;
	bool flag, empty;

	fin >> T;

	for (c = 1; c <= T; c++) {
		empty = false;
		flag = false;
		board.clear();
		board.resize(4, vi(4, 0));
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				fin >> temp;
				if (temp == 'X') board[i][j] = 1;
				if (temp == 'O') board[i][j] = 2;
				if (temp == 'T') board[i][j] = 3;
			}
		}

		for (i = 0; i < 4; i++) {
			count_rx = 0;
			count_ro = 0;
			count_cx = 0;
			count_co = 0;
			for (j = 0; j < 4; j++) {
				if (board[i][j] == 0) empty = true;
				if (board[i][j] == 1) count_rx++;
				if (board[j][i] == 1) count_cx++;
				if (board[i][j] == 2) count_ro++;
				if (board[j][i] == 2) count_co++;
				if (board[i][j] == 3) {
					count_ro++;
					count_rx++;
				}
				if (board[j][i] == 3) {
					count_co++;
					count_cx++;
				}
			}
			if (count_cx == 4 || count_rx == 4) {
				fout << "Case #" << c << ": X won" << endl;
				flag = true;
				break;
			}
			if (count_co == 4 || count_ro == 4) {
				fout << "Case #" << c << ": O won" << endl;
				flag = true;
				break;
			}
			if (flag) break;
		}
		if (flag) continue;

		count_d1o = 0;
		count_d2o = 0;
		count_d1x = 0;
		count_d2x = 0;

		for (i = 0; i < 4; i++) {
			if (board[i][i] == 1) count_d1x++;
			if (board[i][i] == 2) count_d1o++;
			if (board[3-i][i] == 1) count_d2x++;
			if (board[3-i][i] == 2) count_d2o++;
			if (board[i][i] == 3) {
				count_d1x++;
				count_d1o++;
			}
			if (board[3-i][i] == 3) {
				count_d2x++;
				count_d2o++;
			}
		}

		if (count_d1x == 4 || count_d2x == 4) {
			fout << "Case #" << c << ": X won" << endl;
			flag = true;
		}
		if (count_d1o == 4 || count_d2o == 4) {
			fout << "Case #" << c << ": O won" << endl;
			flag = true;
		}

		if (flag) continue;

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (board[i][j] == 0) empty = true;
			}
		}
		if (empty) {
			fout << "Case #" << c << ": Game has not completed" << endl;
		}
		else {
			fout << "Case #" << c << ": Draw" << endl;
		}

	}

	return 0;
}

