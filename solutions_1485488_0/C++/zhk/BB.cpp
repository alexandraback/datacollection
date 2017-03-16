#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <iostream>
using namespace std;

FILE* fin = stdin;
FILE* fout = stdout;

void solve(int);
int main() {
	int  T, it=1;
	scanf("%d", &T);
	for(; it<=T; ++it) {
		solve(it);
	}
	return 0;
}

const int NN = 128;

int  H, N, M; double cur_time;
int  F[NN][NN], C[NN][NN], WH[NN][NN];
int  Q[NN*NN*8], Qs, Qe;
bool vst[NN][NN];
double ct[NN][NN];

#define CODE(x,y) (((x)<<10) | (y))
#define GETX(s)   ((s)>>10)
#define GETY(s)   ((s)&127)
int  dx[] = {1, -1, 0, 0};
int  dy[] = {0, 0, -1, 1};

bool can(int wh, int fh, int nfh, int nch) {
	return wh+50<=nch && fh+50<=nch && nfh+50<=nch;
}
bool cmp(const int&a, const int& b) {
	return ct[GETX(a)][GETY(a)] < ct[GETX(b)][GETY(b)];
}

double get_next_time() {
	double ans = 1e30;
	double cur_WH = H - cur_time*10;
	for(int i=0; i<Qe; ++i) {
		int  sx = GETX(Q[i]);
		int  sy = GETY(Q[i]);
		// int  gt = 1;
		// if(H-cur_time*10 >= F[sx][sy]+20) gt=1;
		// else gt=10;
		// gt += ct[sx][sy];
		for(int k=0; k<4; ++k) {
			int nx = sx+dx[k];
			int ny = sy+dy[k];
			if( nx<0 || ny < 0 || nx>=N || ny>=M || vst[nx][ny]) {
				continue;
			}
			if(C[sx][sy] < F[nx][ny]+50) continue;
			if(F[sx][sy]+50 > C[nx][ny] || F[nx][ny]+50 > C[nx][ny] || WH[nx][ny]+1e-10 >= cur_WH) continue;
			ans = min(ans, (H - WH[nx][ny]) / 10.0);
		}
	} return ans;
}

void go(bool first = false) {
	sort(Q, Q+Qe, cmp);
	for(int i=0; i<Qe; ++i) {
		int  sx = GETX(Q[i]);
		int  sy = GETY(Q[i]);
		double  gt = 1, cct = max(cur_time, ct[sx][sy]);
		if((first ? H : H-cct*10) >= F[sx][sy]+20) gt=1;
		else gt=10;
		gt += cct;
		for(int k=0; k<4; ++k) {
			int nx = sx+dx[k];
			int ny = sy+dy[k];
			if( nx<0 || ny < 0 || nx>=N || ny>=M || ct[nx][ny]<=gt) {
				continue;
			}
			if(C[sx][sy] < F[nx][ny]+50) continue;
		    if(can(first ? H : H-cct*10, F[sx][sy], F[nx][ny], C[nx][ny])) {
				// continue;
				ct[nx][ny] = gt;
				if(vst[nx][ny]) continue;
				vst[nx][ny] = true;
				Q[Qe++] = CODE(nx, ny);
			}
		}
	}
}

void solve(int case_idx) {
	scanf("%d%d%d", &H, &N, &M);
	memset(vst, 0, sizeof(vst));
	// Qs = Qe = 0;
	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			scanf("%d", C[i]+j);
			WH[i][j] = C[i][j] - 50;
		}
	}
	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j)
			scanf("%d", F[i]+j);
	}
	memset(ct, 0, sizeof(ct));
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) ct[i][j] = 1e30;
	ct[0][0] = 0;
	Qs = Qe = 0;
	Q[Qe++] = CODE(0,0); vst[0][0] = true;
	cur_time = 0;
	go(true);
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) if(vst[i][j]) ct[i][j] = 0;
	for(cur_time=0; !vst[N-1][M-1];) {
		cur_time = get_next_time();
		// printf("cur_time = %.12f\n", cur_time);
		go();
	}
	printf("Case #%d: %.12f\n", case_idx, ct[N-1][M-1]);
}
