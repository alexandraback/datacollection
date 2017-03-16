#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int max(int a, int b, int c) {
	return max(max(a, b), c);
}

int W, N, M;
int h[200][200];
int f[200][200];
int wh[200][200];
bool vis[200][200];
struct qe{
	int w, x, y;
	qe(int w, int x, int y) : w(w), x(x), y(y) {}
	const bool operator<(const qe& o) const {
		return w < o.w;
	}
};

priority_queue<qe> q;

int dir[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
void dfs(int x, int y) {
	vis[x][y] = true;
	//printf("dfs %d %d\n", x, y);
	wh[x][y] = W;
	q.push(qe(W, x, y));
	for(int i=0; i<4; i++) {
		int wx = x + dir[i][0];
		int wy = y + dir[i][1];
		if(wx >= 0 and wx < M and wy>=0 and wy<N) {
			if(!vis[wx][wy]) if(max(W, f[x][y], f[wx][wy]) + 50 <= h[wx][wy] and h[x][y] >= f[wx][wy] + 50)
				dfs(wx, wy);
		}
	}
}

void update(int w, int x, int y) {
	if(w > wh[x][y]) {
		wh[x][y]=w;
		q.push(qe(w, x, y));
	}
}
int solve() {
	for(int x=0; x<M; x++) for(int y=0; y<N; y++) {
		vis[x][y] = false;
		wh[x][y] = -1<<30;
	}
	while(!q.empty()) q.pop();
	dfs(0,0);
	while(!vis[M-1][N-1]) {
		qe c = q.top();
		q.pop();
		int x = c.x, y = c.y, w = c.w;
		//printf("%d %d %d\n", w, x, y);
		vis[x][y] = true;
		wh[x][y] = w;
		
		for(int i=0; i<4; i++) {
			int wx = x + dir[i][0];
			int wy = y + dir[i][1];
			
			if(wx >= 0 and wx < M and wy>=0 and wy<N) {
					if(max(w, f[x][y], f[wx][wy]) + 50 <= h[wx][wy] and h[x][y] >= f[wx][wy] + 50) {
						if(w >= f[x][y] + 20) update(w-10, wx, wy);
						else update(w-100, wx, wy);
					} else if(max(f[x][y], f[wx][wy]) + 50 <= h[wx][wy] and h[x][y] >= f[wx][wy] + 50) {
					
						int nw = h[wx][wy] - 50; //warte auf nw
						//printf("nw %d\n", nw);
						if(nw >= f[x][y] + 20) {
							
							update(nw-10, wx, wy);
						}
						else update(nw-100, wx, wy);
					}
			}
		}
		
	}
	return W-wh[M-1][N-1];
}
int main() {
	//freopen("C.in", "r", stdin);
	int T;
	scanf("%d\n", &T);
	for(int t=1; t<=T; t++) {
		scanf("%d %d %d", &W, &N, &M);
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++)
				scanf("%d", &h[j][i]);
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++)
				scanf("%d", &f[j][i]);
		}
		printf("Case #%d: %f\n", t, (double)(solve())/10.);
		
	}
}
