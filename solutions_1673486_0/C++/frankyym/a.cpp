#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		int A, B;
		scanf("%d%d", &A, &B);
		
		double correctP = 1.0;
		double avgType = 1 + B + 1;
		
		for (int i=1; i<=A; ++i) {
			double p;
			scanf("%lf", &p);
			
			correctP *= p;
			double expT = correctP * (B - i) + (1 - correctP) * ((B-i) + 1 + B) + 1 + (A - i);
			if (expT < avgType) avgType = expT;
		}
		
		printf("Case #%d: %.6lf\n", t+1, avgType);
	}
	return 0;
}