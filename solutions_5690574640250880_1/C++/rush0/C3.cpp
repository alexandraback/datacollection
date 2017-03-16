#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define OUT(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;

void print(int R, int C, int mine[][55]) {
	REP(i, R) {
		REP(j, C) putchar(mine[i][j]);
		putchar('\n');
	}
}

const int dx[] = {0, -1, -1, -1,  0,  1, 1, 1};
const int dy[] = {1,  1,  0, -1, -1, -1, 0, 1};
bool valid(int R, int C, int mine[][55], int cx, int cy) {
	int cnt[55][55];
	REP(i, R) REP(j, C) cnt[i][j] = 0;

	REP(i, R) REP(j, C) {
		if (mine[i][j] == '*') {
			cnt[i][j] += 1;
			REP(k, 8) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < R && 0 <= ny && ny < C) {
					cnt[nx][ny] += 1;
				}
			}
		}
	}

	typedef pair<int, int> PII;
	queue<PII> q;
	bool vis[55][55];
	memset(vis, false, sizeof(vis));
	q.push(PII(cx, cy)), vis[cx][cy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (cnt[x][y] != 0) continue;
		REP(k, 8) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < R && 0 <= ny && ny < C &&
				mine[nx][ny] != '*' && !vis[nx][ny]) {
				q.push(PII(nx, ny)), vis[nx][ny] = true;
			}
		}
	}

	REP(i, R) REP(j, C) if (mine[i][j] != '*' && !vis[i][j]) return false;
	return true;
}

void gao(int R, int C, int M) {
	int RR = R, CC = C, MM = M;

	int mine[55][55];
	REP(i, R) REP(j, C) mine[i][j] = '.';

	int ox = 0, oy = 0;
	while (R >= 1 && C >= 1 && M >= 1 && (R <= M || C <= M)) {
		if (R <= M && (C > M || R <= C)) {
			REP(i, R) mine[ox + i][oy] = '*';
			M -= R;
			oy += 1, C -= 1;
		} else {
			REP(j, C) mine[ox][oy + j] = '*';
			M -= C;
			ox += 1, R -= 1;
		}
	}

	// print(RR, CC, mine), OUT(M);

	if (R >= 2 && C >= 2) {
		REP(i, R - 2) REP(j, C - 2) {
			if (M > 0) {
				mine[ox + i][oy + j] = '*';
				--M;
			}
		}
	}

	int cx = RR - 1, cy = CC - 1;
	if (M > 0) {
		printf("Impossible\n");
		return;
	}

	if (mine[cx][cy] == '*') {
		printf("Impossible\n");
		return;
	}
	mine[cx][cy] = 'c';

	if (!valid(RR, CC, mine, cx, cy)) {
		printf("Impossible\n");
		return;
	}

	print(RR, CC, mine);
}

int main() {
	int T, R, C, M;
	scanf("%d", &T);
	REP(tid, T) {
		scanf("%d%d%d", &R, &C, &M);

		printf("Case #%d:\n", tid + 1);
		gao(R, C, M);
	}
	return 0;
}