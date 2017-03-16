#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	int T;
	double C, F, X, speed, ans;
	scanf("%d", &T);
	for (int T0=1; T0 <= T; T0++) {
		printf("Case #%d: ", T0);
		scanf("%lf%lf%lf", &C, &F, &X);
		if (C > X) {
			printf("%.8lf\n", X/2);
			continue;
		}
		
		ans = 0; speed = 2;
		while (X * F - C * (speed + F) > 0) {
			ans += C/speed;
			speed += F;
		}
		printf("%.8lf\n", ans + X/speed);
	}
	return 0;
}

