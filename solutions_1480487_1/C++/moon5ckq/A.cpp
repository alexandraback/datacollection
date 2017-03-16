#include <cstdio>
#define oo 205
int a[oo];
int n;

inline void Readin() {
	scanf("%d", &n);
	for (int i=1;i<=n;++i)
		scanf("%d", a+i);
}

inline void Solve() {
	int x= 0;
	for (int i=1;i<=n;++i)
		x+=a[i];
	
	double l = 0, r = x*2;
	while (l+1E-8 < r) {
		double mid = (l + r) / 2;
		
		double rest = 0;
		for (int j=1;j<=n;++j)
			if (a[j] < mid) rest += mid - a[j];
		if (rest < x) l = mid;
		else r = mid;
	}
	
	for (int i=1;i<=n;++i) {
		if (l < a[i]) printf(" 0.0000000");
		else printf(" %.6lf",(l-a[i]) / x * 100);
	}
	
	puts("");
}


int main() {
	int Case, Test;
	scanf("%d", &Test);
	for (Case = 1; Case <= Test; ++Case) {
		printf("Case #%d:", Case);
		Readin();
		Solve();
	}
	
	return 0;
}
