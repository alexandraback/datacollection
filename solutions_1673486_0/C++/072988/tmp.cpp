#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1 << 20;

int A, B;
double p[MAXN];
double sum[MAXN];

double cal(){
	sum[0] = 1.0;
	for(int i = 1; i <= A; i ++){
		sum[i] = sum[i - 1] * p[i];
	}
	double ans = B + 2;
	ans = min(ans, sum[A] * (B - A + 1) + (1 - sum[A]) * (B - A + 1 + B + 1));
	for(int i = 0; i <= A; i ++){
		double tmp = (A - i + 1 + B - i) * sum[i] + (A - i + 1 + B - i + B + 1) * (1 - sum[i]);
		ans = min(ans, tmp);
	}

	return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t ++){
		scanf("%d%d", &A, &B);
		for(int i = 1; i <= A; i ++){
			scanf("%lf", &p[i]);
		}
		printf("Case #%d: %.6lf\n", t, cal());
	}

	return 0;
}