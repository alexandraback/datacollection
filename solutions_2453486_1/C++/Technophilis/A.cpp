#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream in("A-large.in");
	ofstream out("A-large.out");

	int T; in >> T;

	for (int x = 1; x <= T; x++) {
		int r[4][2]; for (int i = 0; i < 4; i++) r[i][0] = r[i][1] = 0;
		int c[4][2]; for (int i = 0; i < 4; i++) c[i][0] = c[i][1] = 0;
		int d[2][2]; for (int i = 0; i < 2; i++) d[i][0] = d[i][1] = 0;
		int cnt = 0;
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
			char cc; in >> cc;
			int s = 1, e = 0;
			if (cc == 'O') {
				s = 0, e = 0;
			} else if (cc == 'X') {
				s = 1, e = 1;
			} else if (cc == 'T') {
				s = 0, e = 1;
			} else {
				cnt++;
			}
			for (int a = s; a <= e; a++) {
				r[i][a]++; c[j][a]++;
				if (i == j) d[0][a]++;
				else if (i == 3 - j) d[1][a]++;
			}
		}
		bool ended = 0;
		for (int i = 0; i < 4; i++) {
			if (r[i][0] == 4 || c[i][0] == 4 || (i < 2 && d[i][0] == 4)) {
				out << "Case #" << x << ": O won" << endl; ended = 1;
				break;
			} else if (r[i][1] == 4 || c[i][1] == 4 || (i < 2 && d[i][1] == 4)) {
				out << "Case #" << x << ": X won" << endl; ended = 1;
				break;
			}
		}
		if (!ended) {
			if (cnt == 0) out << "Case #" << x << ": Draw" << endl;
			else out << "Case #" << x << ": Game has not completed" << endl;
		}
	}

	return 0;
}
