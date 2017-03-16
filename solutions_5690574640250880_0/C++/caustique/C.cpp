#pragma comment(linker,"/stack:256000000")

#include <cmath> 
#include <ctime> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <set> 
#include <map> 
#include <cstring> 
#include <cstdlib> 
#include <queue> 
#include <cstdio> 
#include <cfloat>

using namespace std; 

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++) 
#define sz(v) (int)(v).size() 
#define all(v) (v).begin(), (v).end()

int u[55][55];
int n, m, k;
bool OK;

int calc(int x, int y) {
	int cnt = 0;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0) continue;
			int nx = x + dx;
			int ny = y + dy;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !u[nx][ny]) {
				++cnt;
			}
		}
	}
	return cnt;
}

void paint(int x, int y, int dif) {
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0) continue;
			int nx = x + dx;
			int ny = y + dy;
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				u[nx][ny] += dif;
			}
		}
	}
}

void dfs(int z) {
	if (z > k) return;
	if (z == k) {
		OK = 1;
		return;
	}
	vector <pair <int, pair <int, int> > > p;
	REP(i, n) REP(j, m) {
		if (u[i][j]) {
			int c = calc(i, j);
			if (c == k - z) {
				paint(i, j, 1);
				OK = 1;
				return;
			} else if (0 < c && c < k - z) {
				p.push_back(make_pair(c, make_pair(i, j)));
			}
		}
	}
	sort(all(p));
	reverse(all(p));
	REP(i, sz(p)) {
		int x = p[i].second.first;
		int y = p[i].second.second;
		int c = p[i].first;
		paint(x, y, 1);
		dfs(z + c);
		if (OK) return;
		paint(x, y, -1);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie();
	int T;
	cin >> T;
	REP(_, T) {
		cout << "Case #" << _ + 1 << ":" << endl;
		cin >> n >> m >> k;
		k = n * m - k;
		REP(i, n) {
			REP(j, m) {
				memset(u, 0, sizeof(u));
				OK = 0;
				u[i][j] = 1;
				dfs(1);
				if (OK) {
					REP(x, n) {
						REP(y, m) {
							if (u[x][y]) {
								if (x == i && y == j) {
									cout << "c";
								} else {
									cout << ".";
								}
							} else {
								cout << "*";
							}
						}
						cout << endl;
					}
					break;
				}
			}
			if (OK) break;
		}
		if (!OK) puts("Impossible");
	}
	return 0;
}