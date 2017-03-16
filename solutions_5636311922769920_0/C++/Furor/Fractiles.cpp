#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

LL follow(int i, int d, LL p, int k) {
	if (d == 0)
		return p;
	return follow(i, d - 1, p * k + i, k);
}

int main() {
	int cc, i, t, k, c, s;
	scanf("%d", &t);
	for (cc = 1; cc <= t; cc++) {
		scanf("%d %d %d", &k, &c, &s);
		printf("Case #%d:", cc);
		for (i = 0; i < k; i++)
			printf(" %I64d", follow(i, c - 1, i, k) + 1);
		printf("\n");
	}
	return 0;
}