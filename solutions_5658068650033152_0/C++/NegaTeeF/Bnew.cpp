#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool used1[20][20];
bool used2[20][20];

int qr[20 * 20];
int qc[20 * 20];
int n, m, k;
int lef, righ;

void go (int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m) return;
	if (!used2[r][c] && !used1[r][c]) {
		used2[r][c] = true;
		qr[righ] = r;
		qc[righ] = c;
		righ++;
	}
}

bool ok (int r, int c) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			used2[i][j] = false;
	if (r == 0 || r == n - 1 || c == 0 || c == m - 1) return true;
	lef = 0, righ = 1;
	qr[lef] = r;
	qc[lef] = c;
	used2[r][c] = true;
	while (lef < righ) {
		int R = qr[lef];
		int C = qc[lef];
		if (R == 0 || R == n - 1 || C == 0 || C == m - 1) return true;
		lef++;
		go(R - 1, C);
		go(R + 1, C);
		go(R, C - 1);
		go(R, C + 1);
	}
	return false;
}

int main () {
	int t;
	scanf ("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf ("%d%d%d", &n, &m, &k);
		int res = n * m + 1;
		for (int mask = 0; mask < (1 << (n * m)); mask++) {
			if (__builtin_popcount(mask) >= res) continue;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					used1[i][j] = false;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					used1[i][j] = ((mask >> (i * m + j)) & 1);
			int cur = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					if (used1[i][j] || !ok(i, j))
						cur++;
				}
			if (cur >= k) res = __builtin_popcount(mask);
		}
		printf ("Case #%d: %d\n", tt + 1, res);
	}
}

