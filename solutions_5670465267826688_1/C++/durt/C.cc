#include <iostream>
#include <string>
#include <utility>
#include <cassert>
using namespace std;

int L;
long long X;
string base;

typedef pair<int,char> quat;

char sym_table[4][4] = {
	{'1', 'i', 'j', 'k'},
	{'i', '1', 'k', 'j'},
	{'j', 'k', '1', 'i'},
	{'k', 'j', 'i', '1'}};

int sign_table[4][4] = {
	{ 1,  1,  1,  1},
	{ 1, -1,  1, -1},
	{ 1, -1, -1,  1},
	{ 1,  1, -1, -1}};
	
int encode(char c) {
	switch (c) {
		case ('1'): return 0;
		case ('i'): return 1;
		case ('j'): return 2;
		case ('k'): return 3;
	}
	assert(false);
	return -1;
}

quat multQuats(quat a, quat b) {
	int x = encode(a.second), y = encode(b.second);
	int sign = sign_table[x][y];
	char sym = sym_table[x][y];
	quat res = make_pair(sign, sym);
	res.first *= (a.first * b.first);
	return res;
}

string solve() {
	bool ifound = false, jfound = false;
	quat state = make_pair(1, '1');
	for (int i = 0; i < min(16LL,X)*L; i++) {
		quat next = make_pair(1, base[i%L]);
		state = multQuats(state, next);
		if (!ifound) {
			if (state == make_pair(1, 'i')) {
				ifound = true;
				state = make_pair(1, '1');
			}
		} else {
			if (state == make_pair(1, 'j')) {
				jfound = true;
				break;
			}
		}
	}
	if (!ifound || !jfound)
		return "NO";
	// finally, need to check that L^X = -1 (i.e. ijk)
	// first evaluate L
	state = make_pair(1, '1');
	for (int i = 0; i < L; i++) {
		quat next = make_pair(1, base[i%L]);
		state = multQuats(state, next);
	}
	// -1 means X must be odd and we're good
	// +/- i,j,k mean x must be 2*odd and we're good
	if (state == make_pair(-1, '1') && X % 2 == 1)
		return "YES";
	if (state.second != '1' && X % 2 == 0 && (X/2) % 2 == 1)
		return "YES";
	return "NO";
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> L >> X >> base;
		string res = solve();
		cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}
