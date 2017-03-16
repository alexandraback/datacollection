#include <iostream>
#define forn(i, s, n) for (int i = (s); i < (n); i++)
#define sI(N) scanf("%d", &N)
using namespace std;

int A[1000008], B[1000008];
int pow10[17];

long long int rev_num(long long int N) {
	long long int rev = 0;
	while (N > 0) {
		rev = (long long int) rev * 10 + N % 10;
		N = N / 10;
	}
	return rev;
}

int digc(long long int N) {
	int dc = 0;
	while (N > 0) {
		dc++;
		N = N / 10;
	}
	return dc;
}

void print_path(int N) {
	while (B[N] > 0) {
		printf("%d -> ", N);
		N = B[N];
	}
	printf("\n");
}

long long int solve(long long int N) {
	//printf("N = %lld\n", N);
	if (N == 0) {
		return 0;
	}
	if (N == 1) {
		return 1;
	}

	long long int ans = 0;
	if ((N % 10) == 0) {
		N--;
		ans += 1;
	}
	int dc = digc(N);
	if (dc == 1) {
		return ans + N;
	}

	int m = (dc + 1) / 2;
	long long int h = N % pow10[m];
	if (h != 1) {
		ans += h - 1;
	}
	N = rev_num(N - h + 1);
	m = dc / 2;
	h = N % pow10[m];
	if (h > 1) {
		ans += h;
		N = N - h + 1;
	}	
	//printf("N = %lld, ans = %lld\n", N, ans);
	return ans + solve(N - 2) + 2;
}

int main() {
	int T, t;
	A[1] = 1;
	B[1] = 0;
	for (int i = 2; i <= 1000000; i++) {
		if ((i % 10) != 0 && (rev_num(i) < i)) {
			A[i] = min(A[i - 1] + 1, A[rev_num(i)] + 1);
			if (A[i] == A[i - 1] + 1) {
				B[i] = i - 1;
			} else {
				B[i] = rev_num(i);
			}
		} else {
			A[i] = A[i - 1] + 1;
			B[i] = i - 1;
		}
	}
	pow10[0] = 1;
	for (int i = 1; i <= 15; i++) {
		pow10[i] = (long long int)pow10[i - 1] * 10;
	}
	sI(T);
	forn(t, 1, T + 1) {
		long long int N;
		scanf("%lld", &N);
		//print_path(N);
		//printf("Case #%d: %d %d\n", t, A[N], (A[N] - 1) / 9);
		printf("Case #%d: %lld\n", t, solve(N));
		// if (N <= 1000000LL) {
		// 	printf("orig %d\n", A[N]);
		// }
	}
	// for (int i = 1; i <= 100000; i++) {
	// 	if (A[i] != solve(i)) {
	// 		printf("%d %d %lld\n", i, A[i], solve(i));
	// 	}
	// }

	return 0;
}