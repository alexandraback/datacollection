#include <cstdlib>
#include <iostream>
#include <fstream>
#include "assert.h"

using namespace std;

int main(int argc, char** argv) {
	ofstream fout("D.small.out");
	ostream & out = fout;
	ifstream fin("D-small-attempt0.in");
	int T, K, C, S;
	fin >> T;
	for (int t = 1; t <= T; ++t) {
		fin >> K >> C >> S;
		if (S == K) {
			out << "Case #" << t << ": ";
			for (int i = 1; i <= S; ++i) {
				out << i << " ";
			}
			out << endl;
		} else {
			assert(false);
		}
	}
	
	return 0;
}

