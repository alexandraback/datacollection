#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 256;
const double INF = 9999999999999999.9;

double s[MAXN], p[MAXN];

double gao(const int ss, const int n, const double x) {
	int i, j, k;
	int tc(50);
	double left, right, mid, ret;
	double sum, cp;
	
	left = 0, right = 1;
	while (tc--) {
		mid = (left + right) / 2.0;
//		mid = 1.0 / 6;
		sum = 0;
		for (i=0; i<n; ++i) {
			cp = max(0.0, (ss + x * mid - s[i]) / x);
			sum += cp;
		}
		if (sum >= 1) right = mid;
		else left = mid;
	}
	return right * 100;
}

int main() {
	int i, j, k;
	int m, n;
	int tc, cn(0);
	double x, mn;
	
	//freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	
	freopen("A-small-attempt3.in", "r", stdin);
//	freopen("res.txt", "w", stdout);
	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		x = 0;
		for (i=0; i<n; ++i) scanf("%lf", s+i), x += s[i];
		for (i=0; i<n; ++i) {
			p[i] = gao(s[i], n, x);
		}
		printf("Case #%d:", ++cn);
		for (i=0; i<n; ++i) printf(" %.6lf", p[i]);
		puts("");
	}

	return 0;
}