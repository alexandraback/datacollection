#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
typedef long long ll;

int quat[10000];
int stuff[10000][10000];

const int I = 2, J = 3, K = 4;
int decode(char c) {
	if (c == 'i') return I;
	if (c == 'j') return J;
	if (c == 'k') return K;
	cerr << "encode error: " << c << endl;
	return 0;
}
string encode(int q) {
	int q2 = abs(q);
	string res;
	if (q < q2) res += "-";
	if (q2 == 1) res += "1";
	else if (q2 == I) res += "i";
	else if (q2 == J) res += "j";
	else if (q2 == K) res += "k";
	else cerr << "decode error: " << q << endl;
	return res;
}

int qmultable[3][3] = {{-1, 4, -3},
					   {-4, -1, 2},
					   {3, -2, -1}};
int qmulslow(int a, int b) {
	int aa = abs(a); int bb = abs(b);
	if (aa == 1 || bb == 1) return a * b;
	return qmultable[aa-2][bb-2] * a/aa * b/bb;
}
int qpowslow(int q, ll e) {
	if (e == 0) return 1;
	int res = 1;
	e %= 4;
	for (int i = 1; i <= e; i++) {
		res = qmulslow(res, q);
	}
	return res;
}

int qmulcache[16][16];
inline int qmul(int a, int b) {
	return qmulcache[a+4][b+4];
}

int qpowcache[16][4];
inline int qpow(int q, ll e) {
	return qpowcache[q+4][e%4];
}

void test() {
	for (int i = 1; i <= 4; i++) {
		if (i == 1) {
			for (int j = 1; j <= 4; j++) {
				cout << "\t" << encode(j);
			}
			cout << endl;
		}
		cout << encode(i);
		for (int j = 1; j <= 4; j++) {
			cout << "\t" << encode(qmul(i, j));
		}
		cout << endl;
	}
	for (int q = 1; q <= 4; q++) {
		for (int i = 0; i < 10; i++) {
			cout << encode(qpow(q, i)) << ' ';
		}
		cout << endl;
		for (int i = 0; i < 10; i++) {
			cout << encode(qpow(-q, i)) << ' ';
		}
		cout << endl;
	}
}


bool bruteforce(string s, int L, int X) {
	stringstream ss;
	for (int i = 0; i < X; i++) {
		ss << s;
	}
	string str = ss.str();
	int f = L*X;
	for (int i = 0; i < f; i++) {
		quat[i] = decode(str[i]);
		stuff[i][i] = quat[i];
	}
	for (int k = 1; k < f; k++) {
		for (int i = 0; i+k < f; i++) {
			stuff[i][i+k] = qmul(quat[i], stuff[i+1][i+k]);
		}
	}
	for (int i = 0; i < f-2; i++) {
		if (stuff[0][i] != I) continue;
		for (int j = i+1; j < f-1; j++) {
			if (stuff[i+1][j] != J) continue;
			if (stuff[j+1][f-1] == K) return true;
		}
	}
	return false;
}

bool solve(string s, int L, ll X) {
	for (int i = 0; i < L; i++) {
		quat[i] = decode(s[i]);
		stuff[i][i] = quat[i];
	}
	for (int k = 1; k < L; k++) {
		for (int i = 0; i+k < L; i++) {
			stuff[i][i+k] = qmul(quat[i], stuff[i+1][i+k]);
		}
	}

	int blockmul = stuff[0][L-1];
	for (int i = 0; i < L; i++) {
		ll block = 0; // block of current character

		// first character is i
		int ii = stuff[0][i];
		for (int e = 0; e < 4; e++) {
			if (ii == I) break;
			// try prepending a full block before
			ii = qmul(blockmul, ii);
			block++;
		}
		if (ii != I) continue;
		int pos1 = block*L+i;

		for (int j = i+1; j < 2*L; j++) {
			if (j == L) block++;
			ll block2 = block;

			// second character is j
			int jj = 1;
			if (j < L) {
				jj = stuff[i+1][j];
				if (j == L-1) {
					for (int e = 0; e < 4; e++) {
						if (jj == J) break;
						jj = qmul(jj, blockmul);
						block2++;
					}
				}
			} else {
				int part1 = 1;
				int part2 = stuff[0][j-L];
				if (i+1 < L) part1 = stuff[i+1][L-1];

				jj = qmul(part1, part2);
				for (int e = 0; e < 4; e++) {
					if (jj == J) break;
					part1 = qmul(part1, blockmul);
					jj = qmul(part1, part2);
					block2++;
				}
			}
			if (jj != J) continue;
			int pos2 = block2*L+(j%L);

			// third character is k
			int kk = 1;
			if (j+1 < L) {
				kk = stuff[j+1][L-1];
			} else if (L < j+1 && j+1 < 2*L) {
				kk = stuff[j+1-L][L-1];
			} else {
				kk = blockmul;
				block2++;
			}

			if (block2 >= X) continue;
			kk = qmul(kk, qpow(blockmul, X-1 - block2));
			if (kk == K) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// cache to speed up
	for (int i = -4; i <= 4; i++) {
		if (i == 0) continue;
		for (int j = -4; j <= 4; j++) {
			if (j == 0) continue;
			qmulcache[i+4][j+4] = qmulslow(i, j);
		}
		for (int e = 0; e < 4; e++) {
			qpowcache[i+4][e] = qpowslow(i, e);
		}
	}
	//test();
	//return 0;

	int nc; cin >> nc;
	for (int cs = 1; cs <= nc; cs++) {
		int L; ll X; cin >> L >> X;
		string s; cin >> s;

		bool ans = solve(s, L, X);
		//bool ans = bruteforce(s, L, X);
		cout << "Case #" << cs << ": ";
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
