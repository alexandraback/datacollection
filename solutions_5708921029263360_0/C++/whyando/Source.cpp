#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

ofstream fout("out.txt");
ifstream fin("in.txt");

void function1(const int test_no) {
	int J, P, S,K;
	fin >> J;
	fin >> P;
	fin >> S;
	fin >> K;
	int a = J*P*min(S, K);
	fout << "Case #" << test_no << ": " << a << endl;
	for (int j = 1; j <= J && j<=K; j++) {
		for (int p = 1; p <= P && p<=K; p++) {
			for (int s = 1; s <= S && s <= K; s++)
				fout << j << " " << p << " " << s << endl;
		}
	}

	
}

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		function1(t);
	}

	return 0;
}
