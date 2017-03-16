/*
 * c.cpp
 *
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

template<typename T> inline void ignore(T) {}

typedef unsigned long long ull;

char table[8][8];

char inv(char u) {
	if (u >= 'a' && u <= 'z') {
		return u + 'A' - 'a';
	} else {
		return u + 'a' - 'A';
	}
}

void fill() {
	char product [4][5] =
	{ "lijk",
	  "iLkJ",
	  "jKLi",
	  "kjIL"
	};
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			table[i][j] = product[i%4][j%4];
			if ((i/4) != (j/4)) {
				table[i][j] = inv(table[i][j]);
			}
		}
	}
}

int index(char u) {
	switch (u) {
	case 'l': return 0;
	case 'i': return 1;
	case 'j': return 2;
	case 'k': return 3;
	case 'L': return 4;
	case 'I': return 5;
	case 'J': return 6;
	case 'K': return 7;
	default: return -1;
	}
}

char mult(char u, char v) {
	return table[index(u)][index(v)];
}

bool solve(const string &s, ull l, ull x) {
	char acc, tmp;

	// Check whole product equals -1
	acc = 'l';
	for (ull i = 0; i < l; ++i) {
		acc = mult(acc, s[i]);
	}
	tmp = acc;
	acc = 'l';
	for (ull j = 0; j < (x % 4ull); ++j) {
		acc = mult(acc, tmp);
	}
	if (acc != 'L') {
		return false;
	}

	// Compute prefix and suffix products
	acc = 'l';
	ull prefix = 0;
	for (ull i = 0; i < min(4 * l, l * x); ++i) {
		acc = mult(acc, s[i % l]);
		if (acc == 'i') {
			prefix = i + 1; break;
		}
	}

	acc = 'l';
	ull suffix = 0;
	for (ull i = 0; i < min(4 * l, l * x); ++i) {
		acc = mult(s.rbegin()[i % l], acc);
		if (acc == 'k') {
			suffix = i + 1; break;
		}
	}

	return (prefix != 0 && suffix != 0 && prefix + suffix < x * l);
}

int main(void) {
	int t; cin >> t;
	fill();
	forn(k, t) {
		ull l, x; cin >> l >> x;
		string s; cin >> s;
		bool ans = solve(s, l, x);
		cout << "Case #" << (k+1) << ": " << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
