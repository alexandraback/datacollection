#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

double solve(int A, int B, double *M) {
	double p = 1;
	double result = 2 + B;
	for (int i = 0; i <= A; i++) {
		double x = 2 * (A - i) + (B - A) + 1;
		double y = x + 1 + B;
		result = min(result, x * p + y * (1 - p));
		if (i < A) {
			p *= M[i];
		}
	}
	return result;
}

int main() {
	int T;
	double *M = new double[100000];
	fin >> T;

	for (int i = 0; i < T; i++) {
		int A, B;
		fin >> A >> B;
		for (int j = 0; j < A; j++) {
			fin >> M[j];
		}
		char buffer[100];
		sprintf(buffer, "%.8lf", solve(A, B, M));
		fout << "Case #" << (i + 1) << ": " << buffer << "\n";
	}

	delete[] M;
	return 0;
}
