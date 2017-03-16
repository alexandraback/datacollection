#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;


int main(void) {
	int t, testCases;
	cin >> testCases;
	unsigned long A, B, K, count, Kceil, Aclip, Bclip, Kshift;
	unsigned long a, b;
	
	for (t=1; t<=testCases; t++) {
		cin >> A >> B >> K;
		
		if (A<=K) count = A*B;
		else if (B<=K) count = A*B;
		else {
			count = A*K + (B-K)*K;
			Kceil = 1;
			Kshift = 0;
			while (Kceil < K) {
				Kceil <<= 1;
				Kshift++;
			}
			Aclip = (Kceil < A) ? Kceil : A;
			Bclip = (Kceil < B) ? Kceil : B;
			for (a=K; a<Aclip; a++) for (b=K; b<B; b++) if ((a&b) < K) count++;
			for (a=Aclip; a<A; a++) {
				for (b=K; b<Bclip; b++) if ((a&b) < K) count++;
				for (b=Bclip; b<B; b++) {
					if ((a&b)>>Kshift) { b--; b+=Kceil; }
					else {
						if ((a&b) < K) {
						//	printf("a %lx, b %lx, a&b %lx Bclip %lx, K %lx\n", a, b, a&b, Bclip, K);
							count++;
						}
					}
				}
			}
		}
		
		printf("Case #%d: %ld\n", t, count);
	}
	
	
	return 0;
}