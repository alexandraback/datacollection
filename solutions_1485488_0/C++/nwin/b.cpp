#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int N, M, H;
int fl[110][100], ce[110][110];
int dx[5] = {-1, 0, 0, 1};
int dy[5] = {0, -1, 1, 0};
const double inf = 1e30;
const double eps = 1.e-8;
typedef pair<double, pair<int, int> > quedata;
bool isvalid(int h, int w) {
	return h >= 0 && h < N && w >= 0 && w < M && ce[h][w] - fl[h][w] >= 50;
}
void solve() {
	double tl[110][110][5];
	bool done[110][110] = {};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int d = 0; d < 4; d++) {
				int ni = i + dy[d], nj = j + dx[d];
				tl[i][j][d] = inf;
				if (!isvalid(ni, nj) || ce[i][j] - fl[i][j] < 50) continue;
				if (ce[i][j] - 50 < fl[ni][nj]) continue;
				if (ce[ni][nj] - 50 < fl[i][j]) continue;
				
				double tmp = max(0.0, (H - ce[i][j] + 50) / 10.0);
				tmp = max(tmp, (H - ce[ni][nj] + 50) / 10.0);
				tl[i][j][d] = tmp;
			//	printf("%d %d->%d %d: %f\n", i, j, ni, nj, tmp);
			}
		}
	}
	priority_queue<quedata> que;
	que.push(quedata(0.0, make_pair(0, 0)));
	while (que.size()) {
		quedata data = que.top(); que.pop();
		int i = data.second.first, j = data.second.second;
		double time = -data.first;
		if (done[i][j]) continue;
		done[i][j] = 1;
		if (i == N - 1 && j == M - 1 && time < inf - eps) {
			printf("%.8f", time);
			return ;
		}
		for (int d = 0; d < 4; d++) {
			int ni = i + dy[d], nj = j + dx[d];
			if (!isvalid(ni, nj) || done[ni][nj] || tl[i][j][d] > inf - eps) continue;
			quedata ndata(-0.0, make_pair(ni, nj));
			if (!(time < eps && tl[i][j][d] < eps)) {
				double tmp = max(time, tl[i][j][d]);
				if (H - tmp * 10 > fl[i][j] + 20 - eps)
					tmp += 1;
				else
					tmp += 10;
				ndata.first = -tmp;
			}
			que.push(ndata);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d%d%d", &H, &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &ce[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &fl[i][j]);
			}
		}
		printf("Case #%d: ", t + 1);
		solve();
		printf("\n");
	}
	return 0;
}
