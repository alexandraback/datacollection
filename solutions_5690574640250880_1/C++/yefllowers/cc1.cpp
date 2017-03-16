#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};

char a[55][55];
int r, c, m, n;

string toString() {
	string s;
	a[0][0] = 'c';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			s.push_back(a[i][j]);
		if (i < r - 1)
			s.push_back('\n');
	}
	return s;
}

bool inrange(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}

int count(int x, int y) {
	int c = 0;
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (inrange(xx, yy) && a[xx][yy] == '*')
			c++;
	}
	return c;
}

bool v[55][55];

bool check() {
//	cout << "CHECK : " << endl << toString() << endl;
	int cnt = 0;
	for (int i = 0; i < r; i++)
	for (int j = 0; j < c; j++)
	if (a[i][j] == '*')
		cnt++;
	if (cnt != m) return false;
	memset(v, 0, sizeof(v));
	queue<pair<int, int> > Q;
	Q.push(make_pair(0, 0));
	cnt = 0;
	v[0][0] = true;
	while (!Q.empty()) {
		cnt++;
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		if (count(x, y) == 0)
		for (int i = 0; i < 8; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (inrange(xx, yy) && a[xx][yy] != '*' && !v[xx][yy]) {
				Q.push(make_pair(xx, yy));
				v[xx][yy] = true;
			}
		}
	}
	return cnt == r * c - m;
}

bool u[2555][55][55];
int b[55];

void set() {
	memset(a, '*', sizeof(a));
	for (int i = 0; i < r; i++)
	for (int j = 0; j < b[i]; j++)
		a[i][j] = '.';
	for (int i = 0; i < r; i++)
	for (int j = 0; j < c; j++) if (a[i][j] == '*')
	for (int k = 0; k < 8; k++) {
		int x = i + dx[k];
		int y = j + dy[k];
		if (inrange(x, y) && a[x][y] == '.') {
			a[i][j] = ',';
			break;
		}
	}
	for (int i = 0; i < r; i++)
	for (int j = 0; j < c; j++)
		if (a[i][j] == ',')
			a[i][j] = '.';
}

bool dfs(int now, int i, int j) {
	//cout << "DFS " << now << ' ' << i << ' ' << j << endl;
	b[i] = j;
	if (i == r) {
		if (now != n) return false;
		set();
		return check();
	}
	if (now > n) return false;
	if (now + (j + 1) * (r - i) < n) return false;
//	cout << "DDD" << endl;
	if (u[now][i][j]) return false;
	u[now][i][j] = true;
	for (int k = 0; k <= j; k++) {
		int tmp = j + 1;
		if (j == 0 || i == r - 1) tmp = 0;
		if (dfs(now + tmp, i + 1, k)) return true;
	}
	return false;
}

string solve() {
	cin >> r >> c >> m;
	n = r * c - m;
	memset(a, '*', sizeof(a));
	if (n == 1) return toString();
	if (r == 1) for (int i = 1; i < n; i++) a[0][i] = '.';
	if (c == 1) for (int i = 1; i < n; i++) a[i][0] = '.';
	if (check()) return toString();
	if (n <= 2 * c) {
		int o = n / 2;
		for (int i = 0; i < n - o; i++) a[0][i] = '.';
		for (int i = 0; i < o; i++) a[1][i] = '.';
	} else
	if (n <= 2 * r) {
		int o = n / 2;
		for (int i = 0; i < n - o; i++) a[i][0] = '.';
		for (int i = 0; i < o; i++) a[i][1] = '.';
	}
	if (check()) return toString();
	memset(u, 0, sizeof(u));
	for (int i = 1; i <= c; i++)
	if (dfs(i + 1, 0, i)) return toString();
	if (n != 2 && n != 3 && !(min(r,c) == 2 && n % 2 == 1)) cerr << r << ' ' << c << ' ' << m << endl;
	return "Impossible";
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ":" << endl << solve() << endl;
	}
}