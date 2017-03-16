#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 1000000000

int N, M, H;

int c[128][128];
int f[128][128];
bool visited[128][128];
bool vndrop[128][128];

int memo[128][128][1024][2];
int dn[4] = {1, 0, -1, 0};
int dm[4] = {0, 1, 0, -1};

inline int min(const int &a, const int &b) {
	return a < b ? a : b;
}
int dp(int n, int m, int h, bool drop) {
	if (c[n][m] - h < 50) return INF;
	if (c[n][m] - f[n][m] < 50) return INF;
	if (h == 0) {
		if (vndrop[n][m]) return INF;
		vndrop[n][m] = true;
	}
	if (drop == 0) {
		if (visited[n][m]) return INF;
		visited[n][m] = true;
	}
	if (n == N-1 && m == M-1) return 0;
	
	if (memo[n][m][h][drop] != -1) return memo[n][m][h][drop];
	
	
	int water = h - f[n][m];
	
	int nw=0, tm=0;
	if (drop) {
		tm = water >= 20 ? 10 : 100;
		nw = h - tm;
	} else {
		nw = h;
		tm = 0;
	}
	if (nw < 0) nw = 0;

	int tr = INF;
	for (int d=0;d<4;++d) {
		int nn = n + dn[d];
		int mm = m + dm[d];
		int t;
		
		if (nn < 0 || nn >= N) continue;
		if (mm < 0 || mm >= M) continue;		
		
		if (c[nn][mm] - f[n][m] < 50) continue;
		if (c[n][m] - f[nn][mm] < 50) continue;
		
		if (c[nn][mm] - h < 50) {
			if (drop) {
				// wait for water to drain
				int nnw = c[nn][mm] - 50;
				int ttm = 0;
				
				if (nnw - f[n][m] >= 20){
					ttm = 10;
				} else {
					ttm = 100;
				}

				int nw = nnw - ttm;
				if (nw < 0) nw = 0;
				t = (h - nnw) + dp(nn, mm, nw, drop);
				t += ttm;
			}
		} else {
			t = dp(nn, mm, nw, drop);
			t += tm;
		}

		if (t < tr) tr = t;
	}
	
	if (!drop) {
		int t = dp(n, m, h, 1);
		if (t < tr) tr = t;
	}
	
	memo[n][m][h][drop] = tr;
	return tr;
}


int main() {
	int T;
	scanf(" %d", &T);
	for (int i=0;i<T;++i) {
		printf("Case #%d: ", (i+1));
		scanf(" %d%d%d", &H, &N, &M);
		
		for (int i=0;i<N;++i) {
			for (int j=0;j<M;++j) {
				scanf(" %d", &c[i][j]);
			}
		}
		for (int i=0;i<N;++i) {
			for (int j=0;j<M;++j) {
				scanf(" %d", &f[i][j]);
			}
		}
		
		memset(visited, 0, sizeof visited);
		memset(vndrop, 0, sizeof vndrop);
		memset(memo, -1, sizeof memo);
		printf("%.1f\n", (double)dp(0, 0, H, 0)/10);
	}
	return 0;
}
