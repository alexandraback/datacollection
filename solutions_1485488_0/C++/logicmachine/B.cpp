#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, pii> pdpii;

const double INF = 1e9;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

int floor[102][102];
int ceil[102][102];
double fastest[102][102];

int main(){
	cout << setiosflags(ios::fixed) << setprecision(10);
	int T;
	cin >> T;
	for(int caseNum = 1; caseNum <= T; ++caseNum){
		int H, N, M;
		cin >> H >> N >> M;
		memset(floor, 0, sizeof(floor));
		memset(ceil, 0, sizeof(ceil));
		for(int i = 0; i <= N + 1; ++i){
			for(int j = 0; j <= M + 1; ++j){ fastest[i][j] = INF; }
		}
		for(int i = 1; i <= N; ++i){
			for(int j = 1; j <= M; ++j){ cin >> ceil[i][j]; }
		}
		for(int i = 1; i <= N; ++i){
			for(int j = 1; j <= M; ++j){ cin >> floor[i][j]; }
		}
		priority_queue< pdpii, vector<pdpii>, greater<pdpii> > pq;
		pq.push(pdpii(0.0, pii(1, 1)));
		while(!pq.empty()){
			pdpii p = pq.top();
			pq.pop();
			int y = p.second.first, x = p.second.second;
			if(y == N && x == M){ break; }
			if(fastest[y][x] < p.first){ continue; }
			for(int i = 0; i < 4; ++i){
				int ny = y + dy[i], nx = x + dx[i];
				if(ceil[ny][nx] - floor[ny][nx] < 50){ continue; }
				if(ceil[ny][nx] - floor[y][x] < 50){ continue; }
				if(ceil[y][x] - floor[ny][nx] < 50){ continue; }
				int f = min(ceil[ny][nx], ceil[y][x]) - 50;
				double t = max(p.first, static_cast<double>(H - f) / 10.0);
				double level = H - t * 10;
				double next_fastest = 0.0;
				if(t == 0.0){
					next_fastest = 0.0;
				}else if(level - floor[y][x] >= 20){
					next_fastest = t + 1.0;
				}else{
					next_fastest = t + 10.0;
				}
				if(next_fastest < fastest[ny][nx]){
					fastest[ny][nx] = next_fastest;
					pq.push(pdpii(next_fastest, pii(ny, nx)));
				}
			}
		}
		cout << "Case #" << caseNum << ": " << fastest[N][M] << endl;
	}
	return 0;
}
