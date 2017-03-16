#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

bool flipcs = false;
string best;
string bestc, bests;
string working;

bool w(const string &c, const string &s) {
	const int N = int(c.length());
	bool borrow = false;
	for (int i = N - 1; i >= 0; i--) {
		int value = int(s[i]) - int(c[i]) + (borrow ? -1 : 0);
		if (value >= 0) {
			working[i] = value + '0';
			borrow = false;
		} else {
			working[i] = value + 10 + '0';
			borrow = true;
		}
	}
	return !borrow;  // return true if c is indeed smaller than or equal to s;
}

void recurse(string &c, string &s, int level, int N, bool cIsSmaller) {
	if (level == N) {
		const string &cc = flipcs ? s : c;
		const string &ss = flipcs ? c : s;
		if (w(c, s)) {
			if (working < best) {
				best = working;
				bestc = cc;
				bests = ss;
			} else if (working == best) {
				if (cc < bestc || (cc == bestc && ss < bests)) {
					bestc = cc;
					bests = ss;
				}
			}
		}
		return;
	}
	char c0 = c[level];
	char s0 = s[level];
	if (c0 == '?' && s0 == '?') {
		if (cIsSmaller) {
			c[level] = '9';
			s[level] = '0';
			recurse(c, s, level + 1, N, true);
		} else {
			c[level] = '0';
			s[level] = '0';
			recurse(c, s, level + 1, N, false);
			c[level] = '0';
			s[level] = '1';
			recurse(c, s, level + 1, N, true);
		}
	} else if (c0 == '?') {
		if (cIsSmaller) {
			c[level] = '9';
			recurse(c, s, level + 1, N, true);
		} else {
			c[level] = s0;
			recurse(c, s, level + 1, N, false);
			if (s0 > '0') {
				c[level] = s0 - 1;
				recurse(c, s, level + 1, N, true);
			}
		}
	} else if (s0 == '?') {
		if (cIsSmaller) {
			s[level] = '0';
			recurse(c, s, level + 1, N, true);
		} else {
			s[level] = c0;
			recurse(c, s, level + 1, N, false);
			if (c0 < '9') {
				s[level] = c0 + 1;
				recurse(c, s, level + 1, N, true);
			}
		}
	} else {
		if (cIsSmaller) {
			recurse(c, s, level + 1, N, true);
		} else {  // equal so far;
			if (c0 < s0) {
				recurse(c, s, level + 1, N, true);  // c is now smaller;
			} else if (c0 > s0) {  // c is bigger? skip;
				;  // skip;
			} else {  // equal;
				recurse(c, s, level + 1, N, false);  // c == s so far;
			}
		}
	}

	c[level] = c0;
	s[level] = s0;
}

void solve(int CASE, string c, string s) {
	best = "";
	int N = int(c.length());
	for (int i = 0; i < N; i++) best += "9";
	working = best;
	flipcs = false;
	recurse(c, s, 0, N, false);
	flipcs = true;
	recurse(s, c, 0, N, false);
	cout << "Case #" << CASE << ": " << bestc << " " << bests << endl;
}

int main(int argc, const char * argv[]) {

	istream &fin = cin;
//	fstream fin("tiny.in");

// #if __CMD__
// 	istream &fin = cin;
// #else
// 	fstream fin("tiny.in");
// #endif

	int T;
	fin >> T;
	string W;
	for (int c = 1; c <= T; c++) {
		string cc, ss;
		fin >> cc;
		fin >> ss;
		solve(c, cc, ss);
	}
    return 0;
}
