#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("A.in");
ofstream fout ("A.out");

int main() {
	int T;
	fin >> T;
	string S;
	for (int c = 1; c <= T; c++) {
		int cumsum = 0;
		int top = 0;
		int L;
		fin >> L;
		fin >> S;
		for (int i = 0; i < S.size(); i++) {
			if (i - cumsum > top) top = i - cumsum;
			cumsum += (int) S[i] - (int) '0';
		}
		fout << "Case #" << c << ": " << top << endl;
	}
	return 0;
}
