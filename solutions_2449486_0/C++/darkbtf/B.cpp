#include <cstdio>

int N, M;
int grd[101][101];
int flg[101][101];

bool chk(int thd) {
	for(int i = 0; i < N; ++i) {
		bool flag = true;
		for(int j = 0; j < M; ++j)
			if(grd[i][j] > thd) flag = false;
		if(!flag) continue;
		for(int j = 0; j < M; ++j)
			flg[i][j] = thd;
	}
	for(int i = 0; i < M; ++i) {
		bool flag = true;
		for(int j = 0; j < N; ++j)
			if(grd[j][i] > thd) flag = false;
		if(!flag) continue;
		for(int j = 0; j < N; ++j)
			flg[j][i] = thd;
	}
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			if(grd[i][j] <= thd && flg[i][j] != thd) return false;
	return true;
}

bool chk() {
	for(int i = 100; i >= 1; --i)
		if(!chk(i)) return false;
	return true;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				scanf("%d", &grd[i][j]);
		printf("Case #%d: ", t);
		puts(chk() ? "YES": "NO");
	}
}
