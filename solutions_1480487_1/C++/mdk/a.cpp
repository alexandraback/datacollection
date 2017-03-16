#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void bins(int x, int sum, const vector<int> & v) {
	double l = 0.0, r = 1.0;
	double perc = 0.0;
	while (r - l > 1e-8) {
		double mid = (l+r)/2.0;
		double pts = v[x] + mid*((double)sum);
		perc = 1.0 - mid;
		//printf("%d pts %lf (%lf %lf) ", x, pts, l, r);
		for (int i = 0 ; i < v.size(); i++) {
			if (i != x && pts > ((double) v[i])) {
				perc -= (pts - ((double)v[i])) / ((double)sum);
			}
			if (perc < 0.0) break;
		}
		if (perc < 0.0) {
			r = mid;
			//puts("tak");
		} else {
			l = mid;
			//puts("nie");
		}
	}
	if (perc>0.0) l = r;
	printf("%.8lf ", 100.0 * l);
}

void test() {
	int n, sum = 0;
	scanf("%d", &n);
	vector<int> j;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		j.push_back(a);
		sum += a;
	}
	for (int i= 0; i< n; i++) {
		bins(i, sum, j);
	}
	puts("");
}

main() {
	int t, cid=1;
	scanf("%d", &t);
	while (t--) {
		printf("Case #%d: ", cid++);
		test();
	}
}
