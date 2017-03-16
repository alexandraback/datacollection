#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long uuu(int a, int b, int c) {
	return 4;
}
long long uuc(int a, int b, int c) {
	return c == 0 ? 3 : 1;
}
long long ucu(int a, int b, int c) {
	return 2;
}
long long ucc(int a, int b, int c) {
	if(b == 0 && c == 1) return 0;
	if(b == 0 && c == 0) return 2;
	if(b == 1 && c == 0) return 1;
	if(b == 1 && c == 1) return 1;
}
long long cuu(int a, int b, int c) { return ucu(b, a, c); }
long long cuc(int a, int b, int c) { return ucc(b, a, c); }
long long ccu(int a, int b, int c) { return 1; }

long long ccc(int a, int b, int c) {
	return (a&b) == c ? 1 : 0;
}

long long g(int a, int b, int c, int i, int j, int k) {
	//printf("%d %d %d %d %d %d\n", a, b, c, i, j, k);
	long long total = 1;
	for (int l = 0; l <= 31; l++) {
		#define getbit(a) (((a)>>l)&1)
		switch ((((int)(l >= i))<<8) | (((int)(l >= j))<<4) | (((int)(l >= k)))) {
			case 0x000: total *= uuu(getbit(a), getbit(b), getbit(c)); break;
			case 0x001: total *= uuc(getbit(a), getbit(b), getbit(c)); break;
			case 0x010: total *= ucu(getbit(a), getbit(b), getbit(c)); break;
			case 0x011: total *= ucc(getbit(a), getbit(b), getbit(c)); break;
			case 0x100: total *= cuu(getbit(a), getbit(b), getbit(c)); break;
			case 0x101: total *= cuc(getbit(a), getbit(b), getbit(c)); break;
			case 0x110: total *= ccu(getbit(a), getbit(b), getbit(c)); break;
			case 0x111: total *= ccc(getbit(a), getbit(b), getbit(c)); break;
		}
	}
	return total;
}

long long solve() {
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	int a1 = 0;
	long long total = 0;
	for (int i = 29; i >= 0; i--) {
		if (a & (1 << i)) {

			int b1 = 0;
			for (int j = 29; j >= 0; j--) {
				if (b & (1 << j)) {

					int c1 = 0;
					for (int k = 29; k >= 0; k--) {
						if (c & (1 << k)) {
							total += g(a1, b1, c1, i, j, k);

							c1 += 1 << k;
						}
					}

					
					b1 += 1 << j;
				}
			}

			a1 += 1 << i;	
		}
	}
	return total;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: %lld\n", i, solve());
	}
}
