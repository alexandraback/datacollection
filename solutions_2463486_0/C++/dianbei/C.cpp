#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long INT;

const int N = 20000000;
// const int N = 2000;

INT val[N];
int cnt = 0;

inline int isP(INT x) {
	int a[20], c = 0;
	while(x) {
		a[c++] = x % 10; x /= 10;
	}
	for (int i = 0; i < c / 2; i++) {
		if (a[i] != a[c - 1 - i]) return false;
	}
	return true;
}

int main() {
	int re, ri = 1;
	INT a, b;

	for (int i = 0; i < N; i++) {
		if (!isP(i)) continue;
		INT t = (INT)i * i;
		if (isP(t)) {
			val[cnt++] = t;
		}
	}
	// printf("%d\n", cnt);
	// printf("%I64d\n", val[cnt - 1]);

	// freopen("D:\\Work\\GCJ2013\\B\\B-large.in", "r", stdin);
	// freopen("D:\\Work\\GCJ2013\\B\\B-large.out", "w", stdout);

	scanf("%d", &re);
	while(re--) {
		scanf("%I64d%I64d", &a, &b);

		INT *i = lower_bound(val, val + cnt, a);
		INT *j = upper_bound(val, val + cnt, b);
		printf("Case #%d: %d\n", ri++, (int)(j - i));
	}

	return 0;
}
