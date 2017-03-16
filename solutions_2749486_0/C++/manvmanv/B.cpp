#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define CY 1010
#define MX 1005

const int der[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct P {
	int r, c;
}pre[CY][CY];

struct re {
	int r, c, step;
}S, T;

int dis[CY][CY];
char rec[CY];

int bfs(re s, re t) {
	memset(dis, -1, sizeof(dis));
	memset(pre, -1, sizeof(pre));
	dis[s.r][s.c] = 0;
	queue<re>Q;
	Q.push(s);
	re u, v;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		int r = u.r;
		int c = u.c;
		int step = u.step;
		for (int k = 0; k < 4; ++k) {
			int dr = r + step * der[k][0];
			int dc = c + step * der[k][1];
			if (dr >= 0 && dr < MX && dc >= 0 && dc < MX && (dis[dr][dc] == -1 || dis[dr][dc] > dis[r][c] + 1)) {
				dis[dr][dc] = dis[r][c] + 1;
				pre[dr][dc].r = r;
				pre[dr][dc].c = c;
				if (dr == T.r && dc == T.c) return dis[dr][dc];
				v.r = dr; v.c = dc; v.step = step + 1;
				Q.push(v);
			}
		}
	}
	return -1;
}

void print(int r, int c) {
	int k = 0;
	while (~pre[r][c].r) {
		if (pre[r][c].r < r) rec[k++] = 'S';
		else if (pre[r][c].r > r) rec[k++] = 'N';
		else if (pre[r][c].c < c) rec[k++] = 'E';
		else rec[k++] = 'W';
		int tmp = r;
		r = pre[r][c].r;
		c = pre[tmp][c].c;
	}
	reverse(rec, rec + k);
	for (int i = 0; i < k; ++i) {
		putchar(rec[i]);
	}
	puts("");
}

int main(void) {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	S.r = 501; S.c = 501; S.step = 1;
	for (int Cas = 1; Cas <= cas; ++Cas) {
		scanf("%d%d", &T.c, &T.r);
		T.r *= -1;
	//	T.r--; T.c--;
		T.r += 501; T.c += 501;
		int ans = bfs(S, T);
		//test
//		cout << ans << endl;
		//end
		printf("Case #%d: ", Cas);
		print(T.r, T.c);
	}
	return 0;
}
