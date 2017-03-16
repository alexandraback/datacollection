/*

W: water
F: floor
C: ceil

W, Fc, Fa <= Ca - 50
Fa <= Cc - 50

W + 20 <= Fc => 1s
Fc < W + 20 => 10sec

*/
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define PN 4
int _p[PN], _q, _r;
// main に入った直後に呼ぶ
void pinit() { signal(SIGCHLD, SIG_IGN); }
// 子プロセスの出力直前と親プロセスの終了直前に呼ぶ
void pblock(int p = _p[_q]) { while (p && !kill(p, 0)) usleep(1e4L); }
// 親プロセスの入力直後に呼ぶ
int pfork() {
	_r = (_q + 1) % PN; pblock(_p[_r]);
	if (_p[_r] = fork()) return _q = _r, 1; return 0;
}
// 子プロセスの終了を行う
void pexit() { fflush(stdout); exit(0); }

/// 以下サンプル
int H, W;
int S;
int F[128][128], C[128][128];

int input() {
	scanf("%d%d%d", &S, &H, &W);
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			scanf("%d", &C[y][x]);
		}
	}
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			scanf("%d", &F[y][x]);
		}
	}
	return 1;
}

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int solve(int case_x) {
	// Program to solve
	int state[H][W];
	int ans = -1;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			state[y][x] = -10000000;
		}
	}
	state[0][0] = S;
	for (int s = S; -500000 < s; s--) {
		/*
		printf("-----%d(%d)-----\n", S - s, s);
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				printf("% 4d", state[y][x]);
			}
			puts("");
		}
		//*/
		int change = 0;
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				if (state[y][x] < s) continue;
				int water = s, f_cur = F[y][x], c_cur = C[y][x];
				for (int d = 0; d < 9; d++) {
					int xx = x + dx[d], yy = y + dy[d];
					if (yy < 0 || H <= yy || xx < 0 || W <= xx) continue;
					int f_adj = F[yy][xx], c_adj = C[yy][xx];
					if (water <= c_adj - 50 &&
					    f_cur <= c_adj - 50 &&
					    f_adj <= c_adj - 50 &&
					    f_adj <= c_cur - 50) {
						int motion = 100;
						if (f_cur + 20 <= water) {
							// 1 sec
							motion = 10;
						}
						if (S == s) motion = 0;
						if (state[yy][xx] == -10000000) {
							state[yy][xx] = s - motion;
							change = 1;
						} else {
							//printf("d.%d,%d\n", state[yy][xx], s - motion);
							if (state[yy][xx] < s - motion) change = 1;
							state[yy][xx] = max(state[yy][xx], s - motion);
						}
					}
				}
			}
		}
		if (state[H - 1][W - 1] == s) {
			ans = S - s;
			break;
		}
		if (s == S && change) s++;
	}
	// Block before writing
	pblock();
	if (ans < 0) {
		printf("Case #%d: IMPOSSIBLE\n", case_x);
	} else {
		printf("Case #%d: %.1f\n", case_x, ans / 10.0);
	}
}

int main() {
	pinit();
	int T;
	scanf("%d", &T);
	for (int case_x = 1; case_x <= T; case_x++) {
		input();
		if (pfork()) continue;
		solve(case_x);
		pexit();
	}
	pblock();
	return 0;
}
