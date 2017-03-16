#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");

void solve(int case_num) {
	int n, m;
	fin >> n >> m;
	int a[n][m];
	vector<int> rmax(n, 0), cmax(m, 0);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			fin >> a[i][j];
			rmax[i] = max( rmax[i], a[i][j] );
			cmax[j] = max( cmax[j], a[i][j] );
		}
	}

	fout << "Case #" << case_num << ": ";

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (!( a[i][j] == rmax[i] || a[i][j] == cmax[j] )) {
				fout << "NO\n";
				return;	
			}
		}
	}
	fout << "YES\n";
}

int main() {
	int n;
	fin >> n;
	for (int case_num=1; case_num<=n; ++case_num) {
		solve(case_num);
	}
	return 0;
}
