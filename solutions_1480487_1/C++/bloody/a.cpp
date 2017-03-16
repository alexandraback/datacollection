#include <cstdio>
#include <cstring>
#include <iostream>

#define eps 1e-9
#define precision 1e-7

int N;
int inp[256];
double X;
int cur = 0;

inline bool gt(double a, double b) {
	return (a - b) > eps;
}

bool chk(int pts,  double mid) {

	double diff = (mid - pts);
	for (int i=0;i<N;++i) {
		if (cur == i) continue;
		if (mid > inp[i]) {
			double d2 = (mid - inp[i]);
			diff += d2;
			if (gt(diff, X)) return true;
		}
	}
	return false;
}

double search(int pts, double a, double b) {
	double mid = (b+a)/2;
	//printf("%lf %lf %lf\n", a, b,mid);
	if (b - a < precision) {
		return mid;
	}
	bool ok = chk(pts, mid);
	
	if (ok) {
		return search(pts, a, mid);
	} else {
		return search(pts, mid, b);
	}
}

int main() {
	int T;
	scanf(" %d", &T);
	for (int i=0;i<T;++i) {
		printf("Case #%d: ", (i+1));
		scanf(" %d", &N);
		X= 0;
		for (int i=0;i<N;++i) {
			scanf("%d", &inp[i]);
			X += inp[i];
		}
		cur = 0;
		for (int i=0;i<N;++i) {
			cur = i;
			double mi = search(inp[i], inp[i], inp[i] + X);
//			printf("%lf %d %d\n", mi, X, inp[i]);
			printf("%.6lf ", ((mi - inp[i])/ X) * 100);
		}
		printf("\n");
	}
	return 0;
}
