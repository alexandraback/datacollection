#include <cstdio>
#include <cstdlib>
#include <cstring>
#define minn(x,y) ((x)=(x)<(y)?(x):(y))


int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	
	int testCaseNum;
	scanf("%d", &testCaseNum);
	for (int testCase = 1; testCase <= testCaseNum; ++testCase) {
		double C, F, X;
		scanf("%lf%lf%lf", &C, &F, &X);
		double T = 0, S = 2, bestT = 1e20;
		while (T < bestT) {
			minn(bestT, T + X / S);
			T += C / S;
			S += F;
		}
		printf("Case #%d: %.9lf\n", testCase, bestT);
	}
	
	return 0;
}