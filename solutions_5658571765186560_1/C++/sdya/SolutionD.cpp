#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 25;
int a[maxN][maxN];
int n, m, p;
int cnt[maxN * maxN];

struct Nmino {
	vector < string > s;
	void normalize() {
		int rx = 0, lx = s.size() - 1;
		int ry = 0, ly = s[0].size() - 1;
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; j < s[i].size(); ++j) {
				if (s[i][j] == 'X') {
					lx = min(lx, i);
					rx = max(rx, i);
					ly = min(ly, j);
					ry = max(ry, j);
				}
			}
		}

		vector < string > t(rx - lx + 1, string(ry - ly + 1, ' '));
		for (int i = lx; i <= rx; ++i) {
			for (int j = ly; j <= ry; ++j) {
				t[i - lx][j - ly] = s[i][j];
			}
		}
		s = t;
	}

	void rotate() {
		int n = s.size();
		int m = s[0].size();

		if (n < m) {
			for (int i = 0; i < m - n; ++i) {
				s.push_back(string(m, ' '));
			}
		} else {
			for (int i = 0; i < n; ++i) {
				s[i] += string(n - m, ' ');
			}
		}

		n = s.size();
		vector < string > t(n, string(n, ' '));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				t[n - 1 - j][i] = s[i][j];
			}
		}
		s = t;
		normalize();
	}

	void reflect() {
		for (int i = 0; i < s.size(); ++i) {
			reverse(s[i].begin(), s[i].end());
		}
		normalize();
	}

	bool isSame(const Nmino &other) {
		return s == other.s;
	}

	bool isEqual(const Nmino &other) {
		normalize();
		Nmino current = other;
		current.normalize();
		for (int j = 0; j < 2; ++j) {
			for (int i = 0; i < 4; ++i) {
				current.rotate();
				if (isSame(current)) {
					return true;
				}
			}
			current.reflect();
		}
		return false;
	}

	bool isConnected() {
		queue < pair < int, int > > q;
		int n = s.size();
		int m = s[0].size();
		int dx[] = {-1, 0, 0, 1};
		int dy[] = {0, -1, 1, 0};

		vector < vector < bool > > used(n, vector < bool > (m, false));

		for (int i = 0; i < n && q.empty(); ++i) {
			for (int j = 0; j < m && q.empty(); ++j) {
				if (s[i][j] == 'X') {
					q.push(make_pair(i, j));
				}
			}
		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			used[x][y] = true;
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (s[nx][ny] == 'X' && !used[nx][ny]) {
						used[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!used[i][j] && s[i][j] == 'X') {
					return false;
				}
			}
		}
		return true;
	}

	void print() {
		for (int i = 0; i < s.size(); ++i) {
			cout << s[i] << endl;
		}
		cout << "---------" << endl;
	}
};

vector < Nmino > used;
vector < pair < Nmino, int > > objects[7];
int cntO[7] = {0, 0, 0, 0, 0, 0, 0};

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int C[] = {0, 1, 1, 2, 5, 12, 35};

void generate(int p) {
	vector < string > s(3, string(6, ' '));
	for (int i = 0; i < (1 << 18); ++i) {
		int bits = 0;
		for (int j = 0; j < 18; ++j) {
			if (i & (1 << j)) {
				++bits;
			}
		}
		if (bits != p) {
			continue;
		}

		for (int j = 0; j < 18; ++j) {
			if (i & (1 << j)) {
				s[j / 6][j % 6] = 'X';
			} else {
				s[j / 6][j % 6] = ' ';
			}
		}

		Nmino current;
		current.s = s;
		if (!current.isConnected()) {
			continue;
		}
		current.normalize();
		int id = cntO[p];
		bool nice = false;
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 4; ++k) {
				current.rotate();
				bool ok = true;
				for (int x = 0; x < objects[p].size(); ++x) {
					if (objects[p][x].first.isSame(current)) {
						ok = false;
						break;
					}
				}
				if (ok) {
					objects[p].push_back(make_pair(current, id));
					nice = true;
				}
			}
			current.reflect();
		}
		if (nice) {
			++cntO[p];
		}
	}
}

bool precheck(int total) {
	vector < vector < pair < int, int > > > c(total + 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != 0) {
				c[a[i][j]].push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 1; i <= total; ++i) {
		for (int a = 0; a < c[i].size(); ++a) {
			for (int b = a + 1; b < c[i].size(); ++b) {
				int dx = abs(c[i][a].first - c[i][b].first);
				int dy = abs(c[i][a].second - c[i][b].second);
				if (dx + dy >= p) {
					return false;
				}
			}
		}
	}
	return true;
}

vector < int > visited;
set < int > S;

