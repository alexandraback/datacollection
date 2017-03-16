#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> ii;
int tcs, x, y, ans, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char d[] = {'W', 'S', 'E', 'N'};
const int ix = 101, iy = 101;
int map[205][205];
char steps[205][205][50];
bool visited[205][205];
queue<ii> q;
int main(){
	scanf("%i", &tcs);
	map[ix][iy] = 1;
	visited[ix][iy] = 1;
	q.push(ii(ix, iy));
	while(!q.empty()){
		ii cp = q.front();
		int cx = cp.first, cy = cp.second;
		q.pop();
		for(int cd=0;cd<4;cd++){
			int nx = cx + map[cx][cy] * dx[cd], ny = cy + map[cx][cy] * dy[cd];
			if(visited[nx][ny] || nx < 0 || nx >= 205 || ny < 0 || ny >= 205) continue;
			map[nx][ny] = map[cx][cy] + 1;
			memcpy(steps[nx][ny], steps[cx][cy], sizeof steps[cx][cy]);
			steps[nx][ny][map[cx][cy] - 1] = d[cd];
			visited[nx][ny] = 1;
			q.push(ii(nx, ny));
		}
	}
	for(int tc=1;tc<=tcs;tc++){
		scanf("%i%i", &x, &y);
		x += ix;
		y += iy;
		printf("Case #%i: %s\n", tc, steps[x][y]);
	}
}