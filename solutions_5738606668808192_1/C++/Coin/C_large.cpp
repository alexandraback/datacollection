#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

//模拟1e32以下的整数
struct BigInteger {
	static const long long BASE = 10000000000000000;
	static const int WIDTH = 16;
	long long s[2];
	BigInteger() {
		s[0] = s[1] = 0;
	}
	BigInteger(long long x, int tarBase) {
		s[0] = s[1] = 0;
		long long base = (long long)1 << 31;
		while (base) {
			long long v = x / base;
			*this = *this * tarBase + v;
			x %= base;
			base /= 2;
		}
	}

	BigInteger(long long x) {
		s[1] = x / BASE;
		s[0] = x % BASE;
	}
	BigInteger operator+=(const BigInteger& op) {
		return *this + op;
	}

	BigInteger operator=(const BigInteger& op) {
		s[0] = op.s[0];
		s[1] = op.s[1];
		return *this;
	}

	BigInteger operator+(const BigInteger& op) {
		BigInteger c;
		long long tmp = s[0] + op.s[0];
		c.s[0] = tmp % BASE;
		c.s[1] = s[1] + op.s[1] + tmp / BASE;
		return c;
	}
	BigInteger operator+(long long v) {
		BigInteger c(v);
		return *this + c;
	}

	//乘以x，这里x范围：2-10.
	BigInteger operator*(int x) {
		BigInteger c;
		long long tmp = s[0] * x;
		c.s[0] = tmp % BASE;
		c.s[1] = s[1] * x + tmp / BASE;
		return c;
	}

	void print() {
		printf("%lld%0*lld", s[1], WIDTH, s[0]);
	}

	long long operator%(int x) {
		return ((s[1] % x)*(BASE % x) + s[0] % x) % x;
	}
};


int primer[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
int np = 8;

long long getVal(long long num, int base) {
	long long res = 0;
	for (long long i = 1; num; i *= base, num /= 2)
		res += i * (num % 2);
	return res;
}

void printBinary(long long num) {
	long long base = 1;
	while (base < num) base *= 2;
	base /= 2;
	while (num) {
		printf("%lld", num / base);
		num %= base;
		base /= 2;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, kase = 0;
	scanf("%d", &T);
	while (++kase <= T) {
		int N, J;
		scanf("%d%d", &N, &J);
		printf("Case #%d:\n", kase);
		long long m = 1 << N;
		for (long long i = ((long long)1 << (N - 1)) + 1, cnt = 0; i < ((long long)1 << N) && cnt < J; i += 2) {
			int factor[11] = {};
			int j;
			for (j = 2; j <= 10; j++) {
				BigInteger val(i, j);
			//	long long val = getVal(i, j);
				bool isOk = false;
				for (int k = 0; k < np; k++) {
					if (val % primer[k] == 0) {
						isOk = true;
						factor[j] = primer[k];
						break;
					}
				}
				if (!isOk) break;
			}
			if (j > 10) {
				printBinary(i);
				for (int i = 2; i <= 10; i++)
					printf(" %d", factor[i]);
				printf("\n");
				cnt++;
			}
		}
	}
	return 0;
}