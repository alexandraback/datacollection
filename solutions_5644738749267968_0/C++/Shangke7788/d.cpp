#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAX_N = 1010;
double a[MAX_N], b[MAX_N];
int n;

int gao(double a[], double b[]) {
	int res = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[j]) {
			j++, res++;
		}
	}
	return res;
}

int main() {
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf", a + i);
		}
		for (int i = 0; i < n; i++) {
			scanf("%lf", b + i);
		}
		sort(a, a + n), sort(b, b + n);
		printf("Case #%d: %d %d\n", ca, gao(a, b), n - gao(b, a));
	}
	return 0;
}
