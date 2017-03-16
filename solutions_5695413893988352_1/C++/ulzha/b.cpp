#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

typedef long long ll;

/*

???2?99999
???2?00001

*/

ll to_ll(const string &s) {
	istringstream sin(s);
	ll r;

	sin >> r;

	return r;
}

void minimize(string C, string J, bool cbigger, string &c, string &j) {
	ll vc = to_ll(c), vj = to_ll(j);
	int i;

	for (i = 0; i < C.size(); i++) {
		if (C[i] == '?') C[i] = (cbigger ? '0' : '9');
		if (J[i] == '?') J[i] = (cbigger ? '9' : '0');
	}

	ll vC = to_ll(C), vJ = to_ll(J);

	// cout << C << ' ' << J << endl;
	if (abs(vC - vJ) < abs(vc - vj) || abs(vC - vJ) == abs(vc - vj) && (vC < vc || vC == vc && vJ < vj)) {
		c = C;
		j = J;
	}
}

void probe(string C, string J, int ifirstdiff, char dC, char dJ, string &c, string &j) {
	if (dJ < '0' || dJ > '9') return;
	if (C[ifirstdiff] != '?' && C[ifirstdiff] != dC) return;
	if (J[ifirstdiff] != '?' && J[ifirstdiff] != dJ) return;
	C[ifirstdiff] = dC;
	J[ifirstdiff] = dJ;
	minimize(C, J, false, c, j);
	minimize(C, J, true, c, j);
}

int main() {
	int nt, it;

	cin >> nt;
	for (it = 0; it < nt; it++) {
		string C, J, c(18, '9'), j(18, '0');
		int i;
		cin >> C >> J;

		// c = C, j = J;

		for (i = 0; i < C.size(); i++) {
			char d;

			if (C[i] != '?' && J[i] != '?') {
				probe(C, J, i, C[i], J[i], c, j);
			} else {
				for (d = '0'; d <= '9'; d++) {
					probe(C, J, i, d, d + 1, c, j);
					probe(C, J, i, d, d - 1, c, j);
				}
			}

			// }
			// if (C[i] == '?' && J[i] == '?') {
			// 	minimize(C, J, i, false, c, j);
			// 	minimize(C, J, i, true, c, j);
			// } else if (C[i] == '?') {

			// } else if (J[i] == '?') {

			// } else {

			// 	// if (C[i] != J[i]) break;
			// }

			// if (C[i] != '?' && J[i] != '?' && C[i] != J[i]) break;

			if (C[i] == '?' && J[i] == '?') {
				C[i] = J[i] = '0';
			} else if (C[i] == '?') {
				C[i] = J[i];
			} else if (J[i] == '?') {
				J[i] = C[i];
			}
		}
		minimize(C, J, false, c, j);

		cout << "Case #" << it + 1 << ": " << c << ' ' << j << endl;
	}
}
