#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

using namespace std;
typedef long long ll;

FILE *f;

ll toBase(ll num, int base) {
	ll result = 0;
	ll exp = 1;
	while (num) {
		if (num & 1)
			result += exp;
		exp *= base;
		num >>= 1;
	}
	return result;
}

void print2base(ll num) {
	if (num == 0)
		return;
	int last = num & 1;
	print2base(num >> 1);
	fprintf(f, "%d", last);
}

int primes[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int getDivisor(ll num) {
	for (int i = 0; i < 10; i++)
		if (num % primes[i] == 0)
			return primes[i];
	return 0;
}

ll nums[10000], num;
int bitsUsed[10000], bu;
int onesUsed[10000], ou;
int sp = 0;
int problems[] = {2, 6, 8};

int main() {
	f = fopen("C-large.out", "w");
	fprintf(f, "Case #1:\n");
	int count = 0;
	nums[sp] = 1;
	bitsUsed[sp] = 0;
	onesUsed[sp] = 0;
	sp++;
	while (sp > 0 && count < 500) {
		sp--;
		num = nums[sp];
		bu = bitsUsed[sp];
		ou = onesUsed[sp];
		if (bu == 30) {
			num <<= 1;
			num |= 1;
			bool found = true;
			int divisors[3];
			for (int i = 0; i < 3; i++) {
				ll rebase = toBase(num, problems[i]);
				int divisor = getDivisor(rebase);
				if (divisor) {
					divisors[i] = divisor;
				} else {
					found = false;
					break;
				}
			}
			if (found) {
				print2base(num);
				fprintf(f, " %d 2 3 2 %d 2 %d 2 3\n", divisors[0], divisors[1], divisors[2]);
				count++;
				assert(toBase(num, 4) % 3 == 0);
				assert(toBase(num, 10) % 3 == 0);
				for (int i = 0; i < 3; i++) {
					assert(toBase(num, problems[i]) % divisors[i] == 0);
				}
			}
			continue;
		}
		int remainder = (ou + 2) % 6;
		if (remainder == 0 && 30 - bu < 6) {
			nums[sp] = num << (30 - bu);
			bitsUsed[sp] = 30;
			onesUsed[sp] = ou;
			sp++;
			continue;
		}
		if (remainder != 0 && 6 - remainder == 30 - bu) {
			nums[sp] = num;
			for (int i = 0; i < 30 - bu; i++)
				nums[sp] = (nums[sp] << 1) | 1;
			bitsUsed[sp] = 30;
			onesUsed[sp] = ou + 30 - bu;
			sp++;
			continue;
		}
		nums[sp] = num << 1;
		bitsUsed[sp] = bu + 1;
		onesUsed[sp] = ou;
		sp++;
		nums[sp] = nums[sp - 1] | 1;
		bitsUsed[sp] = bu + 1;
		onesUsed[sp] = ou + 1;
		sp++;
	}
	fclose(f);
	exit(0);
}