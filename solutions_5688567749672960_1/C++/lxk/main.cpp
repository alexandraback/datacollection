#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

typedef uint8_t byte;
typedef int16_t i16;
typedef uint16_t ui16;
typedef int32_t i32;
typedef uint32_t ui32;
typedef int64_t i64;
typedef uint64_t ui64;

#define MOD 1000000007
#define ADD_MOD(a, b) (((a) + (b)) % MOD)
#define MUL_MOD(a, b) i32((i64(a) * i64(b)) % MOD)
#define SUB_MOD(a, b) ((a) >= (b) ? (a) - (b) : (a) + MOD - (b))

ui64 last_digit(ui64 num) {
	return num - (num / 10) * 10;
}

ui64 reverse(ui64 num) {
	ui64 r = 0;
	while (num > 0) {
		r = r * 10 + last_digit(num);
		num = num / 10;
	}

	return r;
}

int num_len(ui64 num) {
	return (int)log10(num) + 1;
}

ui64 get_right(ui64 num, int len) {
	ui64 right = 0;

	ui64 p = 1;
	while (len-- > 0) {
		right += last_digit(num) * p;

		p *= 10;
		num /= 10;
	}

	return right;
}

ui64 get_left(ui64 num, int len) {
	while (len-- > 0) {
		num /= 10;
	}
	return num;
}

bool is_pow10(ui64 num) {
	double l = log10(num);

	double tmp;
	return modf(l, &tmp) == 0.0;
}

ui64 make9(int len) {
	ui64 res = 0;
	int p = 1;
	while (len-- > 0) {
		res += 9 * p;
		p *= 10;
	}

	return res;
}

ui64 combine(ui64 left, ui64 right, int len) {
	ui64 p = 1;
	while (len-- > 0) {
		p *= 10;
	}
	return left * p + right;
}

ui64 next_reversed(ui64 num) {
	int len = num_len(num);
	if (len == 1) {
		return 1;
	}

	int rightLen = (len + 1) / 2;

	ui64 left = get_left(num, rightLen);
	ui64 right = get_right(num, rightLen);

	if (right == 0 || is_pow10(left)) {
		--left;
		right = make9(rightLen);

		return next_reversed(combine(left, right, rightLen));
	}

	return combine(left, 1, rightLen);
}

int main() {
	ios_base::sync_with_stdio(false);

	size_t testCount;
	cin >> testCount;

	for (size_t testIndex = 0; testIndex < testCount; ++testIndex) {
		ui64 n;
		cin >> n;

		ui64 r = 0;
		if (n == 1) r = 1;
		
		while (n > 1) {
			ui64 next = next_reversed(n);
			r += n - next + 1;
			n = reverse(next);
		}

		cout << "Case #" << testIndex + 1 << ": " << r << endl;
	}

	return 0;
}
