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

bool all_filled(int *c){
	for (int i = 0; i < 10; i++) {
		if (c[i] != 1) {
			return false;
		}
	}
	return true;
}

void fill(int *c, unsigned long long n) {
	while (n > 0) {
		c[n % 10] = 1;
		n = n / 10;
	}
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	for (int qq = 1; qq <= tt; qq++) {
		printf("Case #%d: ", qq);
		unsigned long long n;
		scanf("%llu", &n);
		if (n == 0) {
			printf("INSOMNIA\n");
			continue;
		}
		unsigned long long i = 1;
		int c[10];
		memset(c, 0, sizeof(c));
		while (!all_filled(c)) {
			fill(c, n * i);
			i++;
		}

		printf("%llu\n", n * (i - 1ull));
	}
	return 0;
}
