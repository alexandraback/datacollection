#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define sz(x) (int)(x).size()

int r, c, m;
char field[55][55];
char used[55][55];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void fill() {
	for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			field[i][j] = '.';
		}
	}	
}

void print() {
	for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			cout << field[i][j];
		}
		cout << '\n';
	}
}

bool check() {
	memset(used, 0, sizeof(used));
	queue < pair < int, int > > q;
	for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			if(field[i][j] == 'c') {
				used[i][j] = true;
				q.push(make_pair(i, j));
				break;
			}
		}
	}
	assert(!q.empty());
	while(!q.empty()) {
		pair < int, int > p = q.front();
		q.pop();
		int cnt = 0;
		for(int k = 0;k < 8;k++) {
			int nx = p.first + dx[k];
			int ny = p.second + dy[k];
			if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if(used[nx][ny]) continue;
			if(field[nx][ny] == '*') {
				cnt++;
			}
		}
		if(cnt) continue;
		for(int k = 0;k < 8;k++) {
			int nx = p.first + dx[k];
			int ny = p.second + dy[k];
			if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if(used[nx][ny]) continue;
			if(field[nx][ny] == '.') {
				used[nx][ny] = true;
				q.push(make_pair(nx, ny));
			} else {
				assert(false);
			}
		}
	}
	for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			if(field[i][j] == '.' && !used[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void rec(int curR, int curC, int curM, bool start) {
	if(curR == r) {
		if(curM == 0 && start && check()) {
			throw 42;
		}
		return;
	}
	int nextR = curR;
	int nextC = curC + 1;
	if(nextC == c) {
		nextR++;
		nextC = 0;
	}
	rec(nextR, nextC, curM, start);
	if(curM > 0) {
		field[curR][curC] = '*';
		rec(nextR, nextC, curM - 1, start);
		field[curR][curC] = '.';
	}
	if(!start) {
		field[curR][curC] = 'c';
		rec(nextR, nextC, curM, true);
		field[curR][curC] = '.';
	}
}

int main() {
	int tests;
	cin >> tests;
	for(int t = 1;t <= tests;t++) {
		cin >> r >> c >> m;
		cout << "Case #" << t << ":\n";
		fill();
		try {
			rec(0, 0, m, false);
		} catch(...) {
			print();
			continue;
		}
		cout << "Impossible" << endl;
	}
	return 0;
}
