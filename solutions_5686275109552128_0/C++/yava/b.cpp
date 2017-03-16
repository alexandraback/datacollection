#include <stdio.h>

int n;
int a[1024];

void Solve() {
	scanf("%d", &n);
	int mx = 0;
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > mx) {
			mx = a[i];
		}
	}
	int best = mx;
	for (int k=1; k<=mx; k++) {
		int cur = k;
		for (int i=0; i<n; i++) {
			cur += (a[i]-1)/k;
		}
		if (best > cur) {
			best = cur;
		}
	}
	printf("%d\n", best);
}

int main() {
	int t = 0;
	scanf("%d", &t);
	for (int i=1; i<=t; i++) {
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
