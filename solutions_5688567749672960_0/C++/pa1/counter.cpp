#include <iostream>
#define forn(i, s, n) for (int i = (s); i < (n); i++)
#define sI(N) scanf("%d", &N)
using namespace std;

int rev_num(int N) {
	int rev = 0;
	while (N > 0) {
		rev = rev * 10 + N % 10;
		N = N / 10;
	}
	return rev;
}

int main() {
	int T, t;
	int A[1000008];
	A[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if ((i % 10) != 0 && (rev_num(i) < i)) {
			A[i] = min(A[i - 1] + 1, A[rev_num(i)] + 1);
		} else {
			A[i] = A[i - 1] + 1;
		}
	}
	sI(T);
	forn(t, 1, T + 1) {
		int N;
		sI(N);
		printf("Case #%d: %d\n", t, A[N]);
	}
	return 0;
}