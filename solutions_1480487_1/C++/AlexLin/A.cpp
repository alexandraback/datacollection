#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

#define Rep(i,n) for(int i = 0; i < n; ++i)
#define Rep2(i, f, t) for(int i = (f); i <= (t); ++i)
#define tr(C,it) for(__typeof__((C).begin()) it = (C).begin(); it != (C).end(); ++it)

const int maxn = 200 + 10;
int s[maxn];
int n, X;
bool isOK(double curs, double y) {
	double sp = 0.0;
	for(int i = 0;i < n; ++i) 
	{
		double p = (double)(curs - s[i]) / X + y;
		if(p >= 1.0)return true;
		if(p > 0.0)
			sp += p;
	}
	if(sp >= 1.0)return true;
	return false;
}

double getAns(int pos) {
	double L = 0.0, R = 1.0;
	int times = 50;
	while(times--) {
		double mid = (L + R) * 0.5;
		if(isOK(s[pos], mid)) {
			R = mid;
		} else {
			L = mid;
		}
	}
	return R;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for(int nCase = 1; nCase <= tc;++nCase) {
		printf("Case #%d:", nCase);
		scanf("%d", &n);
		X = 0;
		Rep(i, n) {
			scanf("%d", s + i);
			X += s[i];
		}

		Rep(i, n) {
			double ans = getAns(i) * 100.0;
			printf(" %.7f", ans);
		}
		puts("");
	}
	return 0;
}

