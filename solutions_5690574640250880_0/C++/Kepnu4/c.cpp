#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <numeric>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

const int di[] = {1, 1, -1, -1, 0, 0, 1, -1};
const int dj[] = {1, -1, 1, -1, 1, -1, 0, 0};

int n, m, k, a[105][105];

void load() {
	cin >> n >> m >> k;
	k = m * n - k;
}

void print (bool rev) {
	bool c = false;
	for (int i = 0;i < (rev ? m : n);i++) {
		for (int j = 0;j < (rev ? n : m);j++) {
			int t = (rev ? a[j][i] : a[i][j]);
			if (!c) {
				if (t == 100) {
					printf ("c");
					c = true;
					continue;
				}
			} 
			printf ("%c", t ? '.' : '*');
		}
		printf ("\n");
	}
}

bool good (int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

int calc (int i, int j) {
	int res = 0;
	for (int k = 0;k < 8;k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (good (ni, nj) && a[ni][nj] == 0) res++;
	}
	if (res == 0) res = 100;
	a[i][j] = res;
	return res;
}

void recalc (int i, int j) {
	calc (i, j);
	for (int k = 0;k < 8;k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (good (ni, nj) && a[ni][nj] != 0) calc (ni, nj);
	}
}

void solve(int test) {
	memset (a, 0, sizeof (a));
	printf ("Case #%d:\n", test);

	bool rev = false;
	if (n > m) {
		swap (n, m);
		rev = true;
	}

	if (n == 1 || k == 1) {
		a[0][0] = 100;
		for (int i = 1;i < k;i++) {
			a[0][i] = 1;
		}	
		print (rev);
		return;
	}

	if (k == m * n) {
		memset (a, 1, sizeof (a));
		a[0][0] = 100;
		print (rev);
		return;
	}

	if (k == 2 || k == 3 || k == 5 || k == 7 || (n == 2 && k % 2 == 1)) {
		printf ("Impossible\n");
		return;
	}

	int t = k % 2;
	for (int i = 0;i < 2 + t;i++) {
		for (int j = 0;j < 2 + t;j++) {
			a[i][j] = 1;
		}
	}
	for (int i = 0;i < 2 + t;i++) {
		for (int j = 0;j < 2 + t;j++) {
			calc (i, j);
		}
	}

	k -= (t ? 9 : 4);

	while (k > 0) {
		int pi = -1, pj = -1;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (a[i][j] == 2) {
					pi = i;
					pj = j;
				}
			}
		}

		if (pi == -1 && pj == -1) {
			for (int q = 0;q < 2;q++) {
				pi = -1;
				pj = -1;
				for (int i = 0;i < n;i++) {
					for (int j = 0;j < m;j++) {
						if (a[i][j] == 1) {
							pi = i;
							pj = j;
						}
					}
				}
				for (int kk = 0;kk < 8;kk++) {
					int ni = pi + di[kk];
					int nj = pj + dj[kk];

					if (good (ni, nj) && a[ni][nj] == 0) {
						a[ni][nj] = 1;
						recalc (ni, nj);
					}
				}
			}
			k -= 2;
			continue;
		}

		for (int kk = 0;kk < 8;kk++) {
			int ni = pi + di[kk];
			int nj = pj + dj[kk];

			if (good (ni, nj) && a[ni][nj] == 0) {
				a[ni][nj] = 1;
				recalc (ni, nj);
			}
		}
		k -= 2;
	}

	print (rev);
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		cerr << "solving " << i << endl;
 		load();
 		solve(i);
 	}

 	return 0;
}