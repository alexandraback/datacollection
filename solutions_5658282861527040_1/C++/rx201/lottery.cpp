#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int convert( unsigned long A, unsigned long* a, unsigned long* am) {
	int ac = 0;
	for(int i=0; i<32; i++) {
		if (A & (1 << i)) {
			a[ac] = A ^ (1 << i);
			am[ac] = (1 << (i)) - 1;
			ac++;
		}
	}
	return ac;
}

int main(int argc, char* argv[]) {
	int T;
	
	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for(int t=0; t<T; t++) {
		unsigned long A, B, K;
		scanf("%u %u %u\n", &A, &B, &K);
		// printf("%u %u %u\n", A, B, K);
		unsigned long a[32], b[32], am[32], bm[32], k[32], km[32];
		int ac = 0, bc = 0, kc = 0;
		ac = convert(A, a, am);
		bc = convert(B, b, bm);
		kc = convert(K, k, km);
		
		unsigned long count = 0;
		for(int i=0; i<ac; i++) {
			for(int j=0; j<bc; j++) {
				for(int t=0; t<kc; t++) {
					int bits[32];
					int mask[32];
					
					for (int x=0; x<32; x++) {
						int p = 1<<x;
						if ( (am[i] & p) && (bm[j] & p)) {
							mask[x] = 1;
							bits[x] = 0;
						} else if ( (am[i] & p == 0) && (bm[j] & p == 0)) {
							mask[x] = 0;
							bits[x] = ((a[i] & b[j] & p) > 0) ? 1 : 0;
						} else {
							if (am[i] & p)  {
								if (b[j] & p) {
									mask[x] = 1;
									bits[x] = 0;
								} else {
									mask[x] = 0;
									bits[x] = 0;
								}
							} else { // bm[j] & p
								if (a[i] & p) {
									mask[x] = 1;
									bits[x] = 0;
								} else {
									mask[x] = 0;
									bits[x] = 0;
								}
							}
						}
					}
					// for(int x=0; x<32; x++) {
						// if (mask[x])
							// printf("X");
						// else
							// printf("%d", bits[x]);
					// }
					// printf("\n");
					
					unsigned long r = 1;
					for(int x=0; x<32; x++) {
						int p = 1<<x;
						// if ((km[t] & p == 0) && (mask[x] == 0) && (((k[t] >> x) & 1) != bits[x])) {
							// r = 0;
							// break;
						// }
						int rr = 0;
						for(int ab=0; ab<=1; ab++) {
							for(int bb=0; bb <=1; bb++) {
								if ((am[i] & p) == 0 && ((a[i] >> x) & 1) != ab)
									continue;
								if ((bm[j] & p) == 0 && ((b[j] >> x) & 1) != bb)
									continue;
								
								int kb = ab & bb;
								if ( (km[t] & p) || ((k[t] >> x) & 1) == kb)
								    rr++;
							}
						}
						// printf("%d\n", rr);
						r *= rr;
						/*
						if (km[t] & p) {
							if (mask[x])
								r *= 2;
						} else { // km is fixed bit
							if (mask[x]) {
								// bit fixed
							}  else { //
								if ( ((k[t] >> x) & 1) != bits[x])
								    r = 0;
							}
						}
						*/
					}
					// printf("%x %x %x %x %x %x %d\n", a[i], am[i], b[j], bm[j], k[t], km[t], r);
					count += r;
				}
			}
		}
		
		printf("Case #%d: %u\n", t+1, count);
	}
	
	return 0;
}
