#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t; cin >> t;
	for (int cas = 1; cas <= t; ++cas) {
		int x, r, c; cin >> x >> r >> c;
		string winner = "GABRIEL";
		if ((r * c) % x) { winner = "RICHARD"; goto out; }
		if (r + c <= x) { winner = "RICHARD"; goto out; }
		if (min(r, c) < (x + 1) / 2) { winner = "RICHARD"; goto out; }
		if (x == 4 && r * c == 8) { winner = "RICHARD"; goto out; }
		if (x >= 7) { winner = "RICHARD"; goto out; }
out:	cout << "Case #" << cas << ": " << winner << endl;
	}
}
