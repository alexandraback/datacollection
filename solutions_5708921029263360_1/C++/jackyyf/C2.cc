#include <bits/stdc++.h>

using namespace std;

long placed[16][16][16];
long j, p, s, k;

int main(void) {
	ios::sync_with_stdio(false);
	long T;
	cin >> T;
	for (long t = 1; t <= T; ++ t) {
		cin >> j >> p >> s >> k;
		k = min(s, k);
		cout << "Case #" << t << ": " << j * p * k << endl;
		memset(placed, 0, sizeof placed);
	/*
		// Step 1: row
		for (long x = 0; x < k; ++ x) {
			placed[0][0][x] = 1;
		}
		// Step 2: surface
		for (long x = 1; x < p; ++ x) {
			for (long y = 0; y < k; ++ y) {
				placed[0][x][(x + y) % s] = 1;
			}
		}
	*/
		// Step 3: cube
		for (long x = 0; x < j; ++ x) {
			for (long y = 0; y < p; ++ y) {
				for (long z = 0; z < k; ++ z) {
					// placed[x][y][(x + y + z) % s] = 1;
					cout << x + 1 << " " << y + 1 << " " << (x + y + z) % s + 1 << endl;
				}
			}
		}
	}
}
