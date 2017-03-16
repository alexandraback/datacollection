#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	int i;
	
	for (i=0; i < T; i++) {
		long long r,t; // r=radius of first ring, t=milliliters of paint
		scanf("%lld %lld", &r, &t);
		long n=0;
		
		// A=pi*r^2
		while (t > 0) {
			t -= ((r+1)*(r+1))-(r*r);
			if (t < 0) break;
			r += 2;
			n++;
		}
		
		printf("Case #%d: %lld\n", i+1, n);
	}
	
	return 0;
}
