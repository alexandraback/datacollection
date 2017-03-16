#include <stdio.h>

#define N 100000000
long int primes[N];// <= 0 if prime, else first prime divisor

char coin(long int bits, long int n);
long int get_prime(long int val);
void gen_primes();

int main() {
	long int i, t, n, j, bits;
	gen_primes();

	scanf("%ld", &t);
	for(i = 1; i <= t; i++) {
		scanf("%ld%ld", &n, &j);
		printf("Case #%ld:\n", i);
		bits = (1 << (n - 1)) + 1;
		for(i = 0; i < j;) {
			if(coin(bits, n))
				i++;
			bits += 2;
		}
	}
 	return 0;
}

char coin(long int bits, long int n) {
	long int base, bits2, i, fac;
	long int val;
	long int divisor[9];
	//long int values[9];
	char s[32+1];

	for(base = 2; base <= 10; base++) {
		val = 0;
		fac = 1;
		bits2 = bits;
		while(bits2) {
			if(bits2 & 1) {
				val += fac;
			}
			fac *= base;
			bits2 >>= 1;
		}
		divisor[base - 2] = get_prime(val); //returns divisor or <=0 if prime
		if(divisor[base - 2] <= 0) {
			return 0;//false
		}
		//values[base - 2] = val;
	}
	s[n] = 0;//null
	for(i=n-1; i>=0; i--) {
		s[i] = (bits & 1) ? '1' : '0';
		bits >>= 1;
	}
	printf("%s", s);
	for(i=0; i<9; i++) {
		printf(" %ld", divisor[i]);
		//printf("(%ld)", values[i]);
	}
	printf("\n");
	return 1;//true
}

long int get_prime(long int val) {
	long int div;

	if(val < N)
		return primes[val];

	div = 2;
	while(div*div <= val) {
		if(val % div == 0) {
			return div;
		}
		div = div - primes[div];
	}
	return 0;
}

void gen_primes() {
	long int i, div;
	long int lastprime = 2;

	primes[2] = 0;
	for (i = 3; i < N; i++) {
		div = 2;
		while(div*div <= i) {
			if(i % div == 0) {
				primes[i] = div;
				break;
			}
			div = div - primes[div];
		}
		if(div*div > i) {
			primes[i] = 0;
			primes[lastprime] = -(i - lastprime);
			lastprime = i;
		}
	}
}

