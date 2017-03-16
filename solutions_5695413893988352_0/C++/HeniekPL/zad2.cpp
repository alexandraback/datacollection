#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int C_MAX = 3;
const int D_MAX = 10;

int W[2][C_MAX][D_MAX];
vector<int> v[2];

int f(int id, char del) {
	int c;
	int n = 0;
	while ((c = getchar()) != del) {
		if (c == '?') {
			for (int i = 0; i < D_MAX; ++i)
				W[id][n][i] = 1;
		} else {
			W[id][n][c - '0'] = 1;
		}
		++n;
	}
	return n;
}

void g(int id, int x, int n, int level) {
	if (level == n) {
		v[id].push_back(x);
	}
	for (int j = 0; j < D_MAX; ++j) {
		if (W[id][level][j] == 1) {
			g(id, 10*x + j, n, level + 1);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T); getchar();
	for (int t = 1; t <= T; ++t) {
		v[0].clear();
		v[1].clear();
		for (int i = 0; i < C_MAX; ++i)
			for (int j = 0; j < D_MAX; ++j) {
				W[0][i][j] = 0;
				W[1][i][j] = 0;
			}
		int n = f(0, ' ');
		f(1, '\n');
		g(0, 0, n, 0);
		g(1, 0, n, 0);
		int resultA = 10000, resultB = 10000, diff_min = 10000;
		int i = 0, j = 0;
		while (i < v[0].size() && j < v[1].size()) {
			int a = v[0][i];
			int b = v[1][j];
			int diff = abs(a - b);
			if (diff < diff_min
			|| (diff == diff_min && a < resultA)
			|| (diff == diff_min && a == resultA && b < resultB)
			) {
				diff_min = diff;
				resultA = a;
				resultB = b;
			}
			if (a < b) i++;
			else j++;
		}
		printf("Case #%d: %0*d %0*d\n", t, n, resultA, n, resultB);
	}
	return 0;
}