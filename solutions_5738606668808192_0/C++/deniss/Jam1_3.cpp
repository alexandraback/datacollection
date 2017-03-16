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


unsigned long long getinbase(unsigned long long k, int base) {
	unsigned long long ans = 0;
	if (base == 2) {
		return k;
	}
	string s = bitset< 32 >(k).to_string();

	for (int i = s.size()-1; i > -1; i--) {
		if (s[i] == '0') continue;
		ans += pow(base, s.size() -1 - i);
	}
	
	return ans;
}

unsigned long long getdivider(unsigned long long k) {
	unsigned long long l = 2;
	while (l < sqrt(k) && k % l) {
		l++;
	}
	if (!(k % l)) return l;

	return 0;
}


bool isok(unsigned long long k) {
	unsigned long long  a[9];
	unsigned long long  b[9];
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
	printf("%llu", b[8]);
	for (int i = 0; i < 9; i++) {
		printf(" %d", a[i]);
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
		k = (1 << (n-1)) + 1;
		while (i < j) {
			if (isok(k)) {
				i++;
			}
			k += 2;
		}
	}
	return 0;
}
