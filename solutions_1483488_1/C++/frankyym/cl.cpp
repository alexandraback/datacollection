#include <cstdio>
#include <iostream>
using namespace std;

int check[2000001];
int ret, A, B;

void solve(int k, int flag) {
	int kk = k, base = 1, len = 0;
	while (kk != 0) {
		kk /= 10;
		base *= 10;
		++len;
	}
	base /= 10;

	int cnt = 0;
	for (int i=0; i<=len; ++i) {
		if ((A <= k) && (k <= B)) {
			if (check[k] != flag) ++cnt;
			check[k] = flag;
		}
		int lastdigit = k % 10;
		k = k / 10 + lastdigit * base;
	}

	ret += cnt * (cnt - 1) / 2;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		scanf("%d%d", &A, &B);

		ret = 0;
		for (int k=A; k<=B; ++k) if (check[k] != t+1) {
			solve(k, t+1);
		}

		printf("Case #%d: %d\n", t+1, ret);
	}
	return 0;
}
