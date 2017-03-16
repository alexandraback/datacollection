#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int testcases,R,C,M,bs;

bool check(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return true;
	return !(bs & (1<<(r*C+c)));
}
int reveal(int xbs, int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return xbs;
	xbs |= (1<<(r*C+c));
	return xbs;
}

int open(int xbs) {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (!(xbs & (1<<(r*C+c)))) continue;
			bool empty = (
				check(r-1,c-1) &&
				check(r-1,c) &&
				check(r-1,c+1) &&
				check(r,c-1) &&
				check(r,c) &&
				check(r,c+1) &&
				check(r+1,c-1) &&
				check(r+1,c) &&
				check(r+1,c+1)
			);
			if (!empty) continue;

			xbs = reveal(xbs, r-1,c-1);
			xbs = reveal(xbs, r-1,c);
			xbs = reveal(xbs, r-1,c+1);
			xbs = reveal(xbs, r,c-1);
			xbs = reveal(xbs, r,c);
			xbs = reveal(xbs, r,c+1);
			xbs = reveal(xbs, r+1,c-1);
			xbs = reveal(xbs, r+1,c);
			xbs = reveal(xbs, r+1,c+1);
		}
	}
	return xbs;
}

int main() {
	cin >> testcases;
	for (int tc = 1; tc <= testcases; tc++) {
		cin >> R >> C >> M;
		cout << "Case #" << tc << ":" << endl;

		int maxbs = 1<<(R*C);
		for (bs = 0; bs < maxbs; bs++) {
			if (__builtin_popcount(bs) != M) continue;
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					if (bs & (1<<(r*C+c))) continue;
					int xbs = (1<<(r*C+c)), prev_xbs = 0;
					while (xbs != prev_xbs) {
						prev_xbs = xbs;
						xbs = open(xbs);
					}
					//cout << bs << ' ' << r << ' ' << c << ' ' << xbs << endl;
					if (__builtin_popcount(xbs) == R*C-M) {
						for (int rd = 0; rd < R; rd++) {
							for (int cd = 0; cd < C; cd++) {
								if (rd == r && cd == c) {
									cout << 'c';
									continue;
								}
								cout << ((check(rd,cd)) ? '.' : '*');
							}
							cout << endl;
						}
						goto done;
					}
				}
			}
		}
		cout << "Impossible" << endl;
done:;
	}
}
