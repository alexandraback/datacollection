#include <cstdio>

using std::scanf;
using std::printf;

int A, B, K;

static void testcase(int t) {
	scanf("%i%i%i", &A, &B, &K);
	int cnt = A + B - 1;
	for(int a = 1; a < A; ++a)
		for(int b = 1; b < B; ++b)
			cnt += (a & b) < K;
	printf("Case #%d: %d\n", t, cnt);
}

int main() {
	int T;
	scanf("%i", &T);
	for(int t = 1; t <= T; ++t)
		testcase(t);
}
