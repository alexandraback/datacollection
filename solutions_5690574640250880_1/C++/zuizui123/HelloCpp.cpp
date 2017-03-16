#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;

#define fi "C-large.in"
#define fo "out.txt"
const int MAXN = 50 + 5;
const int INF = 1e9;
const int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
const int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

int res[MAXN][MAXN];
int R, C, M;
int r, c;
vector<pair<int, int> > bound;
int visited[MAXN][MAXN], visitId;

bool ok(int, int);
bool zerosConnected();
bool goodBound();

int main() {
	freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ":" << endl;
		cin >> R >> C >> M;
		//cout << R << " " << C << " " << M << endl;
		if (M == R * C - 1) {
			for (int i = 0; i < R; ++i) {
				int k;
				for (k = 0; k < C; ++k) {
					if (M == 0) break;
					cout << "*";
					--M;
				}
				if (k == C) cout << endl;
				if (M == 0) break;
			}
			cout << "c" << endl;
			continue;
		}
		for (int i = 0; i <= R + 1; ++i) {
			for (int k = 0; k <= C + 1; ++k) {
				res[i][k] = 0;
			}
		}
		r = R;
		c = C;
		while (M >= min(r, c)) {
			M -= min(r, c);
			if (r == min(r, c)) {
				for (int i = R; i > R - r; --i) {
					res[i][C - c + 1] = 9;
				}
				--c;
			} else {
				for (int i = C; i > C - c; --i) {
					res[R - r + 1][i] = 9;
				}
				--r;
			}
		}

		for (int i = max(R - r, 1); i <= R; ++i) {
			for (int k = max(C - c, 1); k <= C; ++k) {
				if (res[i][k] == 9) {
					for (int d = 0; d < 8; ++d) {
						int ii = i + dx[d];
						int kk = k + dy[d];
						if (ok(ii, kk) && res[ii][kk] < 9) {
							++res[ii][kk];
						}
					}
				}
			}
		}
//		cout << r << " " << c << endl;
//		for (int i = 1; i <= R; ++i) {
//			for (int k = 1; k <= C; ++k) {
//				cout << res[i][k] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
		int flag = 1;
		for (int i = 0; i < MAXN; ++i) {
			for (int k = 0; k < MAXN; ++k) {
				visited[i][k] = 0;
			}
		}
		visitId = 0;
		while (flag && M) {
			flag = 0;
			for (int i = R - r + 1; i <= R; ++i) {
				for (int k = C - c + 1; k <= C; ++k) {
					if (res[i][k] < 9) {
						int temp = res[i][k];
						res[i][k] = 9;
						for (int d = 0; d < 8; ++d) {
							int ii = i + dx[d];
							int kk = k + dy[d];
							if (ok(ii, kk) && res[ii][kk] < 9) {
								++res[ii][kk];
							}
						}
//						if (i == 6 && k == 7) {
//							for (int ti = 1; ti <= R; ++ti) {
//								for (int tk = 1; tk <= C; ++tk) {
//									cout << res[ti][tk] << " ";
//								}
//								cout << endl;
//							}
//						}
//						cout << endl;
						if (zerosConnected()) {
//							cout << bound.size() << endl;
//							for (int ti = 0; ti < bound.size(); ++ti) {
//								cout << bound[ti].first << " " << bound[ti].second << endl;
//							}
//							cout << endl;
							if (goodBound()) {
								flag = 1;
							}
						}
						if (!flag) {
							res[i][k] = temp;
							for (int d = 0; d < 8; ++d) {
								int ii = i + dx[d];
								int kk = k + dy[d];
								if (ok(ii, kk) && res[ii][kk] < 9) {
									--res[ii][kk];
								}
							}
						} else {
							--M;
							break;
						}
					}
				}
				if (flag) break;
			}
		}
		if (M > 0) {
			cout << "Impossible" << endl;
		} else {
			bool containZeros = false;
			for (int i = 1; i <= R; ++i) {
				for (int k = 1; k <= C; ++k) {
					if (res[i][k] == 0) {
						containZeros = true;
						break;
					}
				}
				if (containZeros) break;
			}
			if (!containZeros) {
				cout << "Impossible" << endl;
				continue;
			}
			bool clicked = false;
			for (int i = 1; i <= R; ++i) {
				for (int k = 1; k <= C; ++k) {
					if (res[i][k] == 9) {
						cout << "*";
					} else {
						if (!clicked && res[i][k] == 0) {
							clicked = true;
							cout << "c";
						} else {
							cout << ".";
						}
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}

bool ok(int x, int y) {
	return (x >= R - r + 1 && x <= R && y >= C - c + 1 && y <= C);
}

bool zerosConnected() {
	int sx, sy;
	sx = sy = -1;
	for (int i = R - r + 1; i <= R; ++i) {
		for (int k = C - c + 1; k <= C; ++k) {
			if (res[i][k] == 0) {
				sx = i;
				sy = k;
				break;
			}
		}
		if (sx != -1) break;
	}
	if (sx == -1) {
		return false;
	}
	queue<pair<int, int> > qu;
	bound.clear();
	++visitId;
	qu.push(make_pair(sx, sy));
	visited[sx][sy] = visitId;
	int numZeros = 1;
	while (!qu.empty()) {
		int x, y;
		x = qu.front().first;
		y = qu.front().second;
		qu.pop();
		for (int p = 0; p < 8; ++p) {
			int xp = x + dx[p];
			int yp = y + dy[p];
			if (ok(xp, yp) && res[xp][yp] > 0 && res[xp][yp] < 9 && visited[xp][yp] != visitId) {
				visited[xp][yp] = visitId;
				bound.push_back(make_pair(xp, yp));
			}
		}
		for (int d = 0; d < 8; ++d) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (ok(xx, yy) && res[xx][yy] == 0 && visited[xx][yy] != visitId) {
				visited[xx][yy] = visitId;
				qu.push(make_pair(xx, yy));
				++numZeros;
			}
		}
	}
	for (int i = R - r + 1; i <= R; ++i) {
		for (int k = C - c + 1; k <= C; ++k) {
			if (res[i][k] == 0) {
				--numZeros;
			}
		}
	}
	if (numZeros < 0) {
		return false;
	}
	return true;
}

bool goodBound() {
	for (int i = 0; i < bound.size(); ++i) {
		int x, y;
		x = bound[i].first;
		y = bound[i].second;
		for (int d = 0; d < 8; ++d) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (ok(xx, yy) && visited[xx][yy] != visitId && res[xx][yy] > 0 && res[xx][yy] < 9) {
				return false;
			}
		}
	}
	return true;
}
