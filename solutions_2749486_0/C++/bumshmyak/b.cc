#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

const int LIM = 2000;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
string ds = "EWNS";

char p[2 * LIM][2 * LIM];

struct State {
	int x;
	int y;
	int k;

	State(int _x = 0, int _y = 0, int _k = 0) :
		x(_x),
		y(_y),
		k(_k)
	{ }
};

int main() {
	int n_tests;
	cin >> n_tests;

	for (int test = 0; test < n_tests; ++test) {
		int n, m;
		int x, y;
		cin >> x >> y;
		x += LIM;
		y += LIM;

		queue<State> q;
		q.push(State(LIM, LIM, 1));
		memset(p, 0, sizeof(p));
		p[LIM][LIM] = -1;

		while (!q.empty()) {
			State u = q.front();
			q.pop();
			if (u.x == x && u.y == y) {
				string res;
				int k = u.k;
				while (k > 0) {
					int j = p[u.x][u.y] - 1;
					u.x -= k * dx[j];
					u.y -= k * dy[j];
					res += ds[j];
					--k;
				}
				reverse(res.begin(), res.end());
				cout << "Case #" << test + 1 << ": " << res << endl;
			}
			for (int i = 0; i < 4; ++i) {
				int xn = u.x + u.k * dx[i];
				int yn = u.y + u.k * dy[i];
				if (xn >= 0 && xn < 2 * LIM && yn >= 0 && yn < 2 * LIM && p[xn][yn] == 0) {
					p[xn][yn] = i + 1;
					q.push(State(xn, yn, u.k + 1));
				}
			}
		}
	}

	return 0;
}
