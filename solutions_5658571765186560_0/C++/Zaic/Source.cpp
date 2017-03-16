#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cinttypes>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;

int x, r, c;

bool isFail() {
	int minv = min(r, c);
	int maxv = max(r, c);
	if (r * c % x != 0) return true;
	if (x > max(r, c)) return true;
	if (x > min(r, c) * 2) return true;

	if (x >= 7) return true;
	if (x == 4) {
		if (minv == 2 && maxv == 4) return true;
	}

	return false;
}


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int TT; cin >> TT;
	for (int T = 1; T <= TT; ++T) {
		cin >> x >> r >> c;
		string res = (isFail() ? "RICHARD" : "GABRIEL");
		cout << "Case #" << T << ": " << res << endl;
	}
	return 0;
}