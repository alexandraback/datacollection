#include <cstdio>

typedef long long ll;

ll reverse(ll num) {
	ll temp2 = 0;
	while (num > 0) {
		temp2 = temp2 * 10 + num % 10;
		num /= 10;
	}
	return temp2;
}

int getDigit(ll num) {
	int ans = 0;
	while (num > 0) {
		num /= 10;
		ans++;
	}
	return ans;
}

ll calc(ll num) {
	// printf(" > %lld\n", num);

	ll ans = 0;
	ll temp;

	if (num < 10) return num;
	int digit = getDigit(num);

	// Calc Half
	ll divider = 1;
	int i;
	for (i = 0; i < (digit + 1) / 2; i++) {
		divider *= 10;
	}
	temp = num % divider;

	if (temp == 0) return calc(num - 1) + 1;
	ans += temp - 1;

	num -= ans;
	temp = num;
	num = reverse(num);
	if (temp != num) { // Palindrome check
		ans++;
		// printf(" >> %lld\n", ans);
		return ans + calc(num);
	} else {
		// printf(" >> %lld + 1\n", ans);
		return ans + 1 + calc(num - 1);
	}
}

int main() {
	int testcase, t;

	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		printf("Case #%d: ", t);

		ll in;
		scanf("%lld", &in);
		printf("%lld\n", calc(in));
	}

	return 0;
}
