#define _CRT_SECURE_NO_DEPRECATE
#define _ASSERTE

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <ctime>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for(int i = a; i < (int)(b); ++i)
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(a) a.begin,a.end()
#define ll long long
#define INF 1e9
#define EPS 1e-8

int h, n, m, c[123][123], f[123][123];

double d[123][123];
bool used[123][123];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool pass(int i, int j, int x, int y, int level = h) {
	if (c[i][j] - f[x][y] < 50)return 0;
	if (c[x][y] - f[i][j] < 50)return 0;
	if (c[x][y] - level < 50) return 0;
	if (c[x][y] - f[x][y] < 50)return 0;
	return 1;
}

int cost(int i, int j, int x, int y, int level = h) {
	if (level - f[i][j] >= 20)
		return 1;
	return 10;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int t;
	cin >> t;
	forn(tt, t){
		cerr << tt + 1 << endl;


		cin >> h >> n >> m;
		forn(i, n)
			forn(j, m) {
				cin >> c[i][j];
		}
		forn(i, n)
			forn(j, m) {
				cin >> f[i][j];
				d[i][j] = INF;
				used[i][j] = 0;
		}

		d[0][0] = 0;
		queue< pii > q;
		q.push(mp(0, 0));
		while(!q.empty()) {
			pii v = q.front();
			q.pop();
			forn(k, 4) {
				int x = v.first + dx[k];
				int y = v.second + dy[k];
				if (x >= 0 && y >= 0 && x < n && y < m && pass(v.first, v.second, x, y)) {
					if (d[x][y] > 0) {
						d[x][y] = 0;
						q.push(mp(x, y));
					}
				}
			}
		}

		forn(st, n * m) {
			pii v = mp(-1, -1);
			double best = INF * 2;
			forn(i, n){
				forn(j, m){
					if (!used[i][j] && d[i][j] < best) {
						best = d[i][j];
						v = mp(i, j);
					}
				}
			}
			if (v.first == -1)
				break;

			int i = v.first, j = v.second;
			used[v.first][v.second] = 1;
			forn(k, 4) {
				int x = v.first + dx[k];
				int y = v.second + dy[k];
				if (!(x >= 0 && y >= 0 && x < n && y < m))continue;
				double t = d[i][j];
				int water = max(0, int(h - t * 10 + EPS));
				if (pass(i, j, x, y, water)) {
					d[x][y] = min(d[x][y], d[i][j] + cost(i, j, x, y, water));
				}else {
					if (c[i][j] - f[x][y] >= 50 && c[x][y] - f[i][j] >= 50 && c[x][y] - f[x][y] >= 50){
						int diff = 50 - (c[x][y] - water);
						double add_t = diff * 0.1;
						d[x][y] = min(d[x][y], d[i][j] + add_t + cost(i, j, x, y, water - diff));
					}
				}
			}
		}

		cout << "Case #" << (tt + 1) << ": ";
		printf("%.7f\n", d[n - 1][m - 1]);
	}
	
	return 0;
}