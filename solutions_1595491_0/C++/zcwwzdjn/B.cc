#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

namespace {
	const int kMaxN = 100, kMaxT = 30, kMaxPer = 10;
	int casen, n, s, p, t[kMaxN + 1];
	int g[kMaxT + 1][kMaxPer + 1], h[kMaxT + 1][kMaxPer + 1], f[kMaxN + 1][kMaxN + 1];
	int sg[kMaxT + 1][kMaxPer + 1], sh[kMaxT + 1][kMaxPer + 1];

	int QueryG(int x, int l, int r) {
		-- l;
		int lb = (l < 0 ? 0 : sg[x][l]), rb = (r < 0 ? 0 : sg[x][r]);
		return (rb - lb) > 0;
	}

	int QueryH(int x, int l, int r) {
		-- l;
		int lb = (l < 0 ? 0 : sh[x][l]), rb = (r < 0 ? 0 : sh[x][r]);
		return (rb - lb) > 0;
	}
		
	void Solve(FILE *fin, FILE *fout) {
		for (int i = 0; i <= kMaxPer; ++ i)
			for (int j = i; j <= kMaxPer; ++ j) 
				for (int k = j; k <= kMaxPer; ++ k)
					if (k - i < 2) g[i + j + k][k] = 1;
					else if (k - i == 2) h[i + j + k][k] = 1;
		for (int i = 0; i <= kMaxT; ++ i) {
			sg[i][0] = g[i][0];
			sh[i][0] = h[i][0];
			for (int j = 1; j <= kMaxPer; ++ j) {
				sg[i][j] = sg[i][j - 1] + g[i][j];
				sh[i][j] = sh[i][j - 1] + h[i][j];
			}
		}
		fscanf(fin, "%d", &casen);
		for (int cas = 0; cas ++ < casen; ) {
			fscanf(fin, "%d%d%d", &n, &s, &p);
			for (int i = 1; i <= n; ++ i) fscanf(fin, "%d", &t[i]);
			memset(f, -1, sizeof(f));
			f[0][0] = 0;
			for (int i = 0; i < n; ++ i)
				for (int j = 0; j <= s; ++ j)
					if (f[i][j] >= 0) {
						f[i + 1][j] = max(f[i + 1][j], f[i][j] + QueryG(t[i + 1], p, kMaxPer));
						f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + QueryH(t[i + 1], p, kMaxPer));
					}
			fprintf(fout, "Case #%d: %d\n", cas, f[n][s]);
		}
	}
}

int main() {
	::Solve(stdin, stdout);
	return 0;
}
