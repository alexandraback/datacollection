#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
long double C, F, X, Ans, cnt;

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int i, T0 = 0;
	scanf("%d", &T);
	for( ; T; --T) {
		cin >> C >> F >> X;
		cnt = 0;
		Ans = X / 2.0;
		for(i = 1; i; ++i) {
			long double v1 = F * (double)i + 2, Vx = F * (i - 1) + 2;
			double Ans1 = cnt + C / v1 + X / v1;
			if(cnt + C / Vx + X / v1 <= Ans) {
				Ans = cnt + C / Vx + X / v1;
				cnt += C / Vx;
			}
			else {
				break;
			}
		}
		double pA = Ans;
		printf("Case #%d: %.7lf\n", ++T0, pA);
	}
	return 0;
}
