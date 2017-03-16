#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>
#include <cmath>

using namespace std;

ifstream fin ("c.in");
ofstream fout ("c.out");

int T, N, M, K;
int opt[1234];

int main () {
	fin >> T;
	for (int i =  1; i <= T; i++) {
		fout << "Case #" << i << ": ";
		fin >> N >> M >> K;
		for (int j = 0; j <= K; j++) {
			opt[j] = j;
		}
		for (int n = 1; n <= N-2; n++)
		for (int m = 1; m <= M-2; m++) {
			opt[n*m+2*n+2*m] = 2*n+2*m;
			//cerr << "opt(" << (n*m+2*n+2*m) << ") = " << (2*n+2*m) << '\n';
		}
		for (int j = 0; j <= K; j++) {
			opt[j] = min(opt[j], opt[j-1]+1);
		}
		fout << opt[K] << '\n';
	}	
	return 0;
}
