#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int R, N, M, K;
int product[8];
int poss[100];

int check(int a[]) {
	memset(poss, 0, sizeof(poss));
	for (int i = 0; i < 8; ++i) {
		int prod = 1;
		for (int j = 0; j < 3; ++j) if (i & (1 << j)) prod *= a[j];
		poss[prod] = 1;
	}
	for (int i = 0; i < K; ++i) if (!poss[product[i]]) return 0;
	return 1;
}

string solve() {
	for (int a = 2; a <= M; ++a)
		for (int b = 2; b <= M; ++b)
			for (int c = 2; c <= M; ++c) {
				int A[3];
				A[0] = a; A[1] = b; A[2] = c;
				if (check(A)) {
					stringstream ss;
					ss << a << b << c;
					return ss.str();
				}
			}
	return "";
}

int main() {
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; ++c) {
		printf("Case #%d:\n", c);
		scanf("%d%d%d%d", &R, &N, &M, &K);

		for (int r = 0; r < R; ++r) {
			for (int i = 0; i < K; ++i) scanf("%d", product + i);

			printf("%s\n", solve().c_str());
		}

	}
}
