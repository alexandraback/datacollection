#include <iostream>
#include <cstdio>
#define MAXN 100003
using namespace std;

double p[MAXN];
double ms[MAXN];

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);

	int dataset;
	int a;
	int b;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d %d", &a, &b);
		p[0] = 0;
		ms[0] = 1;
		for(int i=1; i<=a; ++i) {
			scanf("%lf", &p[i]);
			ms[i] = ms[i-1] * p[i];
		}
		double key = 2e9;

		// case 1
		// case 2
		for(int ok = 0; ok<=a; ++ok) {
			double tp = ms[ok];
			double bs = a-ok;
			double tmp_ans = tp*(bs+b-ok+1) + (1-tp)*(bs+b-ok+1+b+1);
			key = min(key, tmp_ans);
		}

		// case 3
		double case_3 = 1 + b + 1;
		key = min(key, case_3);

		printf("Case #%d: %.8lf\n", cas, key);

	}

	return 0;
}
