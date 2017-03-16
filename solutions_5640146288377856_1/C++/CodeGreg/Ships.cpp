#include <iostream>
#include <math.h>
#include <fstream>
#include <stdio.h>

using namespace std;

int T, R, C, W;

ifstream fin ("A-large.in");
ofstream fout ("A-large.out");

int main() {
	fin >> T;
	for (int t = 1; t <= T; ++t) {
		fin >> R >> C >> W;
		int result = (R - 1) * ceil((double)C / W);
		result += ceil((double)C / W) + (W - 1);
//		printf("result: %d\n", result);
		fout << "Case #" << t << ": " << result << endl;
	}


	return 0;
}
