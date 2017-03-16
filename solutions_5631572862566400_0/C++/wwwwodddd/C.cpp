#include <iostream>
#include <cstring>
using namespace std;
int t, n;
int a[1020];
int v[1020];
int f[1020];
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		memset(f, 0, sizeof f);
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int z = 0;
		for (int i = 1; i <= n; i++) {
			int s = i;
			int cnt = 1;
			memset(v, 0, sizeof v);
			while (v[s] == 0) {
				v[s] = cnt++;
				s = a[s];
			}
			z = max(z, cnt - v[s]);
			int t = i;
			cnt = 1;
			while (true) {
				f[t] = max(f[t], v[t]);
				if (t == s) {
					break;
				}
				t = a[t];
			}
		}
		int s = 0;
		for (int i = 1; i <= n; i++) {
			if (i < a[i] && i == a[a[i]]) {
				s += f[i] + f[a[i]];
			}
		}
		z = max(z, s);
		printf("Case #%d: %d\n", tt, z);
	}
	return 0;
}