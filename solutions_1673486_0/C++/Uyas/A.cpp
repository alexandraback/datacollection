#include <cstdio>
#include <algorithm>
using namespace std;

double a[1010];
int n, m;
double planA() {
	double ret = 0;
	double prob = 1;
	for (int i = 1; i <= n; ++i) prob *= a[i];
	ret = prob * (m - n) + (1 - prob) * (m - n + 1 + m);
	return ret + 1;
}

double planB() {
	double ret = 1e20;
	double prob = 1;
	for (int i = 1; i <= n; ++i) {
		int fill = n - i + 1 + m - i + 1;
		ret = min(ret, prob * fill + (1 - prob) * (fill + 1 + m));
		prob *= a[i];
	}
//	ret += prob * (m - n);
	return ret + 1;
}

double planC() {
	return 2 + m;
}

int main() {
	freopen("A01.in", "r", stdin);
	freopen("A01.txt", "w", stdout);
	int task; scanf("%d", &task);
	for (int cas = 1; cas <= task; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) scanf("%lf", &a[i]);
		double x = planA(), 
			   y = planB(),
			   z = planC();
		double ans = min(z, min(x, y));
//		printf("%f %f %f\n", x, y, z);
		printf("Case #%d: %.6f\n", cas, ans);
	}
	return 0;
}
		
