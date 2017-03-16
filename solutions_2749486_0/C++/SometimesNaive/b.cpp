#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

const int N = 1010;
const int O = 505;
int dis[N][N];
pair<int, int> pa[N][N];
char cmd[N][N];

int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
string op = "NSEW";

void solve(string& ans, int X, int Y)
{
	queue< pair<int, int> > q;
	q.push( pair<int, int>(O, O) );
	memset(dis, -1, sizeof(dis));
	dis[O][O] = 0;
	X += O, Y += O;
	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();

		int x = pos.first, y = pos.second;
		if (x == X && y == Y) break;
		int step = dis[x][y] + 1;
		//printf("%d, %d\n", x, y);
		for (int k = 0; k < 4; k++){
			int nx = x + step * d[k][0], ny = y + step * d[k][1];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && dis[nx][ny] == -1) {
				dis[nx][ny] = dis[x][y] + 1;
				pa[nx][ny] = pair<int, int>(x, y);
				cmd[nx][ny] = op[k];
				q.push(pair<int, int>(nx, ny));
			}
		}
	}
//	printf("aaaaaaaaa\n");
	ans = "";
	int x = X, y = Y;
	while (!(x == O && y == O)){
//		printf("%d, %d\n", x, y);
		ans += cmd[x][y];
		int px = pa[x][y].first;
		int py = pa[x][y].second;
		x = px, y = py;
	}
	reverse(ans.begin(), ans.end());
}

int main()
{
	int T, x, y;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		scanf("%d%d", &x, &y);
		string ans;
		solve(ans, x, y);
		printf("Case #%d: %s\n", cas, ans.c_str()); 
	}
	return 0;
}
