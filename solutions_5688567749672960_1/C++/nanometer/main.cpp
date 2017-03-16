#include <cstdio>
#include <cstring>

long reverse(long v) {
	long result = 0;
	while (v) {
		result = result * 10 + v % 10;
		v /= 10;
	}
	return result;
}

long get_len(long n) {
	long result = 0;
	do {
		++ result;
		n /= 10;
	} while (n > 0);
	return result;
}

long pow(long n) {
	long result = 1;
	while (n--) {
		result *= 10;
	}
	return result;
}

long get_high(long n, long len) {
	return n / pow(len - len / 2);
}

long get_low(long n, long len) {
	return n % pow(len - len / 2);
}

long solve(long n) {
	long result = 0;
	while (n > 10) {
		if (n % 10 == 0) {
			--n;
			++result;
		}

		long len  = get_len(n);
		long high = get_high(n, len);
		long low = get_low(n, len);
		
		if (high == pow(len / 2 - 1)) {
			result += low;
		} else {
			result += reverse(high);
			result += low;
		}
		n = pow(len - 1);
	}
	return result + n;
}

int main(void) {
	long test_count, n;
	scanf("%ld", &test_count);
	for (int test = 1; test <= test_count; ++ test) {
		scanf("%ld", &n);
		printf("Case #%d: %ld\n", test, solve(n));
	}
	return 0;
}
