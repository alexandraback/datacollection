#include<algorithm>
#include<cstdio>
#include<ctime>
#include<iostream>
#include <cassert>
#include <string>
#include <bitset>

using namespace std;


double p[100100], sp[100100];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, t = 1;
	for (scanf("%d", &T); T--; ) {
		printf("Case #%d: ", t++);
		int A, B;
		double pp = 1.0;
		scanf("%d%d", &A, &B);
		for (int i = 0; i < A; i++) {
			scanf("%lf", &p[i]);
			pp *= p[i];
			sp[i] = i ? sp[i-1] * p[i] : p[i];
		}
		double ans = (B-A+1) + (B+1)*(1-pp); //keep typing
		ans = min(ans, (A == B ? pp*1 + (1-pp) * (B+2) : B+2)); //press enter right away
		for (int k = 1; k <= A; k++) {//backspace k times
			double _ans = sp[A-1-k]*(k*2 + B - A + 1) + (1-sp[A-1-k]) * (k*2 + B-A+1 + B+1);
			ans = min(ans, _ans);
		}
		printf("%.6f\n", ans);
	}
	return 0;
}
