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

ui64 reverse(ui64 num) {
	ui64 r = 0;
	while (num > 0) {
		ui64 digit = num - (num / 10) * 10;
		r = r * 10 + digit;
		num = num / 10;
	}

	return r;
}

int main() {
	ios_base::sync_with_stdio(false);

	size_t testCount;
	cin >> testCount;

	for (size_t testIndex = 0; testIndex < testCount; ++testIndex) {
		ui64 n;
		cin >> n;

		vector<int> ar(n + 1, 999999999);
		ar[1] = 1;

		for (size_t i = 1; i < n; ++i) {
			ar[i + 1] = min(ar[i + 1], ar[i] + 1);

			ui64 r = reverse(i);
			if (r <= n) {
				ar[r] = min(ar[r], ar[i] + 1);
			}
		}

		cout << "Case #" << testIndex + 1 << ": " << ar[n] << endl;
	}

	return 0;
}
