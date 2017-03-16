#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define SZ(x) ((int)(x).size())
#define ALL(v) (v).begin() , (v).end()
#define CLR(v) memset(v, 0, sizeof(v));

#define MAX 110
using namespace std;

struct St {
	double t, wt;
	int x, y;
};

struct cmp {
	bool operator()(const St a, const St b) {
		return (a.t)>(b.t);
	}
};


priority_queue<St, vector<St>, cmp> qu;
int cei[MAX][MAX], flo[MAX][MAX], t, h, n, m;
bool vis[MAX][MAX];
int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};

bool valid(int x, int y) {
	if (0 <= x && x < m && 0 <= y && y < n)
		return true;
	return false;
}

bool can(int x, int y, int nx, int ny) {
	if (cei[ny][nx] - flo[y][x] < 50)
		return false;
	if (cei[ny][nx] - flo[ny][nx] < 50)
		return false;
	if (cei[y][x] - flo[ny][nx] < 50)
		return false;
	return true;
}

int calcwt(int x, int y, int nx, int ny, int wt) {
	if ((double)cei[ny][nx] - wt >= 50)
		return wt;
	return wt - (50 - ((double)cei[ny][nx]-wt));
}

void bfs() {
	St tmp, tmp2;
	tmp.x = tmp.y = 0;
	tmp.wt = h;
	tmp.t = 0;
	
	double owt = h;
	
	while(!qu.empty()) qu.pop();
	CLR(vis);
	qu.push(tmp);
	
	while (true) {
		tmp = qu.top();
		qu.pop();
		vis[tmp.y][tmp.x] = true;
		
		if (tmp.y == n-1 && tmp.x == m-1) {
			printf("%.8lg\n", tmp.t);
			return;
		}
//		printf("X = %d || Y = %d || t = %lg\n", tmp.x, tmp.y, tmp.t);
		
		FOR(i,0,4) {
			int nx = tmp.x+dx[i], ny = tmp.y+dy[i];
			if (valid(nx,ny) && !vis[ny][nx] && can(tmp.x,tmp.y,nx,ny)) {	
				double nwt = calcwt(tmp.x,tmp.y,nx,ny,tmp.wt);
			//	printf("Test %d %d || wt = %lg || nwt = %lg\n", nx, ny, tmp.wt, nwt);
				tmp2.x = nx, tmp2.y = ny;
				tmp2.t = tmp.t + ((double)(tmp.wt-nwt))/10.0;
				
				if (owt == nwt) tmp2.t += 0;
				else if (nwt-(double)flo[tmp.y][tmp.x] >= 20)
					tmp2.t += 1;
				else tmp2.t += 10;
				tmp2.wt = max(tmp.wt - 10*(tmp2.t-tmp.t),1.0);
				qu.push(tmp2);
			}
		}
	}
}

int main() {
	scanf("%d", &t);
	FOR(i,0,t) {
		printf("Case #%d: ", i+1);
		scanf("%d %d %d", &h, &n, &m);
		FOR(j,0,n) FOR(k,0,m) scanf("%d", &cei[j][k]);
		FOR(j,0,n) FOR(k,0,m) scanf("%d", &flo[j][k]);
		bfs(); //puts("");
	}
	return 0;
}