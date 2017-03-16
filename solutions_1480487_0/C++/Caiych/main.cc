#include <stdio.h>
#include <algorithm>

using namespace std;

int a[400],n,T;

int main() {
	scanf("%d",&T);
	for (int cas = 1;cas <= T;cas++) {
		scanf("%d",&n);
		int s = 0;
		for (int i = 0;i < n;i++) {
			scanf("%d",&a[i]);
			s += a[i];
		}
		printf("Case #%d:",cas);
		double le = s * 2,ri = s * 2;
		for (int i = 0;i < n;i++) 
			le = min(le,1.0 * a[i]);
		while (ri - le > 1e-8) {
			double mid = 0.5 * (le + ri);
			double nn = 0;
			for (int i = 0;i < n;i++) {
				nn += max(0.0,(mid - a[i]));
			}
			if (nn >= s) ri = mid;
			else le = mid;
		}
		for (int i = 0;i < n;i++) {
			printf(" %.6lf",max(0.0,100.0 * (ri - a[i]) / s));
		}
		printf("\n");
	}
	return 0;
}
