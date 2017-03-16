#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <queue>
using namespace std;
#define MN 155
int d[MN*2][MN*2][MN*2];
const int W = MN;
int X, Y;
int px[4] = {1,-1,0,0};
int py[4] = {0,0,1,-1};
char C[4] = {'E','W','N','S'};
char S[505];
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int K = 1; K <= T; K++) {
		memset(d, -1, sizeof(d));
		scanf("%d%d",&X,&Y);
		X += W; Y += W;
		queue <int> qx, qy, qc;
		while (!qx.empty()) qx.pop();
		while (!qy.empty()) qy.pop();
		while (!qc.empty()) qc.pop();
		qx.push(W); qy.push(W); qc.push(0);
		int nx, ny, nc, nxtx, nxty, dir, Len;
		bool sw = 0;
		while (!qx.empty()) {
			nx = qx.front(); qx.pop();
			ny = qy.front(); qy.pop();
			nc = qc.front(); qc.pop();
			nc++;
			for (int i = 0; i < 4; i++) {
				nxtx = nx+nc*px[i];
				nxty = ny+nc*py[i];
				if (0<=nxtx && nxtx<2*MN && 0<=nxty && nxty<2*MN) {
					if (d[nxtx][nxty][nc] == -1) {
						d[nxtx][nxty][nc] = i;
						if (nxtx == X && nxty == Y) {
							dir = i;
							Len = nc;
							sw = 1;
							break;
						}
						qx.push(nxtx);
						qy.push(nxty);
						qc.push(nc);
					}
				}
			}
			if (sw) break;
		}
		int m = 1, tx, ty;
		while (Len) {
			S[m] = C[dir];
			tx = X+Len*(px[dir])*(-1);
			ty = Y+Len*(py[dir])*(-1);
			X = tx, Y = ty;
			dir = d[X][Y][Len-1];
			Len--;
			m++;
		}
		reverse(S+1, S+m);
		S[m] = NULL;
		printf("Case #%d: %s\n",K,S+1);
	}
	fcloseall();
	return 0;
}