#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
using namespace std;

typedef long long int64;

int64 reverse(int64 x) {
	int64 y = 0;
	while (x) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

int main() {
	int testCase;
	scanf("%d", &testCase);
	for (int test = 1; test <= testCase; ++test) {
		int64 N;
		scanf("%I64d", &N);
		int64 A = 0;
		while (true) {
			if (N < 10) {
				A += N;
				break;
			}
			int64 P = 1;
			while (P * P * 10 <= N) P *= 10;
			int64 T = N % P;
			if (T == 0) {
				N--;
				A++;
				continue;
			}
			N -= T - 1;
			A += T - 1;
			if (reverse(N) < N) {
				N = reverse(N);
				A++;
			}
			int64 Q = N % P;
			N -= Q + 1;
			A += Q + 1;
		}
		printf("Case #%d: %I64d\n", test, A);
	}
}