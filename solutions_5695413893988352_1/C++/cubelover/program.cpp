#include <cstdio>
#include <algorithm>

using namespace std;

char a[22], b[22];
char ra[22], rb[22];
int d[22];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc, tcn;
	scanf("%d", &tcn);
	for (tc = 1; tc <= tcn; tc++) {
		long long mx, mn, m, t, r;
		int i, j, k;
		scanf("%s%s", a, b);
		for (i = 0; a[i]; i++);
		t = 1;
		mx = mn = m = 0;
		while (i--) {
			r = 9e18;
			for (j = 0; j < 10; j++) if (a[i] == '?' || a[i] - 48 == j) for (k = 0; k < 10; k++) if (b[i] == '?' || b[i] - 48 == k)
				if (abs((j - k) * t + (j < k ? mx : j > k ? mn : m)) < r) {
					r = abs((j - k) * t + (j < k ? mx : j > k ? mn : m));
					ra[i] = j + 48;
					rb[i] = k + 48;
					d[i] = j < k ? -1 : j > k ? 1 : 0;
				}
			mx += t * ((a[i] == '?' ? 9 : a[i] - 48) - (b[i] == '?' ? 0 : b[i] - 48));
			mn += t * ((a[i] == '?' ? 0 : a[i] - 48) - (b[i] == '?' ? 9 : b[i] - 48));
			m = r;
			t *= 10;
		}
		for (i = 0; a[i] && !d[i]; i++);
		if (a[i]) {
			j = d[i];
			while (a[++i]) {
				ra[i] = (a[i] == '?' ? j > 0 ? '0' : '9' : a[i]);
				rb[i] = (b[i] == '?' ? j > 0 ? '9' : '0' : b[i]);
			}
		}
		ra[i] = rb[i] = 0;
		printf("Case #%d: %s %s\n", tc, ra, rb);
	}
	return 0;
}