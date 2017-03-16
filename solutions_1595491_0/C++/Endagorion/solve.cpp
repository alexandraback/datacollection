#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

int main() {
	fout.precision(10);
	fout << fixed;

	int T;
	fin >> T;
	
	for (int t = 1; t <= T; ++t) {
		int N, S, p;
		fin >> N >> S >> p;
		vector<int> scores(N);
		for (int i = 0; i < N; ++i) {
			fin >> scores[i];
		}
		vector< vector<int> > maxs(N + 1, vector<int>(N + 1, 0));
		for (int i = 0; i < N; ++i) {
			int nots = scores[i] >= 3 * p - 2 ? 1 : 0;
			int surp = scores[i] >= 3 * p - 4 ? 1 : 0;
			if (scores[i] <= 1 || scores[i] >= 29) {
				surp = -1000;
			}
			for (int s = 0; s <= i; ++s) {
				maxs[i + 1][s] = max(maxs[i + 1][s], maxs[i][s] + nots);
				maxs[i + 1][s + 1] = max(maxs[i + 1][s + 1], maxs[i][s] + surp);
			}
		}
		fout << "Case #" << t << ": " << maxs[N][S] << '\n';
	}

	return 0;
}
