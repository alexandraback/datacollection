#include <iostream>
using namespace std;

int N, M, A[30][30];
const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

inline int ins(int x, int X) {
	return 0 <= x && x < X;
}

void mark(int r, int c) {
	if(A[r][c] != 0) return;
	A[r][c] = 2;
	for(int i = 0; i < 4; i++) {
		int nr = r+dr[i], nc = c+dc[i];
		if(ins(nr, N) && ins(nc, M)) mark(nr, nc);
	}
}

int main() {
	int T, K, res;
	cin >> T;
	for(int cs = 1; cs <= T; ++cs) {
		cin >> N >> M >> K;
		res = K;
		for(int mask = 0; mask < (1<<(N*M)); ++mask) {
			if(__builtin_popcount(mask) >= res) continue;
			for(int r = 0; r < N; r++)
				for(int c = 0; c < M; c++)
					A[r][c] = (mask & (1<<(r*M+c))) ? 1 : 0;
			for(int r = 0; r < N; r++) {
				if(A[r][0] != 1) mark(r, 0);
				if(A[r][M-1] != 1) mark(r, M-1);
			}
			for(int c = 0; c < M; c++) {
				if(A[0][c] != 1) mark(0, c);
				if(A[N-1][c] != 1) mark(N-1, c);
			}
			int tk = 0;
			for(int r = 0; r < N; r++)
				for(int c = 0; c < M; c++)
					if(A[r][c] != 2) tk++;
			if(tk >= K) res = __builtin_popcount(mask);
		}
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}