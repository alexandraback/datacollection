#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int x;
	int y;
	double cost;

	bool operator < (const Node & b) const {
		return cost > b.cost;
	}
};

int n, m;
double H;


double fl[500][500];
double cl[500][500];
double res[500][500];

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; 

double search() {
			for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = 1000000000;

	Node start = {0, 0, 0.0};
	priority_queue<Node> q;
	res[0][0] = 0;

	q.push(start);

	while (!q.empty()) {
		Node cur = q.top(); q.pop();
		int x = cur.x;
		int y = cur.y;
		double c = cur.cost;

		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dir[d][0];
			int ny = cur.y + dir[d][1];
			double nc;

			//if (used[nx][ny]) continue;
			if (nx < 0 || nx >= n) continue;
			if (ny < 0 || ny >= m) continue;
			if (cl[nx][ny] - fl[nx][ny] < 50) continue;
			if (cl[nx][ny] - fl[x][y] < 50) continue;
			if (cl[x][y] - fl[nx][ny] < 50) continue;


			double level = H - (10.0 * c);

		//	double top = cl[x][y];
			//double down = max(fl[x][y], level);

			//double ntop = 
		//	double down = max(fl[nx][ny], level);

		if (cl[nx][ny] - level < 50) {
				double nlevel = (cl[nx][ny] - 50);
				double wait = ((double)level - nlevel) / 10.0;
				nc = c + wait;

				if (nlevel - fl[x][y] >= 20)
					nc += 1;
				else 
					nc += 10;
			} else if (c == 0) {
				nc = 0;
			} else if (level - fl[x][y] >= 20) {
				nc = c + 1;
			} else {
				nc = c + 10;
			}

			if (nc < res[nx][ny]) {
				res[nx][ny] = nc;
				q.push((Node){nx, ny, nc});
			}
		}
	}

	return res[n-1][m-1];
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%lf%d%d", &H, &n, &m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%lf", &cl[i][j]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%lf", &fl[i][j]);

		printf("Case #%d: %f", k+1, search());
		if (k<t-1) printf("\n");	
	}
	return 0;
}