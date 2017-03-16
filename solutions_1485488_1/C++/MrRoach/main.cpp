#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <queue>

using namespace std;
const int MAXN = 120;
const int INFTY = 100000000;
const double EPS = 1e-6;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

struct node {
	bool friend operator < (const node &a, const node &b){
		return (a.t > b.t);
	}
	int y;
	int x;
	int t;
};



int T;
int H,N,M;
int f[MAXN][MAXN];
int c[MAXN][MAXN];
int t[MAXN][MAXN];
bool det[MAXN][MAXN];

priority_queue<node, vector<node>, less<node>> q;


int earliest_time(int y1, int x1, int y2, int x2){
	if (c[y1][x1] - f[y1][x1] < 50) return INFTY;
	if (c[y2][x2] - f[y2][x2] < 50) return INFTY;
	if (c[y1][x1] - f[y2][x2] < 50) return INFTY;
	if (c[y2][x2] - f[y1][x1] < 50) return INFTY;
	int t = H - (c[y1][x1] - 50);
	if (t < H - (c[y2][x2] - 50)) {
		t = H - (c[y2][x2] - 50);
	}
	if (t < 0) t = 0;
	return t;
}

int travel_cost(int y, int x, int t){
	if (t == 0) return 0;
	if (H-t-f[y][x] >= 20) return 10;
	else return 100;
}

int main(){
	cin >>T;
	for (int times = 0; times < T; ++times){
		cin >> H >> N >> M;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < M; ++j){
				cin >> c[i][j];
				t[i][j] = INFTY;
			}
		}
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < M; ++j){
				cin >> f[i][j];
			}
		}
		memset(det, false, sizeof(det));
		while (!q.empty()) q.pop();

		t[0][0] = 0;
		node n;
		n.y = 0;
		n.x = 0;
		n.t = 0;
		q.push(n);

		while (!q.empty()){
			node n = q.top();
			q.pop();
			int y = n.y;
			int x = n.x;
			if (det[y][x]) continue;
			det[y][x] = true;
			if (det[N-1][M-1]) break;
			
			for (int i = 0; i < 4; ++i){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= 0 && nx >= 0 && ny < N && nx < M && !det[ny][nx]){
					int nt = earliest_time(y, x, ny,nx);
					if (nt < n.t) nt = n.t;
					nt += travel_cost(y, x, nt);
					if (nt < t[ny][nx]){
						t[ny][nx] = nt;
						node nn;
						nn.x = nx;
						nn.y = ny;
						nn.t = nt;
						q.push(nn);
					}
				}
			}
		}
		cout <<"Case #" << times + 1 <<": "<<t[N-1][M-1]/10.0<<endl;
	}
	return 0;
}