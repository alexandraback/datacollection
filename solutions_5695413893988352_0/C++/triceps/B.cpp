#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

typedef long long ll;

using namespace std;

void solve(int d, string& C, string J, int& m, pair<int, int>& r, pair<string, string>& r2)
{
	if (d == C.size()){
		istringstream issc(C), issj(J);
		int c, j;
		issc >> c; issj >> j;
		if (abs(c - j) < m) {
			m = abs(c - j);
			r = make_pair(c, j);
			r2 = make_pair(C, J);
		}
		else if (abs(c - j) == m) {
			if (min(r.first, r.second) > min(c, j)) {
				r = make_pair(c, j);
				r2 = make_pair(C, J);
			}
		}
		return;
	}

	if (C[d] == '?' && J[d] == '?') {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				C[d] = ('0' + i);
				J[d] = ('0' + j);
				solve(d + 1, C, J, m, r, r2);
				C[d] = J[d] = '?';
			}
		}
	}
	else if (C[d] == '?') {
		for (int i = 0; i < 10; i++) {
			C[d] = ('0' + i);
			solve(d + 1, C, J, m, r, r2);
			C[d] = '?';
		}
	}
	else if (J[d] == '?') {
		for (int i = 0; i < 10; i++) {
			J[d] = ('0' + i);
			solve(d + 1, C, J, m, r, r2);
			J[d] = '?';
		}
	}
	else {
		solve(d + 1, C, J, m, r, r2);
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string C, J;
		cin >> C >> J;
		int d = 1000000;
		pair<int, int> r;
		pair<string, string> r2;
		solve(0,C,J,d,r,r2);
		cout << "Case #" << t+1 << ": " << r2.first << " " << r2.second << endl;
	}

	return 0;
}
