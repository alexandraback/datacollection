#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include <algorithm>

#define REP(i, n) for (int i = 0; i < (n); i++) 

using namespace std;

const int N = 1024;

int main() {
	freopen("D:/d-large.in", "r", stdin);
	freopen("D:/d-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	double a[N], b[N];
	REP(t, T) {
		int n;
		scanf("%d", &n);
		REP(i, n) scanf("%lf", &a[i]);
		REP(i, n) scanf("%lf", &b[i]);
		sort(a, a + n);
		sort(b, b + n);
		int dec = 0, normal = 0;
		int ai = 0, bi = 0;
		while (ai < n) {
			if (b[bi] > a[ai]) {
				// bj--
			} else {
				bi++;
				dec++;
			}
			ai++;
		}
		int aj = n - 1, bj = n - 1;
		while (aj >= 0) {
			if (b[bj] > a[aj]) {
				bj--;
			} else {
				normal++;
			}
			aj--;
		}
		printf("Case #%d: %d %d\n", t + 1, dec, normal);
	}
	return 0;
}