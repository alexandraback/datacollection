#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

typedef long long ll;

using namespace std;

void solve(int d, int s, string& C, string J, ll& m, pair<ll, ll>& r, pair<string, string>& r2)
{
	if (d == C.size()){
		istringstream issc(C), issj(J);
		ll c, j;
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
		if (s == 0) {
			C[d] = '0';
			J[d] = '0';
			solve(d + 1, 0, C, J, m, r, r2);
			C[d] = '1';
			J[d] = '0';
			solve(d + 1, 1, C, J, m, r, r2);
			C[d] = '0';
			J[d] = '1';
			solve(d + 1, -1, C, J, m, r, r2);
		}
		else if (s == 1) {
			C[d] = '0';
			J[d] = '9';
			solve(d + 1, 1, C, J, m, r, r2);
		}
		else if (s == -1) {
			C[d] = '9';
			J[d] = '0';
			solve(d + 1, -1, C, J, m, r, r2);
		}
		C[d] = J[d] = '?';
	}
	else if (C[d] == '?') {
		if (s == 0) {
			if (J[d] < '9') {
				C[d] = J[d] + 1;
				solve(d + 1, 1, C, J, m, r, r2);
			}
			C[d] = J[d];
			solve(d + 1, 0, C, J, m, r, r2);
			if (J[d] > '0') {
				C[d] = J[d] - 1;
				solve(d + 1, -1, C, J, m, r, r2);
			}
		}
		else if (s == 1) {
			C[d] = '0';
			solve(d + 1, 1, C, J, m, r, r2);
		}
		else if (s == -1) {
			C[d] = '9';
			solve(d + 1, -1, C, J, m, r, r2);
		}
		C[d] = '?';
	}
	else if (J[d] == '?') {
		if (s == 0) {
			if (C[d] < '9') {
				J[d] = C[d] + 1;
				solve(d + 1, -1, C, J, m, r, r2);
			}
			J[d] = C[d];
			solve(d + 1, 0, C, J, m, r, r2);
			if (C[d] > '0') {
				J[d] = C[d] - 1;
				solve(d + 1, 1, C, J, m, r, r2);
			}
		}
		else if (s == -1) {
			J[d] = '0';
			solve(d + 1, -1, C, J, m, r, r2);
		}
		else if (s == 1) {
			J[d] = '9';
			solve(d + 1, 1, C, J, m, r, r2);
		}
		J[d] = '?';
	}
	else {
		solve(d + 1, s != 0 ? s : C[d]>J[d] ? 1 : (C[d]<J[d] ? -1 : 0), C, J, m, r, r2);
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cerr << t << endl;
		string C, J;
		cin >> C >> J;
		ll d = LLONG_MAX;
		pair<ll, ll> r;
		pair<string, string> r2;
		solve(0,0,C,J,d,r,r2);
		cout << "Case #" << t+1 << ": " << r2.first << " " << r2.second << endl;
	}

	return 0;
}
