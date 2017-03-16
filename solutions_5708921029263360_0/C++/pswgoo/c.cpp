#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i, s, t) for(int i(s); i<=(int)(t); i++)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int A, B, C, K;
int a[10][10][10];
int x[10][10], y[10][10], z[10][10];

bool ok() {
	REP(i, A) REP(j, B) {
		int sum = 0;
		REP(k, C) sum += a[i][j][k];
		if (sum > K) return false;
	}
	REP(i, A) REP(k, C) {
		int sum = 0;
		REP(j, B) sum += a[i][j][k];
		if (sum > K) return false;
	}
	REP(j, B) REP(k, C) {
		int sum = 0;
		REP(i, A) sum += a[i][j][k];
		if (sum > K) return false;
	}
	return true;
}

void Work(int casen) {
	cout << "Case #" << casen << ": ";
	cin >> A >> B >> C >> K;
	memset(a, 0, sizeof(a));
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(x));
	memset(z, 0, sizeof(x));
	if (K >= C) {
		REP(i, A) REP(j, B) REP(k, C) a[i][j][k] = 1;
	} else {
		REP(i, A) REP(j, B) REP(k, min(K, C))
			a[i][(j) % B][(i + j + k) % C] = 1;

		// while (1) {
		// 	int ii, jj, kk, v = K + 1;
		// 	REP(i, A) REP(j, B) REP(k, C) {
		// 		int q = max(x[j][k], max(y[i][k], z[i][j]));
		//
		// 		cout << i << ' ' << j << ' ' << k << ' ' << q << ' ' << x[j][k] << ' ' << y[i][k] << ' ' << z[i][j] << endl;
		// 		if (q >= v || a[i][j][k]) continue;
		// 		ii = i;
		// 		jj = j;
		// 		kk = k;
		// 		v = q;
		// 	}
		// 	cout << endl;
		// 	if (v >= K) break;
		// 	a[ii][jj][kk] = 1;
		// 	x[jj][kk]++;
		// 	y[ii][kk]++;
		// 	z[ii][jj]++;
		// }

		// int s = 0;
		// int oA = A;
		// int oB = B;
		// int oC = C;
		// while (oA > 0) {
		// 	REP(i, min(oA, K))
		// 	REP(j, min(oB, K))
		// 	REP(k, min(oC, K))
		// 		a[s + i][s + j][s + k] = 1;
		// 	s += K;
		// 	oA -= K;
		// 	oB -= K;
		// 	oC -= K;
		// }
	}
	if (!ok()) {
		cout << "Error" << endl;
	}
	int sum = 0;
	REP(i, A) REP(j, B) REP(k, C) sum += a[i][j][k];
	cout << sum << endl;
	REP(i, A) REP(j, B) REP(k, C) {
		if (a[i][j][k])
			cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		Work(i);
}
