#include <bits/stdc++.h>
using namespace std;
double C, F, X;
int TC;
int main () {
	freopen("cookieclicker.in", "r", stdin);
	freopen("cookieclicker.out", "w", stdout);
	
	scanf("%d", &TC);
	for (int T = 1; T <= TC; ++T) {
		scanf("%lf%lf%lf", &C, &F, &X);
		
		double cur = 0.0, ans = X/2.0, rate = 2.0;
		while (cur < ans) {
			cur += C/rate;
			rate += F;
			ans = min(ans, cur+(X/rate));
		}
		printf("Case #%d: %.7lf\n", T, ans);
	}
}
