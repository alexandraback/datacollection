#include <cstdio>
#include <queue>
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define MP make_pair
#define VALID(x, y) (x >= 0 && x < n && y >= 0 && y < m)
int h, m, n;
int C[128][128], F[128][128];
int t[128][128];

int can_move(int x, int y, int nx, int ny, int tm){
	if(C[nx][ny] < F[x][y] + 50) return -1;
	if(C[x][y] < F[nx][ny] + 50) return -1;
	if(C[nx][ny] < F[nx][ny] + 50) return -1;
	//printf("[%d] (%d, %d, %d, %d) to (%d, %d, %d, %d)\n", h - tm, x, y, F[x][y], C[x][y], nx, ny, F[nx][ny], C[nx][ny]);	
	return max(h - tm + 50 - C[nx][ny], 0);
}
void dfs(int x, int y, queue< pair<int, int> >& q){
	t[x][y] = 0;
	//printf("B (%d, %d)\n", x, y);
	q.push(MP(y | (x << 8), t[x][y] = 0));
	FOR(dir, 4){
		int nx = x + dx[dir], ny = y + dy[dir];
		if(!VALID(nx, ny)) continue;
		if(t[nx][ny] && can_move(x, y, nx, ny, 0) == 0) dfs(nx, ny, q);
	}
}
int main(void){
	int T; scanf("%d", &T);
	for(int cn = 0; cn++ < T; ){
		printf("Case #%d: ", cn);
		scanf("%d %d %d", &h, &n, &m);
		FOR(i, n) FOR(j, m) scanf("%d", &C[i][j]);
		FOR(i, n) FOR(j, m) scanf("%d", &F[i][j]);
		FOR(i, n) FOR(j, m) t[i][j] = 1 << 30;
		queue< pair<int, int> > q;
		dfs(0, 0, q);
		//printf("DFS IS OVER\n");
		while(!q.empty() && t[n - 1][m - 1] == 1 << 30){
			int qf = q.front().first, tm = q.front().second;
			int x = qf >> 8, y = qf & 0xFF;
			q.pop();
			if(tm > t[x][y]) continue;
			//printf("Reached (%d, %d) in %d\n", x, y, tm);
			FOR(dir, 4){
				int mvt, nx = x + dx[dir], ny = y + dy[dir];
				if(!VALID(nx, ny)) continue;
				if((mvt = can_move(x, y, nx, ny, tm)) != -1){
					//printf("\tMvt from (%d, %d) to (%d, %d) -> %d\n", x, y, nx, ny, mvt);
					int water_level = max(h - (tm + mvt), F[x][y]);
					int arrival_time = tm + mvt + 10;
					if(water_level < F[x][y] + 20) arrival_time += 90;
					if(arrival_time < t[nx][ny]){
						//printf("\tFrom (%d, %d) to (%d, %d) wait %d, move %d\n", x, y, nx, ny, mvt, arrival_time - (tm + mvt));
						t[nx][ny] = arrival_time;
						q.push(MP(ny | (nx << 8), arrival_time));
					}
				}
			}
		}
		printf("%d.%d\n", t[n - 1][m - 1] / 10, t[n - 1][m - 1] % 10);
	}
	return 0;
}
