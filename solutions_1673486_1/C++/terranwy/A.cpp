#include <cstdio>

const int maxn = 99999;

int casei, cases, A, B;
double ans;
double pro[maxn];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d%d", &A, &B);
		for (int i = 0; i < A; ++i) scanf("%lf", pro + i);
		ans = B + 2;
		double p = 1, tmp;
		for (int i = 0; i < A; ++i) {
			p *= pro[i];
			tmp = p * (B - (i << 1) + A - 1) + (1 - p) * (((B - i) << 1) + A);
			if (tmp < ans) ans = tmp;
		}
		printf("Case #%d: %.7lf\n", casei, ans);
	}
	
}
