#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int a[500];
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cs, n;
	scanf("%d", &cs);
	for (int test = 1; test <= cs; ++test) {
		scanf("%d", &n);
		double s = 0;
		for (int i = 1; i <= n ; ++i) {
			scanf("%d", &a[i]);
			s += a[i];
		}
		double l = 0, r = s, mid, tmp;
		while (l + 1e-10 < r) {
			mid = (l + r ) / 2; tmp = 0;
			for (int i = 1; i <= n ; ++i)
			if (mid > a[i]) tmp += mid - a[i];
			if (tmp > s) r = mid;
			else l = mid;
		}
		printf("Case #%d: ", test);
	//	cout << l << endl;
		for (int i = 1; i <= n ; ++i) {
			tmp = (l - a[i]) / s * 100;
			if (a[i] > l) printf("0.0000000 ");
			else printf("%.10lf ", tmp);
		}
		printf("\n");
	}
	return 0;
}