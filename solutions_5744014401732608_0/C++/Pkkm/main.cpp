#include <bits/stdc++.h>
using namespace std;

#define ARRAY_LEN(array) (sizeof(array) / sizeof(*array))
#define SIZEOF_MEMBER(type, member) (sizeof(((type *) NULL)->member))

template <typename T> T gcd(T x, T y) { return y == 0 ? x : gcd(y, x % y); }
int ffs(long long x) { return __builtin_ffsll(x); } // Find First Set -- 1 + index of the rightmost 1-bit; 0 if all bits are 0.
int popcount(long long x) { return __builtin_popcountll(x); } // Count the number of 1-bits.

typedef int64_t Num;
//typedef __int128 num;
#define PRINUM PRId64
#define SCANUM SCNd64

bool debug = true;
#define DEBUG_WRAP(...) \
	do { if (debug) { \
			fflush(stdout); \
			fprintf(stderr, "[D] %s:%d:%s: ", __FILE__, __LINE__, __func__); \
			__VA_ARGS__; \
			fflush(stderr); \
		} } while(0)
#define DEBUG(fmt, ...) DEBUG_WRAP(fprintf(stderr, fmt "\n", ##__VA_ARGS__))
#define DUMP(expr) DEBUG_WRAP(cerr << #expr << " = " << (expr) << "\n")

template<typename T>
T powi(T base, T exponent) {
	T result = 1;
	while (exponent > 0) {
		if (exponent & 1)
			result *= base;
		exponent >>= 1;
		base *= base;
	}

	return result;
}

void handle_case(int case_num) {
	int n_build, n_paths;
	scanf(" %d %d", &n_build, &n_paths);

	int **adj = new int*[n_build];
	for (int i = 0; i < n_build; i++) {
		adj[i] = new int[n_build];
		for (int j = 0; j < n_build; j++) {
			adj[i][j] = 0;
		}
	}

	if (n_build == 2) {
		if (n_paths == 1) {
			printf("POSSIBLE\n01\n00\n");
			return;
		}

		printf("IMPOSSIBLE\n");
		return;
	}

	int n_vert;
	for (n_vert = 3; !(powi(2, n_vert - 2) > n_paths); n_vert++);

	if (n_vert > n_build) {
		printf("IMPOSSIBLE\n");
		return;
	}

	for (int from = 1; from <= n_build - 2; from++) {
		for (int to = from + 1; to <= n_build - 1; to++) {
			adj[from][to] = 1;
		}
	}

	int m1 = n_paths - 1;
	for (int i = 0; i < n_vert - 2; i++) {
		if ((m1 >> i) & 1) {
			adj[0][n_build - 2 - i] = 1;
		}
	}
	adj[0][n_build - 1] = 1;

	printf("POSSIBLE\n");
	for (int row = 0; row < n_build; row++) {
		for (int col = 0; col < n_build; col++) {
			printf("%d", adj[row][col]);
		}
		printf("\n");
	}

	fflush(stdout);
}

int main(void) {
	char n_cases_str[64];
	fgets(n_cases_str, sizeof(n_cases_str), stdin);
	int n_cases;
	sscanf(n_cases_str, " %d ", &n_cases);

	for (int case_num = 1; case_num <= n_cases; case_num++) {
		printf("Case #%d: ", case_num);
		handle_case(case_num);
		printf("\n");
	}

	return 0;
}
