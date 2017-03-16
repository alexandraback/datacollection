#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;
#define P10_UINT64 10000000000000000000ULL 

__uint128_t pow_128(int i, int p) {
	__uint128_t ret = i;
	if (p == 0)
		return 1;

	for (int k = 1; k < p; k++) {
		ret *= (int) i;
	}
	return ret;
}

__uint128_t getinbase(unsigned long long k, int base) {
	__uint128_t ans = 0;

	string s = bitset< 32 >(k).to_string();

	for (int i = s.size()-1; i > -1; i--) {
		if (s[i] == '0') continue;
		ans += pow_128(base, s.size() -1 - i);
	}
	
	return ans;
}

unsigned long long getdivider(__uint128_t k) {
	unsigned long long l = 2;
	while (l < 10000 && k % l) {
		l++;
	}
	if (!(k % l)) return l;

	return 0;
}


bool isok(unsigned long long k) {
	unsigned long long  a[9];
	__uint128_t  b[9];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	for (int i = 0; i < 9; i++) {
		b[i] = getinbase(k, i + 2);
	}

	for (int i = 0; i < 9; i++) {
		a[i] = getdivider(b[i]);
		if (a[i] == 0) {
			return false;
		}
	}
	if (b[8] > P10_UINT64) {
		printf("%llu%019llu", (unsigned long long) (b[8] / P10_UINT64), (unsigned long long) (b[8] % P10_UINT64));
	}
	else {
		printf("%llu", (unsigned long long) (b[8] % P10_UINT64));
	}

	for (int i = 0; i < 9; i++) {
		printf(" %llu", a[i]);
	}
	printf("\n");
	return true;
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	for (int qq = 1; qq <= tt; qq++) {
		printf("Case #%d:\n", qq);
		int n, j, i = 0;
		unsigned long long k;
		scanf("%d %d", &n, &j);
		k = (1 << (n - 1)) + 1llu;
		while (i < j) {
			if (isok(k)) {
				i++;
			}
			k += 2llu;
		}
	}
	return 0;
}
