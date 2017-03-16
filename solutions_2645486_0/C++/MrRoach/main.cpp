// Problem 2, Round 1A, GCJ 2013
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int T, e, r, n;
int v[100];
int f[15][10];

int main() {
	cin >> T;
	for (int caseNum = 0; caseNum < T; ++caseNum) {
		cin >> e >> r >> n;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		f[0][e] = 0;
		for (int i = 0; i < e; ++i) {
			f[0][i] = -10000000;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= e; ++j) {
				f[i][j] = -100000000;
				for (int k = max(j - r, 0); k <= e; ++k) {
					int nv = f[i-1][k] + (min(k + r, e) - j) * v[i - 1];
					if (nv > f[i][j]) f[i][j] = nv;
				}
			}
		}
		int maxv = -1000000;
		for (int i = 0; i <= e; ++i) {
			if (f[n][i] > maxv) {
				maxv = f[n][i];
			}
		}
		cout << "Case #" << caseNum + 1 << ": " << maxv << endl;
	}

	return 0;
}