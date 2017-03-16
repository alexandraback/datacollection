#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

struct Node {
	int r,c;
	double t;
	bool operator<(const Node &that) const {
		return t > that.t;
	}
};

int T,H,R,C,hi[101][101],lo[101][101];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
priority_queue<Node> pq;

bool can_move(int r1, int c1, int r2, int c2, double t){
	// You can never move off the edge of the map.
	if (r2<0 || r2>=R || c2<0 || c2>=C) return false;

	// The water level, the floor height of your current square, 
	// and the floor height of the adjacent square 
	// must all be at least 50 centimeters lower than 
	// the ceiling height of the adjacent square.
	// Water level will drop at a constant rate of 10 centimeters per second, down to zero. 
	if (max(H - t*10, (double)max(lo[r1][c1], lo[r2][c2])) > hi[r2][c2] - 50) return false;
	
	// The floor height of the adjacent square must be at least 50 centimeters 
	// below the ceiling height of your current square as well.
	if (lo[r2][c2] > hi[r1][c1] - 50) return false;

	return true;
}

double next_move(int r1, int c1, int r2, int c2, double t){
	if (r2<0 || r2>=R || c2<0 || c2>=C) return -1;
	if (max(lo[r1][c1], lo[r2][c2]) > hi[r2][c2] - 50) return -1;
	if (lo[r2][c2] > hi[r1][c1] - 50) return -1;
	double d = (H - t*10) - (hi[r2][c2] - 50);
//	printf("%d %d, %d %d, %lf %lf, %d - %d, %d - %d, %lf, %d\n",
//		r1,c1,r2,c2,t,d, lo[r1][c1],hi[r1][c1], lo[r2][c2],hi[r2][c2], H-t*10,
//		can_move(r1,c1,r2,c2,t));
	assert(d>0);
	return t + d / 10.0;
}

int vis[101][101];
void enqueue_start_points(int r, int c){
	if (vis[r][c]) return;
	vis[r][c] = 1;
	pq.push((Node){r,c,0});
	//printf("start> %d %d\n",r,c);
	REP(i,4){
		int nr = r+dr[i], nc = c+dc[i];
		if (!can_move(r,c,nr,nc,0)) continue;
		enqueue_start_points(nr,nc);
	}
}

double dp[101][101];

double dijkstra(){
	while (pq.size()) pq.pop();
	memset(vis,0,sizeof(vis));
	enqueue_start_points(0,0);
	REP(i,R) REP(j,C) dp[i][j] = 1e100;
	while (pq.size()){
		Node u = pq.top(); pq.pop();
		if (u.r == R-1 && u.c == C-1) return u.t;
		if (dp[u.r][u.c] + 1e-9 < u.t) continue;
		REP(i,4){
			int nr = u.r + dr[i], nc = u.c + dc[i];
			double nt = -1;
			if (!can_move(u.r,u.c,nr,nc,u.t)){
				nt = next_move(u.r,u.c,nr,nc,u.t);
				if (nt < -0.5) continue;
			} else nt = u.t;

			if (H - nt*10 >= lo[u.r][u.c] + 20){
				// if there are at least 20 centimeters of water remaining on the current square 
				// when you start moving from it, it takes 1 second to complete the move 
				if (dp[nr][nc] - 1e-9 > nt+1){
					pq.push((Node){ nr,nc,nt+1 });
					dp[nr][nc] = nt+1;
				}
			} else {
				// Otherwise, it takes 10 seconds (you have to drag your kayak). 
				if (dp[nr][nc] - 1e-9 > nt+10){
					pq.push((Node){ nr,nc,nt+10 });
					dp[nr][nc] = nt+10;
				}
			}
		}
	}
	assert(false);
}

int main(){
	scanf("%d",&T);
	for (int tc=1; T--; tc++){
		scanf("%d %d %d",&H,&R,&C);
		REP(i,R) REP(j,C) scanf("%d",&hi[i][j]);
		REP(i,R) REP(j,C) scanf("%d",&lo[i][j]);
		double res = dijkstra();
		printf("Case #%d: %.9lf\n",tc,res);
		//fprintf(stderr,"Case #%d: %.9lf\n",tc,res);
	}
}
