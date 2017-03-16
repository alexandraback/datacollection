#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void printcase(int i) {
	cout << "Case #" << i+1 << ": ";
}

void printArray(int** A, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << A[i][j];
		}
		cout << endl;
	}
}

unsigned long exp(int base, int power) {
	unsigned long ret = 1;
	while (power > 0) {
		ret *= base;
		power--;
	}
	return ret;
}

// computes k where 2^k is the largest power of 2 less than or equal to n
int largestPowof2(unsigned long n) {
	if (n == 0) return -1;
	int k = 0;
	int pow2k = 1;
	while (pow2k <= n) {
		k += 1;
		pow2k *= 2;
	}
	k -= 1;
	pow2k /= 2;
	return k;
}

bool solve(int** A, int B, unsigned long M) {
	if (exp(2, B-2) < M) return false;
	for (int i = 0; i < B; ++i) {
		for (int j = i+1; j < B; ++j) {
			A[i][j] = 1;
		}
	}
	unsigned long n = exp(2, B-2) - M;
	while (n > 0) {
		int k = largestPowof2(n);
		n -= exp(2, k);
		A[k+1][B-1] = 0;
	}
	return true;
}

int main() {
	int T;
	int N;
	int B;
	unsigned long M;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		printcase(i);
		cin >> B >> M;
		int** A;
		A = new int*[B];
		for (int j = 0; j < B; ++j) {
			A[j] = new int[B];
		}
		for (int j = 0; j < B; ++j) {
			for (int k = 0; k < B; ++k) {
				A[j][k] = 0;
			}
		}
		if (solve(A, B, M)) {
			cout << "POSSIBLE" << endl;
			printArray(A, B, B);
		} else {
			cout << "IMPOSSIBLE" << endl;
		}

		for (int j = 0; j < B; ++j) {
			delete[] A[j];
		}
		delete[] A;
	}

	return 0;
}