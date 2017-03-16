#include <cstdio>
#include <cmath>

#define ARRAYSIZE 41

long long memo[ARRAYSIZE];

int isPalindrome(long long x) {
	int power = (int)log10((long double)x);
	if (power == 0)
		return 1;
	int a, b;
	for (int i = 0; i < (power + 1) / 2; i++) {
		a = ((x - (x % (long long) pow(10, i))) / (long long) pow(10, i)) % 10;
		b = ((x - (x % (long long) pow(10, power - i))) / (long long) pow(10, power - i)) % 10;
		if (a != b)
			return 0;
	}
	return 1;
}

int fairAndSquare(long long a, long long b) {
	int total = 0;
	
	long long start = (long long) sqrt((long double)a);
	long long end = (long long) sqrt((long double)b);
	
	if (start * start < a)
		start++;
	if (end * end > b)
		end--;
	
	memo[0] = 0;
	for (long long i = start; i <= end; i++) {
		if (isPalindrome(i)) {
			if (isPalindrome(i * i)) {
				memo[++total] = i * i;
			}
		}
	}
	
	return total;
}

int fairAndSquareMemo(long long a, long long b) {
	int start = 0;
	int end = 0;
	for (int i = 0; i < ARRAYSIZE; i++) {
		if (a <= memo[i]) {
			start = i;
			break;
		}
	}
	for (int i = 0; i < ARRAYSIZE; i++) {
		if (b < memo[i]) {
			end = i;
			break;
		}
		if (b == memo[i]) {
			end = i + 1;
			break;
		}
	}
	return end - start;
}

int main() {
	fairAndSquare(1LL, 100010000000000LL);
	int T;
	long long A, B;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%lld %lld", &A, &B);
		printf("Case #%d: %d\n", i, fairAndSquareMemo(A, B));
	}
	return 0;
}
