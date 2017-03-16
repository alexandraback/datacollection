#include <fstream>
#include <string>
#include <vector>

using namespace std;

void sortt (vector<int> &a, vector<int> &b) {
	int n = a.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j]) {
				int t = a[i]; a[i] = a[j]; a[j] = t;
				int q = b[i]; b[i] = b[j]; b[j] = q;
			}
}

int main () {
	int T;
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");
	fin >> T;
	for (int t = 0; t < T; t++) {
		int b;
		long long m;
		fin >> b >> m;
		int a[60][60];
		for (int i = 0; i < b; i++)
			for (int j = 0; j < b; j++)
				a[i][j] = 0;
		long long x = 1;
		for (int i = 0; i < b - 2; i++)
			x *= 2;
		if (m > x) fout << "Case #" << t + 1 << ": IMPOSSIBLE" << endl; else {
			fout << "Case #" << t + 1 << ": POSSIBLE" << endl;
			for (int i = 0; i < b - 1; i++)
				for (int j = i + 1; j < b - 1; j++)
					a[i][j] = 1;
			if (m == x) {
				for (int i = 0; i < b - 1; i++)
					a[i][b - 1] = 1;
			} else {
				int i = 1;
				while (m > 0) {
					a[i][b - 1] = m % 2;
					m /= 2;
					i++;
				}
			}
			for (int i = 0; i < b; i++) {
				for (int j = 0; j < b; j++)
					fout << a[i][j];
			fout << endl;
			}
		}
	}
	fin.close();
	fout.close();
	return 0;
}