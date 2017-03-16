#include <fstream>

using namespace std;

ifstream fin("B-large.in");
ofstream fout("out.txt");

long long two[61];

int a[50][50];
int num[61];

int main() {
	int tests;
	fin >> tests;
	two[0] = 1;
	for (int i = 1; i < 61; ++i) {
		two[i] = two[i - 1] * 2;
	}

	for (int test = 0; test < tests; ++test) {
		memset(a, 0, sizeof(a));
		memset(num, 0, sizeof(num));
		int b;
		long long m;
		fin >> b >> m;
		int maxtwo = 1;
		bool eq = false;
		for (int i = 60; i >= 0; --i) {
			if (two[i] <= m) {
				maxtwo = i;
				if (two[i] == m) {
					eq = true;
				}
				break;
			}
		}
		m -= two[maxtwo];
		long long one = 1;
		for (int i = 0; i <= 60; ++i) {
			if (m & (one << i)) {
				num[i] = 1;
			} else {
				num[i] = 0;
			}
		}
		fout << "CASE #" << test + 1 << ": ";
		int req = maxtwo + 2;
		if (!eq) {
			++req;
		}
		if (req > b) {
			fout << "IMPOSSIBLE" << endl;
		} else {
			fout << "POSSIBLE" << endl;
			a[0][b - 1] = 1;
			for (int i = 1; i <= maxtwo; ++i) {
				a[0][i] = 1;
				for (int j = 1; j < i; ++j) {
					a[i][j] = 1;
				}
				a[i][b - 1] = 1;
			}
			if (!eq) {
				int cur = maxtwo + 1;
				a[0][cur] = 1;
				for (int i = 60; i >= 0; --i) {
					if (num[i]) {
						a[cur][i + 1] = 1;
					}
				}
			}

			for (int i = 0; i < b; ++i) {
				for (int j = 0; j < b; ++j) {
					fout << a[i][j];
				}
				fout << endl;
			}
		}
	}

	return 0;
}
