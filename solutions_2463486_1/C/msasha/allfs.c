#include <stdio.h>
#include <inttypes.h>

typedef int64_t int64;

int isPalindrome(int64 n){
	int digits[101];
	int digitCount = 0, i;
	
	while (n != 0){
		digits[digitCount] = n%10;
		n /= 10;
		digitCount++;
	}
	
	for (i = 0; i < digitCount; i++)
		if (digits[i] != digits[digitCount-1-i])
			return 0;
	
	return 1;
}


int main(void){
	int64 n, nsq, odd;
	
	odd = 1;
	n = 1;
	nsq = 1;
	while (nsq <= 100000000000000L){
		if (isPalindrome(n) && (isPalindrome(nsq)))
			printf("%lldLL, ", nsq);

		odd += 2;
		nsq += odd;
		n++;
	}
	
	printf("\n");
	
	return 0;
}