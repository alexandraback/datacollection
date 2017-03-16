#include <cstdio>
#include <algorithm>

using namespace std;

struct p {
	int ju, i;
	long double au;
};

bool lju(const p& p1, const p& p2) {
	return p1.ju < p2.ju;
}

bool li(const p& p1, const p& p2) {
	return p1.i < p2.i;
}

p a[200];

const long double eps = 1e-8;

int main() {
	int t;
	scanf("%i", &t);
	for(int ti = 0; ti < t; ti++) {
		printf("Case #%i: ", ti + 1);
		int n;
		scanf("%i", &n);
		for(int i = 0; i < n; i++) scanf("%i", &a[i].ju);
		for(int i = 0; i < n; i++) a[i].i = i;
		long double x = 0;
		for(int i = 0; i < n; i++) x += a[i].ju;
		sort(a, a + n, lju);
		int ii;
		for(ii = 0; ii < n; ii++) if(2.0 / n - a[ii].ju / x < -eps) break;
		long double xx = 0;
		for(int i = 0; i < ii; i++) xx += a[i].ju;
		for(int i = ii; i < n; i++) a[i].au = 0;
		for(int i = 0; i < ii; i++) a[i].au = (1.0 + xx / x ) / ii - a[i].ju / x;
		sort(a, a + n, li);
		for(int i = 0; i < n; i++) printf("%.6lf ", static_cast<double>(a[i].au) * 100);
		printf("\n");
	}
	return 0;
}

