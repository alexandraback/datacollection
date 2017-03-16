#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

long long answers[100005];
int q = 0;

bool IsPalindrome(long long x) {
	int digs[20];
	int q = 0;
	while (x) {
		digs[q++] = x % 10;
		x /= 10;
	}
	for (int i = 0; i < q; ++i) {
		if (digs[i] != digs[q - 1 - i]) {
			return false;
		}
	}
	return true;
}

void Precalc() {
	for (long long i = 0; i <= 10000000; ++i) {
		if (IsPalindrome(i) && IsPalindrome(i * i)) {
			answers[q++] = i * i;
			cerr << i * i << endl;
		}
	}
}

int main() {
	freopen("c_easy.in", "r", stdin);
	freopen("c_easy.out", "w", stdout);
	Precalc();
	cerr << q << endl;
	int T;
	scanf("%d", &T);
	for (int I = 0; I < T; ++I) {
		printf("Case #%d: ", I + 1);
		long long a, b;
		scanf("%lld%lld", &a, &b);
		int result = 0;
		for (int i = 0; i < q; ++i) {
			if (answers[i] >= a && answers[i] <= b) {
				++result;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}