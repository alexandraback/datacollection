#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

ifstream fin ("C.in");
ofstream fout ("C.out");

int f (int a, int b) {
	bool minus_flag = (a*b < 0);
	int minus = 1;
	if (minus_flag) minus = -1;
	a = abs(a);
	b = abs(b);
	if (a == 1 || b == 1) return minus * a * b;
	if (a == b) return minus * -1;
	if (a == 2 && b == 3) return minus * 4;
	if (a == 2 && b == 4) return minus * -3;
	if (a == 3 && b == 2) return minus * -4;
	if (a == 3 && b == 4) return minus * 2;
	if (a == 4 && b == 2) return minus * 3;
	if (a == 4 && b == 3) return minus * -2;
	return 0;
}


int main() {
	int T;
	fin >> T;
	for (int c = 1; c <= T; c++) {
		long long L, X;
		string S = "", orig;
		fin >> L >> X;
		if (X > 4) {
			X = (X % 4) + 4;
		}
		fin >> orig;
		for (int i = 0; i < X; i++) {
			S += orig;
		}
		vector<int> items(S.size());
		for (int i = 0; i < X*L; i++) {
			if (S[i] == 'i') items[i] = 2;
			if (S[i] == 'j') items[i] = 3;
			if (S[i] == 'k') items[i] = 4;
		}
		vector<int> prods(S.size());
		prods[0] = items[0];
		for (int i = 1; i < X*L; i++) {
			prods[i] = f(prods[i-1], items[i]);
		}
		// NECESITO EN ORDEN i, i * j, i * j * k
		// NECESITO EN ORDEN i, k, k * k
		// NECESITO EN ORDEN i, k, -1
		// NECESITO EN ORDEN 2, 4, -1
		int count = 0;
		for (int i = 0; i < X*L-1; i++) {
			if (count == 0 && prods[i] == 2) count++;
			if (count == 1 && prods[i] == 4) count++;
			if (count == 2 && prods[X*L-1] == -1) count++;
		}
		if (count == 3) fout << "Case #" << c << ": YES" << endl;			else fout << "Case #" << c << ": NO" << endl; 
	}


}
