#include <stdio.h>
#include <cstring>
#define eps 1e-8
#define maxl 1010

int n, a[maxl], sum;

bool check(int p, double l) {
	double low = a[p] + sum * l;

	double left = 0.0;
	for(int i=0; i<n; ++i) {
		if(p == i) continue;
		if((double)a[i] <= low) {
			left += low - a[i];
		}
	}

	return left > sum * (1 - l);
}

int main() {
	int t;
	scanf("%d", &t);
	for(int q=1; q<=t; ++q) {
		scanf("%d", &n);
		sum = 0;
		for(int i=0; i<n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
		}

		printf("Case #%d:", q);
		for(int i=0; i<n; ++i) {
			double l = 0.0, r = 1.0, ans = 0.0;
			while(l <= r + eps) {
				double mid = (l + r) / 2;
				if(check(i, mid)) {
					ans = mid;
					r = mid - eps;
				}
				else l = mid + eps;
			}
			printf(" %.8lf", ans * 100);
		}
		puts("");
	}
	return 0;
}

