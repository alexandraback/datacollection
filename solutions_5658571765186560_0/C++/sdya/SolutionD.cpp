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

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int C[] = {0, 1, 1, 2, 5, 12, 35};

void rec(int filled, int total = 0) {
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
	/*if (valid(x, y - 1) && cnt[a[x][y - 1]] + 1 <= p) {
		a[x][y] = a[x][y - 1];
		++cnt[a[x][y]];
		rec(filled + 1, total);
		--cnt[a[x][y]];
	}
	if (valid(x - 1, y) && cnt[a[x - 1][y]] + 1 <= p) {
		a[x][y] = a[x - 1][y];
		++cnt[a[x][y]];
		rec(filled + 1, total);
		--cnt[a[x][y]];
	}*/
	for (int i = 1; i <= min((n * m) / p, total + 1); ++i) {
		if (cnt[i] + 1 <= p) {
			a[x][y] = i;
			++cnt[i];
			rec(filled + 1, max(i, total));
			--cnt[i];
		}
	}
}

void solve(int test) {
	int x, r, c;
	cin >> x >> r >> c;
	n = r;
	m = c;
	p = x;
	if (x > r * c || (x > r && x > c) || x >= 7 || (r * c) % x != 0) {
		printf("Case #%d: RICHARD\n", test);
		return ;
	}
	memset(a, 0, sizeof(a));
	memset(cnt, 0, sizeof(cnt));
	used.clear();
	rec(0);
	/*for (int i = 0; i < used.size(); ++i) {
		used[i].print();
	}*/
	if (used.size() != C[p]) {
		printf("Case #%d: RICHARD\n", test);	
	} else {
		printf("Case #%d: GABRIEL\n", test);	
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//while (true) {
	//	solve(0);
	//}

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << (i + 1) << endl;
	}
	cerr << "Time: " << clock() << endl;
	return 0;
}