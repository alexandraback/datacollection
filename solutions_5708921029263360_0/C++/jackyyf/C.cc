#include <bits/stdc++.h>

using namespace std;

long j, p, s, k;

bool placed[4][4][4];
long rcnt[4][4][4];
bool ans[4][4][4];
long anscnt;
long cnt;

bool check() {
	memset(rcnt, 0, sizeof rcnt);
	for (long x = 0; x < j; ++ x) {
		for (long y = 0; y < p; ++ y) {
			for (long z = 0; z < s; ++ z) {
				if (placed[x][y][z]) {
					if (++ rcnt[0][x][y] > k)
						return false;
					if (++ rcnt[1][x][z] > k)
						return false;
					if (++ rcnt[2][y][z] > k)
						return false;
				}
			}
		}
	}
	return true;
}

void solve(long x, long y, long z) {
	if (z == s) {
		z = 0;
		++ y;
	}
	if (y == p) {
		y = 0;
		++ x;
	}
	if (x == j) {
		if (!check()) return;
		if (cnt > anscnt) {
			memcpy(ans, placed, sizeof(ans));
			anscnt = cnt;
		}
		return ;
	}
	placed[x][y][z] = 1;
	cnt += 1;
	solve(x, y, z + 1);
	placed[x][y][z] = 0;
	cnt -= 1;
	solve(x, y, z + 1);
}


int main(void) {
	long T;
	cin >> T;
	for(long t = 1; t <= T; ++ t) {
		cin >> j >> p >> s >> k;
		memset(placed, 0, sizeof placed);
		anscnt = 0;
		solve(0, 0, 0);
		cout << "Case #" << t << ": " << anscnt << endl;
		for (long x = 0; x < j; ++ x) {
			for (long y = 0; y < p; ++ y) {
				for (long z = 0; z < s; ++ z) {
					if (ans[x][y][z]) {
						cout << x + 1 << " " << y + 1 << " " << z + 1 << endl;
					}
				}
			}
		}
	}
}
