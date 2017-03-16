#include <stdio.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
struct dat {
	int j, p, s;
} a[333];
int J, P, S, K, an, res, rbit, b[33];
int da[333], db[333], dc[333];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, runs; for (scanf("%d", &T), runs = 1; T--; runs++) {
		printf("Case #%d: ", runs);
		scanf("%d%d%d%d", &J, &P, &S, &K);
		an = 0;
		for (int i = 0; i < 13; i++) da[i] = db[i] = dc[i] = 0;
		for (int i = 1; i <= J; i++) {
			for (int j = 1; j <= P; j++) {
				for (int k = 1; k <= S; k++) {
					a[an++] = { i, j, k };
					da[i * P + j]++;
					db[j * S + k]++;
					dc[i * S + k]++;
				}
			}
		}
		int mm = 0;
		for (int i = 0; i < 13; i++) {
			mm = max(mm, da[i]);
			mm = max(mm, db[i]);
			mm = max(mm, dc[i]);
		}
		if (mm <= K) {
			printf("%d\n", an);
			for (int i = 0; i < an; i++) printf("%d %d %d\n", a[i].j, a[i].p, a[i].s);
			continue;
		}
		res = rbit = 0;
		for (int bit = (1 << an) - 1; bit >= 1; bit--) {
			int cnt = 0, bn = 0;
			for (int i = 0; i < an; i++) if ((1 << i)&bit) cnt++, b[bn++] = i;
			if (cnt <= res) continue;
			for (int i = 0; i < 13; i++) da[i] = db[i] = dc[i] = 0;
			bool ok = 1;
			for (int k = 0; k < bn; k++) {
				int i = b[k];
				da[a[i].j * P + a[i].p]++;
				db[a[i].p * S + a[i].s]++;
				dc[a[i].j * S + a[i].s]++;
				if (da[a[i].j * P + a[i].p] > K) {
					ok = 0;
					break;
				}
				if (db[a[i].p * S + a[i].s] > K) {
					ok = 0;
					break;
				}
				if (dc[a[i].j * S + a[i].s] > K) {
					ok = 0;
					break;
				}
			}
			if (ok && cnt > res) {
				res = cnt;
				rbit = bit;
			}
		}
		printf("%d\n", res);
		for (int i = 0; i < an; i++) {
			if ((1 << i)&rbit) {
				printf("%d %d %d\n", a[i].j, a[i].p, a[i].s);
			}
		}
	}
}