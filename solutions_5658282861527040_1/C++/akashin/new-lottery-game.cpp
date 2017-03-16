#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cassert>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

const char* inputFile = "B-large.in";
const char* outputFile = "B-large.out";

// const char* inputFile = "file.in";
// const char* outputFile = "file.out";

class Solver {
public:
	Solver() {
	}

	string solveTest() {
		cin >> A >> B >> K;

		long long cleverSolution = solveClever(A, B, K);

		// long long stupidSolution = solveStupid(A, B, K);
		// if (stupidSolution != cleverSolution) {
		// 	std::cerr << A << " " << B << " " << K << std::endl;
		// 	std::cerr << stupidSolution << std::endl;
		// 	std::cerr << cleverSolution << std::endl;
		// 	assert(false);
		// }

		return std::to_string(cleverSolution);
	}

	inline bool bit(int X, int bit) const {
		return (X & (1ll<<bit));
	}

	long long calcDP(int len, bool tightA, bool tightB, bool tightK) {
		if (len == 0) {
			return (!tightA && !tightB && !tightK);
		}
		long long &res = dp[len][tightA][tightB][tightK];

		if (res == -1) {
			res = 0;
			for (int a = 0; a <= 1; ++a) {
				for (int b = 0; b <= 1; ++b) {
					int k = a & b;
					bool moreA = (a > bit(A, len - 1));
					bool moreB = (b > bit(B, len - 1));
					bool moreK = (k > bit(K, len - 1));
					bool lessA = (a < bit(A, len - 1)); 
					bool lessB = (b < bit(B, len - 1));
					bool lessK = (k < bit(K, len - 1));

					if (tightA && moreA) {
						continue;
					}
					if (tightB && moreB) {
						continue;
					}
					if (tightK && moreK) {
						continue;
					}

					res += calcDP(len - 1, tightA && !lessA, tightB && !lessB, tightK && !lessK);
				}
			}
		}
		return res;
	}

	long long solveClever(int A, int B, int K) {
		memset(dp, -1, sizeof(dp));
		return calcDP(32, 1, 1, 1);
		//return calcDP(3, 1, 1, 1);
	}

	long long solveStupid(int A, int B, int K) {
		long long result = 0;
		for (size_t a = 0; a < A; ++a) {
			for (size_t b = 0; b < B; ++b) {
				//cerr << a << " " << b << std::endl;
				if ((a & b) < K) {
					++result;
				}
			}
		}
		return result;
	}

	int A, B, K;
	long long dp[50][2][2][2];
};

int main() {
	freopen(inputFile, "r", stdin);
	freopen(outputFile, "w", stdout);
	int T;
	scanf("%d", &T);

	for (int testNumber = 1; testNumber <= T; ++testNumber) {
		Solver solver;
		string verdict = solver.solveTest();
		printf("Case #%d: %s\n", testNumber, verdict.c_str());
	}
	return 0;
}
