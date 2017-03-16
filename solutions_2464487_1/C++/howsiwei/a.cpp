#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("a.in");
ofstream fout("A.out");

void solve() {
	unsigned long long r, t;
	fin >> r >> t;
	unsigned long long n = 0;

	for (int stp = 1<<30; stp > 0; stp >>= 1) {
		n += stp;
		if ( n*(2*(n+r)-1) > t ) n -= stp;
	}
	fout << n << '\n';
}

int main() {
	int n;
	fin >> n;
	for (int case_num = 1; case_num <= n; ++case_num) {
		fout << "Case #" << case_num << ": ";
		solve();
	}
	return 0;
}
