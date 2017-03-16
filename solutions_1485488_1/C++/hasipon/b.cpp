#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		int H, N, M;
		cin >> H >> N >> M;
		vector<vector<int> > C(N, vector<int>(M));
		vector<vector<int> > F(N, vector<int>(M));
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				cin >> C[i][j];
			}
		}
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				cin >> F[i][j];
			}
		}
		vector<vector<int> > T(N, vector<int>(M, 1<<30));
		priority_queue<pair<int, pair<int,int> > > Q;
		T[0][0] = 0;
		Q.push(make_pair(0, make_pair(0, 0)));
		int di[] = {+1, -1, 0, 0};
		int dj[] = {0, 0, +1, -1};
		while (!Q.empty()) {
			int tt = -Q.top().first;
			int ii = Q.top().second.first;
			int jj = Q.top().second.second;
			Q.pop();
			if (tt != T[ii][jj]) continue;
			for (int d = 0; d < 4; ++ d) {
				int i = ii+di[d];
				int j = jj+dj[d];
				if (0 <= i && i < N && 0 <= j && j < M) {
					if (F[ii][jj] <= C[i][j]-50 && F[i][j] <= C[i][j]-50 && F[i][j] <= C[ii][jj]-50) {
						int t = max(tt, H - (C[i][j]-50));
						if (t > 0) {
							if (H - t >= F[ii][jj]+20) {
								t += 10;
							} else {
								t += 100;
							}
						}
						if (t < T[i][j]) {
							T[i][j] = t;
							Q.push(make_pair(-t, make_pair(i,j)));
						}
					}
				}
			}
		}
		printf("Case #%d: %f\n", tt, T[N-1][M-1]*0.1);
	}
}
