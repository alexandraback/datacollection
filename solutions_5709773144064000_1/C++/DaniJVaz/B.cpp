#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		double C, F, X;
		scanf("%lf %lf %lf", &C, &F, &X);

		double r = 2;
		double minC = X+1;
		double t = 0;
		while (1) {
			t += C/r;
			if (t + (X-C)/r < minC)
				minC = t + (X-C)/r;
			else
				break;					// When adding factories stops improving, we can 
										//stop, because no further factories will improve
			r += F;
		}
		printf("Case #%d: %.7lf\n", iC, minC);
	}
	return 0;
}