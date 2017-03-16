#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <math.h>
using namespace std;

int i, j, k, kejsis, kejs, n, m;
int ret;
long long a[100], A[100], b[100], B[100];

long long go(int p, int q) {
	long long ret = 0, d = 0;
	if (p >= n || q >= m) return 0;
	if (A[p] == B[q]) {
		d = min(a[p], b[q]);
		a[p] -= d;
		b[q] -= d;
		ret = d;
	}
	ret = max(ret+go(p+1, q), ret+go(p, q+1));
	a[p] += d;
	b[q] += d;
	return ret;
}

int main() {
	scanf("%d", &kejsis);
	for (int kejs = 1; kejs <= kejsis; ++kejs) {
		printf("Case #%d: ", kejs);
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++) scanf("%lld%lld", &a[i], &A[i]);
		for (i = 0; i < m; i++) scanf("%lld%lld", &b[i], &B[i]);
		long long mx = 0;
		if (n == 1) {
			for (i = 0; i < m; i++) {
				if (B[i] == A[0]) {
					if (a[0] > 0) {
						if (a[0] >= b[i]) {
							a[0] -= b[i];
							mx += b[i];
						} else if (a[0] < b[i]) {
							mx += a[0];
							a[0] = 0;
						}
					}
				}
			}
		}
		printf("%lld\n", go(0, 0));
	}
	return 0;
}
