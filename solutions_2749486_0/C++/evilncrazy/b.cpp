#include <cstdio>
#include <algorithm>
#include <queue>

int fromx[1005][1005], fromy[1005][1005], from[1005][1005];
int dist[1005][1005];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

char dirs[4] = {'N','S','E','W'};

struct Coord {
	int x, y, dist;
	Coord(int xx, int yy, int d) : x(xx), y(yy), dist(d) { }
	bool operator < (const Coord &c) const { return dist > c.dist; }
};

void printResult(int x, int y) {
	if (x == 500 && y == 500) return;
	
	printResult(fromx[x][y], fromy[x][y]);

	printf("%c", dirs[from[x][y]]);
}

void find(int x, int y) {
	std::priority_queue<Coord> q;
	q.push(Coord(500, 500, 0));
	dist[500][500] = 0;

	while (!q.empty()) {
		Coord top = q.top();
		q.pop();

		if (top.dist == dist[top.x][top.y]) {
			if (x == top.x && y == top.y) {	
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nx = dx[i] * (top.dist + 1) + top.x, ny = dy[i] * (top.dist + 1) + top.y;
				if (nx >= 0 && nx <= 1000 && ny >= 0 && ny <= 1000) {
					if (top.dist + 1 < dist[nx][ny]) {
						from[nx][ny] = i; fromx[nx][ny] = top.x; fromy[nx][ny] = top.y;
						dist[nx][ny] = top.dist + 1;
						q.push(Coord(nx, ny, top.dist + 1));
					}
				}
			}
		}
	}
}

void solve(int cs) {
	for (int x = 0; x < 1000; x++) {
		for (int y = 0; y < 1000; y++) {
			fromx[x][y] = fromy[x][y] = from[x][y] = -1;
			dist[x][y] = 5000;
		}
	}

	int x, y; scanf("%d %d", &x, &y);

	find(x + 500, y + 500);

	printf("Case #%d: ", cs);
	printResult(x + 500, y + 500);
	printf("\n");
}

int main() {
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++)
		solve(i);
}