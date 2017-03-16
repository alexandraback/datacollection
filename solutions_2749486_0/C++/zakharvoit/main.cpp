#pragma comment(linker, "/stack:8388608")
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cassert>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

const int MAXN = 550;

int getX(char c) {
	if (c == 'E')
		return 1;
	if (c == 'W')
		return -1;
	return 0;
}

int getY(char c) {
	if (c == 'N')
		return 1;
	if (c == 'S')
		return -1;
	return 0;
}

const int sx = MAXN / 2;
const int sy = MAXN / 2;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		
		int x, y;
		cin >> x >> y;

		x += sx;
		y += sy;

		vector <vector <char> > d(MAXN, vector <char>(MAXN)), nd;
		vector <vector <vector <char> > > p(MAXN, vector < vector <char> > (MAXN, vector <char>(MAXN)));

		d[sx][sy] = true;

		int ans = 0;

		for (int s = 0; s < MAXN; s++) {
			nd.assign(MAXN, vector <char>(MAXN));
			for (int i = 0; i < MAXN; i++) {
				for (int j = 0; j < MAXN; j++) {
					if (i - s - 1 >= 0 && d[i - s - 1][j]) {
						nd[i][j] = true;
						p[i][j][s] = 'N';
					}
					if (i + s + 1 < MAXN && d[i + s + 1][j]) {
						nd[i][j] = true;
						p[i][j][s] = 'S';
					}
					if (j - s - 1 >= 0 && d[i][j - s - 1]) {
						nd[i][j] = true;
						p[i][j][s] = 'E';
					}
					if (j + s + 1 < MAXN && d[i][j + s + 1]) {
						nd[i][j] = true;
						p[i][j][s] = 'W';
					}
				}
			}
			if (nd[y][x]) {
				ans = s;
				break;
			}
			d = nd;
		}

		string res;

		while (ans >= 0) {
			res += p[y][x][ans];
			int dx = x;
			int dy = y;
			y -= (ans + 1) * getY(p[dy][dx][ans]);
			x -= (ans + 1) * getX(p[dy][dx][ans]);
			--ans;
		}

		reverse(res.begin(), res.end());
		cout << "Case #" << (test + 1) << ": " << res << endl;
	}

	return 0;
}