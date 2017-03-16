#include <cstdio>
#include <algorithm>
using namespace std;

double C, F, X;

int main(void) {
	int testNum;
	scanf("%d", &testNum);
	for (int i = 0; i < testNum; i++) {
		scanf("%lf %lf %lf", &C, &F, &X);

		double vel = 2.0;
		double ans = X / vel;
		double timeForFarm = 0;

		for (int j = 0; j < 100000; j++) {
			timeForFarm = timeForFarm + C / vel;
			vel += F;

			double estimate = timeForFarm + X / vel;
			if (ans > estimate) {
				ans = estimate;
			}
		}

		printf("Case #%d: %.7lf\n", i + 1, ans);
	}
	return 0;
}

/*

timeForFarm = sum(i = 0, n - 1)(C / (2 + F * i));
vel = 2 + F * n; 

Ans = timeForFarm + X / vel;
timeForFarm(n) - timeForFarm(n - 1) > X / vel(n - 1) - X / vel(n)
C / (2 + F * (n - 1)) > X / (2 + F * (n - 1)) - X / (2 + F * n)
C > X - X * (2 + F * (n - 1)) / (2 + F * n)
(2 + F * n) * C > ((2 + F * n) - (2 * F * (n - 1))) * X
2 * C + C * F * n > F * X
n > (F * X - 2 * C) / (C * F);

*/
