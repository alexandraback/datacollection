#include <iostream>
#include <queue>

using namespace std;

int const LIM = 55;

int n, m, c;
bool b[LIM][LIM];

int dx[] = {1, 0};
int dy[] = {0, 1};

void tetris(int i, int j) {
	if (c == 0)
		return;
	queue<pair<int, int>> q;
	--c;
	b[i][j] = true;
	q.push(make_pair(i, j));
	while (!q.empty() && c > 0) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		for (int k = 0; k < 2 && c > 0; ++k) {
			int x1 = i + dx[k], y1 = j + dy[k];
			if (x1 >= n || y1 >= m)
				continue;
			if (b[x1][y1])
				continue;
			b[x1][y1] = true;
			--c;
			q.push(make_pair(x1, y1));
		}
	}
}

void gogo(int &i, int &j) {
	while (c >= m - j) {
		for (int k = j; k < m; ++k, --c)
			b[i][k] = true;
		++i;
		if (c < n - i)
			break;
		for (int k = i; k < n; ++k, --c)
			b[k][j] = true;
		++j;
	}
}

void gogo1(int &i, int &j) {
	while (c >= n - i) {
		for (int k = i; k < n; ++k, --c)
			b[k][j] = true;
		++j;
		if (c < m - j)
			break;
		for (int k = j; k < m; ++k, --c)
			b[i][k] = true;
		++i;
	}
}

bool zero[LIM][LIM];

bool check1(int _i, int _j) {
	for (int i = max(0, _i - 1); i <= _i + 1; ++i)
		for (int j = max(0, _j - 1); j <= _j + 1; ++j) {
			if (zero[i][j])
				return true;
		}
	return false;
}

bool check() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			zero[i][j] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (b[i][j]) {
				for (int i1 = max(0, i - 1); i1 < min(i + 2, n); ++i1)
					for (int j1 = max(0, j - 1); j1 < min(j + 2, m); ++j1) {
//						cout << "bitch" << endl;
						zero[i1][j1] = false;
					}
			}
		}
	}
#ifdef LOCAL_
	cout << "zero:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << zero[i][j];
		cout << endl;
	}
#endif
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!b[i][j])
				if (!check1(i, j))
					return false;
		}
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ":\n";
		cin >> n >> m >> c;
		if (c + 1 == n * m) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (i == n - 1 &&j == m - 1) {
						cout << 'c';
					} else {
						cout << '*';
					}
				}
				cout << endl;
			}
			continue;
		}
		int _c = c;
		if (n * m == c) {
			cout << "Impossible" << endl;
			continue;
		}
		for (int i = 0; i < LIM; ++i)
			for (int j = 0; j < LIM; ++j) {
				b[i][j] = false;
				zero[i][j] = false;
			}
		bool swapped = false;
		if (m > n) {
			swap(m, n);
			swapped = true;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				b[i][j] = false;
		int i = 0, j = 0;
		for (i = 0; i < n - m; ++i) {
			if (c >= m) {
				c -= m;
				for (int j = 0; j < m; ++j)
					b[i][j] = true;
			} else {
				break;
			}
		}
		if (c < m) {
			tetris(i, 0);
		} else {
			gogo(i, j);
			tetris(i, j);
		}
		if (b[n - 1][m - 1]) {
			cout << "Impossible" << endl;
			continue;
		} else {
			if (!check()) {
				c = _c;
				for (int i = 0; i < LIM; ++i)
					for (int j = 0; j < LIM; ++j) {
						b[i][j] = false;
						zero[i][j] = false;
					}
				bool swapped = false;
				if (m > n) {
					swap(m, n);
					swapped = true;
				}
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m; ++j)
						b[i][j] = false;
				int i = 0, j = 0;
				for (i = 0; i < n - m; ++i) {
					if (c >= m) {
						c -= m;
						for (int j = 0; j < m; ++j)
							b[i][j] = true;
					} else {
						break;
					}
				}
				if (c < m) {
					tetris(i, 0);
				} else {
					gogo1(i, j);
					tetris(i, j);
				}
			}
			if (!check()) {
				cout << "Impossible" << endl;
				continue;
			}
			if (swapped) {
				for (int i = 0; i < LIM; ++i) {
					for (int j = i + 1; j < LIM; ++j) {
						swap(b[j][i], b[i][j]);
					}
				}
				swap(n, m);
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (i == n - 1 && j == m - 1) {
						cout << "c";
					} else {
						cout << (b[i][j] ? '*' : '.');
					}
				}
				cout << endl;
			}
		}
#ifdef LOCAL_
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				cout << b[i][j];
			cout << endl;
		}
#endif
	}
	return 0;
}
