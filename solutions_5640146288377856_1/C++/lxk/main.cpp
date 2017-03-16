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

int main() {
	ios_base::sync_with_stdio(false);

	size_t testCount;
	cin >> testCount;

	for (size_t testIndex = 0; testIndex < testCount; ++testIndex) {
		size_t w, h, n;
		cin >> h >> w >> n;

		size_t res = 0;
		res += (h - 1) * (w / n);
		res += w / n + n - (w % n == 0 ? 1 : 0);

		cout << "Case #" << testIndex + 1 << ": " << res << endl;
	}

	return 0;
}
