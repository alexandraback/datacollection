#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main() {
	int num_tests;
	cin >> num_tests;
	for (int test = 1; test <= num_tests; ++test) {
		int h, w, d;
		cin >> h >> w >> d;
		string s;
		getline(cin, s);
		
		vector<string> g(h);
		int xi, xj;
		for (int i = 0; i < h; ++i) {
			getline(cin, g[i]);
			for (int j = 0; j < w; ++j) {
				if (g[i][j] == 'X') {
					xi = 2*i - 1;
					xj = 2*j - 1;
					break;
				}
			}
		}

		set<pair<int, int> > dir;
		int hh = 2*(h - 2);
		int ww = 2*(w - 2);
		int dd = 2*d;

		int mo = max(dd / hh, dd / ww) + 1;
		for (int mi = -mo; mi <= mo; ++mi) {
			for (int mj = -mo; mj <= mo; ++mj) {
				if (mi == 0 && mj == 0) {
					continue;
				}
				int yi = xi;
				if (mi > 0) {
					int ri = hh - xi;
					for (int k = 1; k <= mi; ++k) {
						yi += 2*ri;
						ri = hh - ri;
					}
				} else {
					int ri = xi;
					for (int k = 1; k <= -mi; ++k) {
						yi -= 2*ri;
						ri = hh - ri;
					}
				}
				int yj = xj;
				if (mj > 0) {
					int rj = ww - yj;
					for (int k = 1; k <= mj; ++k) {
						yj += 2*rj;
						rj = ww - rj;
					}
				} else {
					int rj = yj;
					for (int k = 1; k <= -mj; ++k) {
						yj -= 2*rj;
						rj = ww - rj;
					}
				}

				int di = yi - xi;
				int dj = yj - xj;
				if (di*di + dj*dj <= dd*dd) {
					int gg = gcd(abs(di), abs(dj));
					di /= gg;
					dj /= gg;
					dir.insert(make_pair(di, dj));
				}
			}
		}

		cout << "Case #" << test << ": " << dir.size() << endl;
	}
}
