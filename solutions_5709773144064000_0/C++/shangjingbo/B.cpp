#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

const int limit = 1000000;

int main()
{
	int tests, test = 1;
	for (scanf("%d", &tests); test <= tests; ++ test) {
		double C, F, X;
		scanf("%lf%lf%lf", &C, &F, &X);
		double speed = 2;
		double answer = 0;
		while (1) {
			double t = C / speed;
			double deltaT = C / F;
			if (speed * (t + deltaT) <= X) {
				answer += t;
				speed += F;
			} else {
				answer += X / speed;
				break;
			}
		}
		
		printf("Case #%d: %.10f\n", test, answer);
	}
	return 0;
}
