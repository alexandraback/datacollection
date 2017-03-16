#include "stdio.h"
#include "math.h"
#include "stdlib.h"

typedef unsigned long long int uint64;

int is_palindrome(uint64 x)
{
	char buf[101] = {0};
	int len = 0;
	int result = 1;
	int i;
	
	while (x) {
		buf[len] = x%10;
		x /= 10;
		len++;
	}

	for (i=0; i<len>>1; i++) {
		if (buf[i] != buf[len-i-1]) {
			result = 0;
			break;
		}
	}

	return result;
}

int main ()
{
	int t;
	int i;
	uint64 j;
	char *lut = malloc(sizeof(char)*10000000);
	char count = 0;

	lut[0] = 0;
	for (j=1; j<=10000000; j++){

		if(is_palindrome(j) && is_palindrome(j*j)) {
			count++;
		}
		lut[j] = count;
	}

	scanf("%d", &t);

	for(i=0; i<t; i++) {
		uint64 a,b;

		scanf("%llu %llu", &a, &b);
		a--;

		a = sqrt(a);
		b = sqrt(b);

		printf("Case #%d: %d\n", i+1, lut[b]-lut[a]);
	}
	
	free(lut);

	return 0;
}
