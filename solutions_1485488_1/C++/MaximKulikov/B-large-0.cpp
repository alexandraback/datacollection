#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;
typedef stringstream ss;

#define sz(v)		((int) v.size())
#define fv(v, i)	for (int i = 0; i < sz(v); ++i)
#define fn(n, i)	for (int i = 0; i < n; ++i)

#define FILENAME	"B-large-0"

int N, H, M, C[128][128], F[128][128], enter[128][128];

class Position {
public:
	int t, x, y;
	Position(int _t, int _x, int _y) : t(_t), x(_x), y(_y) {}
	bool operator <(const Position& other) const {
		return t > other.t;
	}
};

int dx[] = {0, -1, 1, 0},
	dy[] = {-1, 0, 0, 1};

int main() {
	ifstream in(FILENAME ".in");
	ofstream out(FILENAME ".out");

	int T;
	in >> T;
	for (int test = 1; test <= T; ++test) {

		in >> H >> N >> M;
		fn(N, i) {
			fn(M, j) {
				in >> C[i][j];
				C[i][j];
			}
		}
		fn(N, i) {
			fn(M, j) {
				in >> F[i][j];
				F[i][j];
			}
		}

		priority_queue<Position> q;
		memset(enter, 0x3f, sizeof(enter));
		int inf = 0x3f3f3f3f, wait;
		q.push(Position(0, 0, 0));
		while(enter[N-1][M-1] == inf) {
			Position cur = q.top(); q.pop();
			if (cur.t > enter[cur.x][cur.y]) continue;
			int x, y, t;
			fn(4, k) {
				x = cur.x + dx[k];
				y = cur.y + dy[k];
				if (x < 0 || y < 0 || x >= N || y >= M ||
					min(C[x][y], C[cur.x][cur.y])-max(F[x][y], F[cur.x][cur.y]) < 50) continue;
				wait = max(0, H - cur.t - C[x][y] + 50);
				t = cur.t + wait;
				if (t > 0) {
					t += (H - t - F[cur.x][cur.y]) >= 20 ? 10 : 100;
				}
				if (t < enter[x][y]) {
					enter[x][y] = t;
					q.push(Position(t, x, y));
				}
			}
		}

		out << "Case #" << test << ": ";
		out << (enter[N-1][M-1] / 10) << '.' << (enter[N-1][M-1] % 10);
		out << endl;
	}

	return 0;
}