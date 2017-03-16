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


int64 countFairAndSquare(int64 a, int64 b){
	int64 n, nsq, count = 0, odd;
	
	odd = 1;
	n = 0;
	nsq = 0;
	while (nsq < a){
		nsq += odd;
		odd += 2;
		n++;
	}
	
	while (nsq <= b){
		if (isPalindrome(n) && (isPalindrome(nsq)))
			count++;
		
		nsq += odd;
		odd += 2;
		n++;
	}
	
	return count;
}

int main(void){
	int t, caseNr;
	scanf("%d\n", &t);
	
	for (caseNr = 1; caseNr <= t; caseNr++){
		int64 a, b;
		scanf("%lld %lld\n", &a, &b);
		
		printf("Case #%d: %lld\n", caseNr, countFairAndSquare(a, b));
	}
	
	return 0;
}