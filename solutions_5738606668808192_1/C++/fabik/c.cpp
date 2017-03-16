#include <cstdio>
#include <cassert>
#include <string>

using namespace std;

const int MaxDivisor = 10000;

inline void addWithCarry(uint64_t &total, uint64_t &carry, uint64_t value)
{
	total += value;

	if (total < value) {
		carry++;
	}
}

inline void splitInt64(uint64_t value, uint64_t &high, uint64_t &low)
{
	high = value >> 32;
	low = (value << 32) >> 32;
}

class UInt128
{
	public:
		uint64_t high, low;

		UInt128(uint64_t value = 0) : high(0), low(value)
		{
		}

		UInt128 operator+(UInt128 other) const
		{
			UInt128 result;
			result.high = high + other.high;
			result.low = low;
			addWithCarry(result.low, result.high, other.low);
			return result;
		}

		UInt128 operator*(UInt128 other) const
		{
			uint64_t a[4], b[4], res[6] = {};
			splitInt64(high, a[3], a[2]);
			splitInt64(low, a[1], a[0]);
			splitInt64(other.high, b[3], b[2]);
			splitInt64(other.low, b[1], b[0]);

			for (int i = 0; i < 4; i++) {
				for (int j = 0; i + j < 4; j++) {
					addWithCarry(res[i + j], res[i + j + 1], a[i] * b[j]);
				}
			}

			for (int i = 0; i < 4; i++) {
				uint64_t carry, value;
				splitInt64(res[i], carry, value);
				addWithCarry(res[i + 1], res[i + 2], carry);
				res[i] = value;
			}

			UInt128 result;
			result.high = (res[3] << 32) | res[2];
			result.low = (res[1] << 32) | res[0];
			return result;
		}

		uint64_t operator%(uint64_t value)
		{
			assert(value < (1ULL << 32));
			uint64_t result = high % value;
			result = (result << 32) % value;
			result = (result << 32) % value;
			result = (result + low) % value;
			return result;
		}

		bool operator<(UInt128 other)
		{
			return high < other.high || (high == other.high && low < other.low);
		}
};

bool sieve[MaxDivisor + 1];
int primes[MaxDivisor];
int primeCount;

void initPrimes()
{
	for (int i = 2; i <= MaxDivisor; i++) {
		sieve[i] = true;
	}

	for (int i = 2; i <= MaxDivisor; i++) {
		if (sieve[i]) {
			primes[primeCount++] = i;

			for (int j = i * 2; j <= MaxDivisor; j += i) {
				sieve[i] = false;
			}
		}
	}
}

UInt128 convertCoinToBase(uint64_t coin, int base)
{
	UInt128 value(0);

	for (uint64_t c = 1; c < coin; c *= 2) {
		value = value * UInt128(base);

		if (coin & c) {
			value = value + UInt128(1);
		}
	}

	return value;
}

string coinToString(uint64_t coin)
{
	char buffer[40] = {};
	int p = 0;

	for (uint64_t c = 1; c < coin; c *= 2) {
		buffer[p++] = (coin & c) ? '1' : '0';
	}

	return string(buffer);
}

int main()
{
	initPrimes();

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		int N, J;
		scanf("%d%d", &N, &J);
		printf("Case #%d:\n", tc);
		int found = 0;

		for (uint64_t mask = 0; mask < (1ULL << (N - 2)) && found < J; mask++) {
			uint64_t coin = (1ULL << (N - 1)) | (mask << 1) | 1;
			int divisors[11];

			for (int base = 2; base <= 10; base++) {
				UInt128 value = convertCoinToBase(coin, base);
				bool foundDivisor = false;

				for (int i = 0; i < primeCount; i++) {
					int prime = primes[i];

					if (!(UInt128(prime) < value)) {
						goto nextMask;
					}

					if (value % prime == 0) {
						divisors[base] = prime;
						foundDivisor = true;
						break;
					}
				}

				if (!foundDivisor) {
					goto nextMask;
				}
			}

			printf("%s", coinToString(coin).c_str());

			for (int base = 2; base <= 10; base++) {
				printf(" %d", divisors[base]);
			}

			printf("\n");

			found++;

nextMask:
			continue;
		}
	}
	return 0;
}
