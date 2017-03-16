#include <iostream>
using namespace std;

bool mm[10000001];

long long count(int num, int low, int high) {
	long long ret = 0;
	int base = 1;
	int x = num;
	while (x) {
		x = x / 10;
		base *= 10;
	}
	base /= 10;

	while (!mm[num]) {
		mm[num] = true;
		if (num >= low && num <= high) {
			++ret;
		}
		int d = num % 10;
		num = num / 10 + base * d;
	}
	return ret * (ret - 1) / 2;
}

int main() {
	int T;
    freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &T);
	int b = 0;
	while (T--) {
		memset(mm, 0, sizeof(mm));
		int A, B;
		scanf("%d%d", &A, &B);
		long long ret = 0;
		for (int i = A; i <= B; ++i) {
			if (!mm[i]) {
			    ret += count(i, A, B);
			}
		}
		printf("Case #%d: %lld\n", ++b, ret);
	}
	return 0;
}

