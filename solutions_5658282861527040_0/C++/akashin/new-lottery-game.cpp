#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

const char* inputFile = "B-small-attempt0.in";
const char* outputFile = "B-small-attempt0.out";

class Solver {
public:
	Solver() {
	}

	string solveTest() {
		int A, B, K;
		cin >> A >> B >> K;

		long long stupidSolution = solveStupid(A, B, K);

		return std::to_string(stupidSolution);
	}

	long long solveStupid(int A, int B, int K) {
		long long result = 0;
		for (size_t a = 0; a < A; ++a) {
			for (size_t b = 0; b < B; ++b) {
				if ((a & b) < K) {
					++result;
				}
			}
		}
		return result;
	}
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
