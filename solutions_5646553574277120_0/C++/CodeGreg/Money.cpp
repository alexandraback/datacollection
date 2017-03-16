#include <iostream>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int T, C, D, V;
int denoms[1000];
bool possible[101];

ifstream fin ("C-small-attempt1.in");
ofstream fout ("C-small-attempt1.out");

int main() {
	fin >> T;
	for (int t = 1; t <= T; ++t) {

		fin >> C >> D >> V;
		for (int d = 0; d < D; ++d)
			fin >> denoms[d];
		sort(denoms, denoms + D);

		fill_n(possible, V + 1, false);

		int addnum = 0;
		possible[0] = true;
		for (int d = 0; d < D; ++d) {
//			printf("d %d (=%d), D_N %d\n", d, denoms[d], D_N);

			for (int k = 1; k < denoms[d]; ++k) {
				if (!possible[k]) {
					for (int i = 0; i < C; ++i)
						for (int v = V; v >= k; --v)
							if (!possible[v])
								possible[v] = possible[v - k];
					addnum++;
				}
			}
			for (int i = 0; i < C; ++i) {
				for (int v = V; v >= denoms[d]; --v)
					if (!possible[v])
						possible[v] = possible[v - denoms[d]];
			}
		}

		for (int k = 1; k <= V; ++k) {
			if (!possible[k]) {
				for (int i = 0; i < C; ++i)
					for (int v = V; v >= k; --v)
						if (!possible[v])
							possible[v] = possible[v - k];
				addnum++;
			}
		}

		fout << "Case #" << t << ": " << addnum << endl;
	}

	return 0;
}
