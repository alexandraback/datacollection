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

int calc(int v, int u, vector< vector<int> > &ways, const vector< vector<int> > &inh) {
	if (v == u) {
		ways[v][u] = 1;
	}
	if (ways[v][u] != -1) {
		return ways[v][u];
	}
	int res = 0;
	for (size_t i = 0; i < inh[v].size(); ++i) {
		int w = inh[v][i];
		res = min(res + calc(w, u, ways, inh), 2);
	}
	return ways[v][u] = res;
}

int main() {
	fout.precision(10);
	fout << fixed;

	int T;
	fin >> T;

	for (int t = 1; t <= T; ++t) {
		int N;
		fin >> N;
		vector< vector<int> > inh(N);
		for (int i = 0; i < N; ++i) {
			int m;
			fin >> m;
			inh[i].resize(m);
			for (int j = 0; j < m; ++j) {
				fin >> inh[i][j];
				--inh[i][j];
			}
			sort(inh[i].begin(), inh[i].end());
		}
		bool ok = false;
		
		vector< vector<int> > ways(N, vector<int>(N, -1));
		for (int i = 0; !ok && i < N; ++i) {
			for (int j = 0; !ok && j < N; ++j) {
				if (calc(i, j, ways, inh) > 1) {
					ok = true;
				}
			}
		}

		fout << "Case #" << t << ": " << (ok ? "Yes" : "No") << '\n';
	}

	return 0;
}
