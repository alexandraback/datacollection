#include <fstream>
using namespace std;

ifstream fin("a.in");
ofstream fout("A.out");

void solve(int case_num) {
	char a[4][4];
	char sym[3] = "XO";
	for (int i=0; i<4; ++i) {
		for (int j=0; j<4; ++j) {
			fin >> a[i][j];
		}
	}

	fout << "Case #" << case_num << ": ";

	for (int i=0; i<2; ++i) {
		for (int j=0; j<4; ++j) {
			for (int k=0; k<4; ++k) {
				if (!( a[j][k] == sym[i] || a[j][k] == 'T' )) {
					break;
				}
				if (k == 3) {
					fout << sym[i] << " won\n";
					return;
				}
			}
		}

		for (int j=0; j<4; ++j) {
			for (int k=0; k<4; ++k) {
				if (!( a[k][j] == sym[i] || a[k][j] == 'T' )) {
					break;
				}
				if (k == 3) {
					fout << sym[i] << " won\n";
					return;
				}
			}
		}

		for (int j=0; j<4; ++j) {
			if (!( a[j][j] == sym[i] || a[j][j] == 'T' )) {
				break;
			}
			if (j == 3) {
				fout << sym[i] << " won\n";
				return;
			}
		}

		for (int j=0; j<4; ++j) {
			if (!( a[j][3-j] == sym[i] || a[j][3-j] == 'T' )) {
				break;
			}
			if (j == 3) {
				fout << sym[i] << " won\n";
				return;
			}
		}
	}

	for (int i=0; i<4; ++i) {
		for (int j=0; j<4; ++j) {
			if (a[i][j] == '.') {
				fout << "Game has not completed\n";
				return;
			}
		}
	}

	fout << "Draw\n";
}

int main() {
	int n;
	fin >> n;
	for (int case_num=1; case_num<=n; ++case_num) {
		solve(case_num);
	}
	return 0;
}
