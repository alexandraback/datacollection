#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

typedef long double ld;

ifstream inf("B-small-attempt0.in");
ofstream ouf("output.txt");

char built[10];
ld P[30];

int gen(int pos, int S, string &kbd, string &word, int &mx) {
	if (pos == S) {
		int occ = 0;
		for (int i = 0; i < S; ++i) {
			bool ok = true;
			for (int j = 0; j < word.length(); ++j) {
				if (i + j >= S || word[j] != built[i + j]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				occ += 1;
			}
			mx = max(mx, occ);
		}
		return occ;
	}
	else {
		int res = 0;
		for (int i = 0; i < kbd.length(); ++i) {
			built[pos] = kbd[i];
			res += gen(pos + 1, S, kbd, word, mx);
		}
		return res;
	}
}

int main() {
	ouf.precision(7);
	int T; inf >> T;
	for (int t = 1; t <= T; ++t) {
		cerr << t << endl;
		int K, L, S;
		string keyboard, word;
		inf >> K >> L >> S >> keyboard >> word;
		fill(P, P + 30, 0);
		for (int i = 0; i < keyboard.length(); ++i) {
			P[keyboard[i] - 'A'] += 1;
		}
		for (int i = 0; i < 30; ++i) {
			P[i] /= keyboard.length();
		}
		int all = 1;
		for (int s = 0; s < S; ++s) {
			all *= K;
		}
		int mx = 0;
		ld sum = gen(0, S, keyboard, word, mx);
		ouf << "Case #" << t << ": " << (mx - sum / all) << endl;
	}
}