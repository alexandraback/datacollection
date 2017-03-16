#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long INT;

const int N = 20000;

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

inline INT getP1(INT x) {
	INT y = x, t = 0, p = 1;
	x /= 10;
	while(x) {
		t = t * 10 + x % 10; p = p * 10; x /= 10;
	}
	return y * p + t;
}

inline INT getP2(INT x) {
	INT y = x, t = 0, p = 1;
	while(x) {
		t = t * 10 + x % 10; p = p * 10; x /= 10;
	}
	return y * p + t;
}

int main() {
	int re, ri = 1;
	INT a, b;

	for (int i = 1; i < N; i++) {
		INT p, t;
		p = getP1(i); t = p * p;
		if (isP(t)) {
			val[cnt++] = t;
		}

		p = getP2(i); t = p * p;
		if (isP(t)) {
			val[cnt++] = t;
		}
	}
	sort(val, val + cnt);



//	printf("%d\n", cnt);
//	for (int i = 0; i < cnt; i++) {
//		printf("%I64d %I64d\n", (INT)sqrt((double)val[i]), val[i]);
//	}
//	return 0;



	freopen("D:\\Work\\GCJ2013\\C\\C-large-1.in", "r", stdin);
	freopen("D:\\Work\\GCJ2013\\C\\C-large-1.out", "w", stdout);

	scanf("%d", &re);
	while(re--) {
		scanf("%I64d%I64d", &a, &b);

		INT *i = lower_bound(val, val + cnt, a);
		INT *j = upper_bound(val, val + cnt, b);
		printf("Case #%d: %d\n", ri++, (int)(j - i));
	}

	return 0;
}
