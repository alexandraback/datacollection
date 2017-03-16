#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
int main(){
	int ncase;
	const double pi = atan(1)*4;
	scanf("%d", &ncase);
	for(int nn = 1; nn <= ncase; nn++){
		int r, t, count = 0;
		double sum = 0;
		scanf("%d%d", &r, &t);
		double limit = pi * t;
		for(count = 0; ; count++){
			sum += pi * ((r + count * 2 + 1) * (r + count * 2 + 1) - (r + count * 2) * (r + count * 2));
//			printf("%f\n", sum);
			if(sum - limit > 1e-9)
				break;
		}
		printf("Case #%d: %d\n", nn, count);
	}
	return 0;
}