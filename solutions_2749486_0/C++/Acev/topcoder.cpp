#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <iostream>
#include <cfloat>
#include <ctime>
#include <sstream>
using namespace std;
#define all(a) a.begin(),a.end()
#define mset(a, v) memset(a, v, sizeof(a));
typedef long long ll;

int dir[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
char dirStr[5] = "NSEW";

int board[1024][1024];
int way[1024][1024];

int offset = 512;

struct State {
	int c, nextLeap;
	pair<int, int> pos;
	bool operator < (const State& s) const {
		return this->c > s.c;
	}
};

void solve(int x, int y) {
	priority_queue<State> q;
	pair<int, int> curr(offset, offset);
	board[offset][offset] = 0;
	State s;
	s.c = 0;
	s.nextLeap = 1;
	s.pos = curr;
	q.push(s);
	while (!q.empty()) {
		s = q.top();
		q.pop();
		curr = s.pos;
		if (curr == make_pair(x, y)) {
			return;
		}

		for (int i = 0; i < 4; ++i) {
			pair<int, int> next(curr.first + s.nextLeap * dir[0][i], curr.second + s.nextLeap * dir[1][i]);
			if (next.first < 0 || next.first >= 1024 || next.second < 0 || next.second >= 1024) {
				continue;
			}

			if (board[next.first][next.second] != -1) {
				continue;
			}

			State ns(s);
			ns.nextLeap++;
			ns.pos = next;
			ns.c = 1 + s.c;
			board[next.first][next.second] = ns.c;
			way[next.first][next.second] = i;

			q.push(ns);
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		mset(board, -1);
		int x, y;
		cin >> x >> y;
		x += offset;
		y += offset;

		solve(x, y);

		pair<int, int> curr(x, y);
		string ans;
		while (curr.first != offset || curr.second != offset) {
			int td = way[curr.first][curr.second];
			ans.push_back(dirStr[td]);
			int l = board[curr.first][curr.second];
			curr.first -= l * dir[0][td];
			curr.second -= l * dir[1][td];
		}
		reverse(all(ans));
		cout << ans << endl;
	}

	return 0;
}
