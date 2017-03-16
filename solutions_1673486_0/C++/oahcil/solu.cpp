#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100010;

int a, b;
double p[MAXN];

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t ++){
		scanf("%d%d", &a, &b);
		double tmp = 1.0;
		p[0] = 1.0;
		for(int i = 1; i <= a; i ++){
			scanf("%lf", &tmp);
			p[i] = p[i - 1] * tmp;
		}
		double ans = b + 2;
		for(int i = 0; i <= a; i ++){
			double tmp = (a - i + 1 + b - i) * p[i] + (a - i + 1 + b - i + b + 1) * (1 - p[i]);
			ans = min(ans, tmp);
		}

		printf("Case #%d: %.6lf\n", t, ans);
	}

	return 0;
}