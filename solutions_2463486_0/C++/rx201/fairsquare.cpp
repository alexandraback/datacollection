#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int palindrome(uint64_t x) {
	int digits[18];
	int n = 0;
	while(x) {
		digits[n++] = x % 10;
		x /= 10;
	}
	int i=0;
	int j=n-1;
	while (i < j) {
		if (digits[i++] != digits[j--])
			return 0;
	}
	return 1;
}

int sqroot(uint64_t x) {
	return (int)sqrt(x);
}

#define MAX 10000000
int Count[MAX+1];

int main(int argc, char* argv[]) {
	int T;
	uint64_t A, B;
	
	setbuf(stdout, NULL);
		
	Count[0] = 0;
	for(int i=1; i<=MAX; i++) {
		if (palindrome(i) && palindrome( ((uint64_t)i) * ((uint64_t)i))) {
			Count[i] = Count[i-1] + 1;
			//printf("%d %llu\n", i, ((uint64_t)i) * ((uint64_t)i));
		}  else {
			Count[i] = Count[i-1];
		}
	}
	
	scanf("%d\n", &T);
	for(int t=0; t<T; t++) {
		scanf("%llu %llu", &A, &B);
		printf("Case #%d: %d\n", t+1, Count[sqroot(B)] - Count[sqroot(A-1)]);
	}
	
	return 0;
}
