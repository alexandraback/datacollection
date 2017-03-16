#include <math.h>
#include <stdbool.h>
#include <stdio.h>

typedef long long llong;
enum { LIM = 10000009 };

llong rev(llong n)
{
	llong r = 0;
	while (n != 0) {
		r = r*10 + n%10;
		n /= 10;
	}
	return r;
}

bool is_palindrome(llong n)
{
	return n == rev(n);
}

bool square_is_fair[LIM];
int prefix_sum[LIM];

int main(void)
{
	for (llong i = 1; i < LIM; ++i) {
		if (is_palindrome(i) && is_palindrome(i*i)) {
			//printf("%lld => %lld\n", i, i*i);
			square_is_fair[i] = true;
		}
		prefix_sum[i] = prefix_sum[i-1] + square_is_fair[i];
	}

	int cases;
	scanf("%d", &cases);
	for (int T = 1; T <= cases; ++T) {
		llong A, B;
		scanf("%lld %lld", &A, &B);
		llong begin = llrint(sqrtl(A));
		if (begin*begin < A)
			begin += 1;
		llong end = llrint(sqrtl(B));
		if (end*end > B)
			end -= 1;
		printf("Case #%d: %d\n", T, prefix_sum[end] - prefix_sum[begin-1]);
	}
	return 0;
}
