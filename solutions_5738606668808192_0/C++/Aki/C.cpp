#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;
typedef long long i64;


uint128_t base(unsigned b, unsigned c)
{
	uint128_t v = 0;
	for (unsigned i = 0; i < 32; ++i) {
		v *= b;
		v += (c >> (31 - i)) & 1;
	}
	return v;
}

bool find_divisor(const uint128_t bases[9], unsigned *divisors)
{
	for (int i = 0; i < 10; ++i) {
		if (bases[i] % 2 == 0) {
			divisors[i] = 2;
		} else {
			divisors[i] = 0;
			for (unsigned d = 3; d < 100000 && d < bases[i]; d += 2) {
				if ((bases[i] % d) == 0) {
					divisors[i] = d;
					break;
				}
			}
			if (divisors[i] == 0) {
				return false;
			}
		}
	}
	return true;
}

string to_str(unsigned c)
{
	string str;
	while (c) {
		str.insert(0, 1, c & 1 ? '1' : '0');
		c >>= 1;
	}
	return str;
}

int main() {
	int T; scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti) {
		fprintf(stderr, "Case #%d of %d...\n", Ti, T);

		int N, J;
		scanf("%d %d", &N, &J);
		
		printf("Case #%d:\n", Ti);

		uint128_t bases[9];

		int jamcoin = 0;
		for (unsigned i = 0; i < (1 << (N-2)); ++i) {
			for (unsigned b = 2; b <= 10; ++b) {
				bases[b - 2] = base(b, (1 << (N-1)) | (i << 1) | 1);
			}

			unsigned divisor[9];
			if (find_divisor(bases, divisor)) {
				printf("%s %d %d %d %d %d %d %d %d %d\n", to_str((1 << (N-1)) | (i << 1) | 1).c_str(), divisor[0], divisor[1], divisor[2], divisor[3], divisor[4], divisor[5], divisor[6], divisor[7], divisor[8]);
				++jamcoin;
			}
			
			if (jamcoin == J) break;
		}
	}
	return 0;
}
