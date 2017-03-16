#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;
const int maxn = 100000 + 5;
int t, n, a[maxn], b[maxn];
bool geta[maxn], getb[maxn];

int main() {
	scanf("%d", &t);
	for (int index = 1; index <= t; ++index) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d%d", &a[i], &b[i]);
		fill(geta, geta + n + 1, false);
		fill(getb, getb + n + 1, false);
		int s = 0, has = 0, len = 0;
		while (has < n) {
			int get = 0;
			for (int i = 1; i <= n; ++i)
				if (!getb[i] && b[i] <= s) {
					getb[i] = true;
					get = 1;
					s += geta[i] ? 1 : 2;
					++has;
					++len;
				}
			if (get) {
				continue;
			}
			int j = 0, max2 = -1;
			for (int i = 1; i <= n; ++i)
				if (!getb[i] && !geta[i] && a[i] <= s && max2 < b[i]) {
					max2 = b[i];
					j = i;
				}
			if (j) {
				geta[j] = true;
				++s;
				++len;
				continue;
			}
			goto BAD;
		}
		printf("Case #%d: %d\n", index, len);
		continue;
BAD:
		printf("Case #%d: Too Bad\n", index);
	}
	return 0;
}
