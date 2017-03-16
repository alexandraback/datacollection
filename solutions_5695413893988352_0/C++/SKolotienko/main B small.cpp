#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

using namespace std;

void test()
{
	string xs, ys;
	cin >> xs >> ys;

	int bestDif = INT_MAX;
	string bestXs;
	string bestYs;

	if (xs.length() == 1) {
		for (int xa = 0; xa < 10; xa++) {
			if (xs[0] != '?' && xs[0] != '0' + xa) continue;
			int x = xa;

			for (int ya = 0; ya < 10; ya++) {
				if (ys[0] != '?' && ys[0] != '0' + ya) continue;
				int y = ya;

				int dif = abs(x - y);
				if (dif < bestDif) {
					bestDif = dif;
					bestXs = xs;
					bestXs[0] = '0' + xa;
					bestYs = ys;
					bestYs[0] = '0' + ya;
				}
			}
		}
	} else if (xs.length() == 2) {
		for (int xa = 0; xa < 10; xa++) {
			if (xs[0] != '?' && xs[0] != '0' + xa) continue;
			for (int xb = 0; xb < 10; xb++) {
				if (xs[1] != '?' && xs[1] != '0' + xb) continue;
				int x = xa * 10 + xb;

				for (int ya = 0; ya < 10; ya++) {
					if (ys[0] != '?' && ys[0] != '0' + ya) continue;
					for (int yb = 0; yb < 10; yb++) {
						if (ys[1] != '?' && ys[1] != '0' + yb) continue;
						int y = ya * 10 + yb;

						int dif = abs(x - y);
						if (dif < bestDif) {
							bestDif = dif;
							bestXs = xs;
							bestXs[0] = '0' + xa;
							bestXs[1] = '0' + xb;
							bestYs = ys;
							bestYs[0] = '0' + ya;
							bestYs[1] = '0' + yb;
						}
					}
				}
			}
		}
	} else if (xs.length() == 3) {
		for (int xa = 0; xa < 10; xa++) {
			if (xs[0] != '?' && xs[0] != '0' + xa) continue;
			for (int xb = 0; xb < 10; xb++) {
				if (xs[1] != '?' && xs[1] != '0' + xb) continue;
				for (int xc = 0; xc < 10; xc++) {
					if (xs[2] != '?' && xs[2] != '0' + xc) continue;
					int x = xa * 100 + xb * 10 + xc;

					for (int ya = 0; ya < 10; ya++) {
						if (ys[0] != '?' && ys[0] != '0' + ya) continue;
						for (int yb = 0; yb < 10; yb++) {
							if (ys[1] != '?' && ys[1] != '0' + yb) continue;
							for (int yc = 0; yc < 10; yc++) {
								if (ys[2] != '?' && ys[2] != '0' + yc) continue;
								int y = ya * 100 + yb * 10 + yc;

								int dif = abs(x - y);
								if (dif < bestDif) {
									bestDif = dif;
									bestXs = xs;
									bestXs[0] = '0' + xa;
									bestXs[1] = '0' + xb;
									bestXs[2] = '0' + xc;
									bestYs = ys;
									bestYs[0] = '0' + ya;
									bestYs[1] = '0' + yb;
									bestYs[2] = '0' + yc;
								}
							}
						}
					}
				}
			}
		}
	}

	cout << bestXs << " " << bestYs;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "Case #" << i + 1 << ": ";
		test();
		cout << endl;
	}
	return 0;
}
