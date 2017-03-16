#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <iostream>
using namespace std;
typedef int64_t i64;

i64 p, q;

i64 gcd(i64 m, i64 n) {
	if (m == 0) {
		return n;
	}
	if (n == 0) {
		return m;
	}
	if (m < n) {
		swap(m, n);
	}
	while (n != 0) {
		i64 rem = m % n;
		m = n;
		n = rem;
	}
	return m;
}

void init() {
	char str[100];
	scanf("%s", str);
	int pos;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '/') {
			pos = i;
			break;
		}
	}
	p = 0;
	q = 0;
	for (int i = 0; i < pos; i++) {
		p *= 10LL;
		p += (i64)(str[i] - '0');
	}
	for (int i = pos + 1; i < strlen(str); i++) {
		q *= 10LL;
		q += (i64)(str[i] - '0');
	}
}

void calc() {
	int ans = -1;
	for (int i = 1; i <= 40; i++) {
		if (p == 0) {
			break;
		}
		i64 g = gcd(p, q);
		p /= g;
		q /= g;
		p *= 2LL;
		if (p >= q) {
			if (ans == -1) {
				ans = i;
			}
			p -= q;
		}
	}
	if (p != 0 ) {
		printf("impossible\n");
	} else {
		printf("%d\n", ans);
	}
}

int main() {
	int tcase;
	scanf("%d", &tcase);
	for (int i = 1; i <= tcase; i++) {
		init();
		printf("Case #%d: ", i);
		calc();
	}
	return 0;
}