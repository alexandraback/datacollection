#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define NUM_PRIMES 100

unsigned int primes[NUM_PRIMES] = {
	2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541
};

unsigned int evalmod_p(unsigned int *poly,int deg,unsigned int base,unsigned int p){
	int i;
	unsigned int v;

	base = base % p;

	v = poly[deg-1] % p;
	for(i=deg-2;i>=0;i--){
		v = v*base + poly[i];
		v = v % p;
	}

	return v;
}

int main(int argc, char* argv[]){
	int T,nocase;
	int N,J;

	int i,j,k;
	unsigned int n,t;
	unsigned int base;

	unsigned int poly[32];
	unsigned int fact[16];

	cin >> T;  // read t. cin knows that t is an int, so it reads it as such.
	for (nocase = 1; nocase <= T; ++nocase) {
		cin >> N >> J;  // read n and then m.
		cout << "Case #" << nocase << ":" << endl;
		//printf("%d %d\n",N,J);

		k=0;
		for(n = 1+ (0x1 << (N-1));;n+=2){
		//printf("i = %d\n",i);

		t = n;
		//printf("n
		for(i=0;i<N;i++){
			poly[i] = t %2;
			t = t/2;
			//printf("%u",poly[i]);
		}
		//printf("\n");
		for(base=2;base<=10;base++){
			fact[base] = 1;
			for(j=0;j<NUM_PRIMES;j++){
				if(evalmod_p(poly,N,base,primes[j])==0){
					fact[base] = primes[j];
					break;
				}
			}
			if(fact[base]==1) break;
		}
		if(base==11){
			k++;
			for(j=N-1;j>=0;j--) printf("%u",poly[j]);
			for(base=2;base<=10;base++) printf(" %u",fact[base]);
			printf("\n");
		}

		if(k==J) break;
		}
	}

	return 0;
}