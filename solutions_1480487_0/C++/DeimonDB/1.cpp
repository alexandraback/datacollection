#include <cstdio>
#include <algorithm>
using namespace std;
const double EPS = 1e-8;
double data[205];
int N;
double tot;
bool bisa(double mid, int idx) {
	double sisa = 100.0 - mid;
	double target = data[idx] + (mid * tot / 100.0);
	for (int i = 0; i < N; i++) {
		if (i == idx || target - data[i] < 0)
			continue;
		double persen;
		persen = (target - data[i]) / tot * 100.0;
		if (sisa < persen) {
			return true;
		}
		sisa -= persen;
	}
	return sisa < EPS;
}
inline void solve(int tc) {
	scanf("%d", &N);
	tot = 0;
	for (int i = 0; i < N; i++) {
		scanf("%lf", &data[i]);
		tot += data[i];
	}
	
	printf("Case #%d: ", tc + 1);
	
	for (int i = 0; i < N; i++) {
		double lo, hi, mid;
		lo = 0;
		hi = 100;
		for (int j = 0; j < 2000; j++) {
			mid = (lo + hi)/2.0;
			if (bisa(mid, i))
				hi = mid;
			else
				lo = mid;
		}
		printf("%.6lf", hi);
		if (i < N-1)
			printf(" ");
	}
	puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) solve(i);
	return 0;
}
