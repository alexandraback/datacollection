#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

long long P, Q;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a%b);
}

void read() {
	scanf("%lld/%lld", &P, &Q);
}

void process(int testcase) {
	if (P > Q) {
		printf("Case #%d: impossible\n", testcase);
	}
	long long mdc = gcd(P, Q);
	P /= mdc;
	Q /= mdc;
	int cnt = 0;
	while (Q % 2 == 0) {
		Q /= 2;
		cnt++;
	}
	if (Q == 1) {
		if ((P >> cnt) <= 1) {
			while (P >= 2) {
				P /= 2;
				cnt--;
			}
			cnt = max(cnt, 1);
			printf("Case #%d: %d\n", testcase, cnt);
			return;
		}
	}
	printf("Case #%d: impossible\n", testcase);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		read();
		process(t);
	}
	return 0;
}