#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N(1010);

int ca, n, m, kk;
int res[N];
int f[2][N][N];

void upd(int &v, int nv) {
	if (v == -1 || v > nv) v = nv;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> ca;
	for (int C = 1; C <= ca; ++C) {
		cin >> n >> m >> kk;
		memset(res, -1, sizeof(res));
		memset(f, -1, sizeof(f));
		int cur = 0;
		for (int i = 1; i <= m; ++i)
			upd(f[0][i][i], i);
		for (int i = 1; i != n; ++i, cur ^= 1) {
			for (int j = 0; j <= m; ++j)
				memset(f[cur ^ 1][j], -1, sizeof(f[cur ^ 1][j]));
			for (int j = 0; j <= m; ++j)
				for (int k = 0; k <= i * m; ++k)
					if (f[cur][j][k] != -1) {
						for (int l = max(j - 2, 1); l <= min(j + 2, m); ++l)
							upd(f[cur ^ 1][l][k + l], f[cur][j][k] + min(2, l));
					}
			for (int j = 0; j <= m; ++j)
				for (int k = 0; k <= (i + 1) * m; ++k)
					if (f[cur ^ 1][j][k] != -1) upd(res[k], f[cur ^ 1][j][k] + max(0, j - 2));
		}
		int ans = res[kk];
		upd(ans, kk);
		for (int i = n * m; i; --i)
			if (res[i] != -1) upd(res[i - 1], res[i]);
		cout << "Case #" << C << ": " << ans << endl;
	}
	return 0;
}