#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	for (int tc=1; tc<=T; tc++) {
		double C, F, X;
		scanf("%lf%lf%lf", &C, &F, &X);
		double answer = X / 2.0;
		double speed = 2.0;
		double t = 0;
		while (t < answer) {
			double t2 = t + C / speed;
			answer = min(answer, t2 + X / (speed + F));
			t = t2;
			speed += F;
		}
		printf("Case #%d: %.10lf\n",tc,answer);
	}
}