vector < int > ids;
void rec(int filled) {
	if (S.size() == C[p]) {
		return ;
	}
	if (filled == n * m) {
		//cerr << ids[0] << " " << ids[1] << " " << ids[2] << " " << ids[3] << endl;
		for (int i = 0; i < visited.size(); ++i) {
			S.insert(visited[i]);
		}
		return;
	}

	int x = filled / m;
	int y = filled % m;
	if (a[x][y] != 0) {
		rec(filled + 1);
		return;
	}

	for (int t = 0; t < objects[p].size(); ++t) {
		const vector < string > &current = objects[p][t].first.s;
		int sx = -1, sy = -1;
		for (int i = 0; i < current.size() && sx == -1; ++i) {
			for (int j = 0; j < current[i].size() && sy == -1; ++j) {
				if (current[i][j] == 'X') {
					sx = i;
					sy = j;
				}
			}
		}

		/*if (ids.size() >= 4 && ids[0] == 7 && ids[1] == 89 && ids[2] == 143 && ids[3] == 153) {
			int t = 0;
		}*/
		bool isOk = true;
		for (int i = 0; i < current.size() && isOk; ++i) {
			for (int j = 0; j < current[i].size() && isOk; ++j) {
				if (current[i][j] == ' ') {
					continue;
				}
				int px = x - sx + i;
				int py = y - sy + j;
				if (px >= 0 && px < n && py >= 0 && py < m && a[px][py] == 0) {
				} else {
					isOk = false;
				}
			}
		}
		if (!isOk) {
			continue;
		}

		for (int i = 0; i < current.size(); ++i) {
			for (int j = 0; j < current[i].size(); ++j) {
				if (current[i][j] == ' ') {
					continue;
				}
				int px = x - sx + i;
				int py = y - sy + j;
				if (px >= 0 && px < n && py >= 0 && py < m && a[px][py] == 0) {
					a[px][py] = 1;
				}
			}
		}
		visited.push_back(objects[p][t].second);
		if (visited.size() > 3) {
			int t = 0;
		}
		ids.push_back(t);
		rec(filled + 1);
		ids.pop_back();
		visited.pop_back();
		for (int i = 0; i < current.size(); ++i) {
			for (int j = 0; j < current[i].size(); ++j) {
				if (current[i][j] == ' ') {
					continue;
				}
				int px = x - sx + i;
				int py = y - sy + j;
				a[px][py] = 0;
			}
		}
		
	}
}

void rec2(int filled, int total = 0) {
	if (!precheck(total)) {
		return;
	}
	if (used.size() == C[p]) {
		return;
	}
	if (filled == n * m) {
		for (int i = 1; i <= total; ++i) {
			if (cnt[i] != p) {
				return;
			}
		}

		for (int i = 1; i <= total; ++i) {
			vector < string > s(n, string(m, ' '));
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					if (a[j][k] == i) {
						s[j][k] = 'X';
					}
				}
			}
			Nmino current;
			current.s = s;
			current.normalize();
			if (!current.isConnected()) {
				return;
			}
		}
		
		for (int i = 1; i <= total; ++i) {
			vector < string > s(n, string(m, ' '));
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					if (a[j][k] == i) {
						s[j][k] = 'X';
					}
				}
			}
			Nmino current;
			current.s = s;
			current.normalize();

			bool ok = true;
			for (int j = 0; j < used.size(); ++j) {
				if (current.isEqual(used[j])) {
					ok = false;
					break;
				}
			}
			if (ok) {
				used.push_back(current);
				//used.back().print();
				//cerr << used.size() << endl;
			}
		}
		return ;
	}

	int x = filled / m;
	int y = filled % m;
	for (int i = 1; i <= min((n * m) / p, total + 1); ++i) {
		if (cnt[i] + 1 <= p) {
			a[x][y] = i;
			++cnt[i];
			rec2(filled + 1, max(i, total));
			--cnt[i];
			a[x][y] = 0;
		}
	}
}

void solve(int test) {
	int x, r, c;
	cin >> x >> r >> c;
	cerr << x << " " << r << " " << c << endl;
	n = r;
	m = c;
	p = x;
	if (r > c) {
		swap(r, c);
		swap(n, m);
	}
	if (x > r * c || (x > r && x > c) || x >= 7 || (r * c) % x != 0) {
		printf("Case #%d: RICHARD\n", test);
		return ;
	}
	if (x == 4) {
		if (r == 1 || r == 2) {
			printf("Case #%d: RICHARD\n", test);
			return;
		}
		printf("Case #%d: GABRIEL\n", test);
		return;
	}
	if (x == 5) {
		if (r == 1 || r == 2) {
			printf("Case #%d: RICHARD\n", test);
			return;
		}
		if (r == 3 && c == 5) {
			printf("Case #%d: RICHARD\n", test);
			return;
		}
		printf("Case #%d: GABRIEL\n", test);
		return;
	}
	if (x == 6) {
		if (r == 1 || r == 2 || r == 3) {
			printf("Case #%d: RICHARD\n", test);
			return;
		}
		if (r >= 4 && c >= 6) {
			printf("Case #%d: GABRIEL\n", test);
			return;
		}
	}
	memset(a, 0, sizeof(a));
	memset(cnt, 0, sizeof(cnt));
	used.clear();
	S.clear();
	rec(0);
	if (S.size() != C[p]) {
		printf("Case #%d: RICHARD\n", test);	
	} else {
		printf("Case #%d: GABRIEL\n", test);	
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (int i = 1; i <= 6; ++i) {
		generate(i);
	}

	cerr << "Generation is over" << endl;

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << (i + 1) << endl;
	}
	cerr << "Time: " << clock() << endl;
	return 0;
}