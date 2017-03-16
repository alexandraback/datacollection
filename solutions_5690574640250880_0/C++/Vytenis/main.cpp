#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
 
using namespace std;
 
 
#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)

int dr[] = {0, -1, -1, -1, 0, 1, 1, 1 };
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1 };

char board[64][64], open[64][64];
int r, c, m;

bool solve() {
	int x, y;

	REP(i,r) REP(j,c) if (board[i][j] == 'c') { x = i; y = j; }
	memset(open, 0, sizeof(open));

	queue <pair<int,int> > q;
	q.push(make_pair(x, y));
	int cnt = 1; open[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop(); 
		int cm = 0;
		FOR(dx,-1,2) FOR(dy,-1,2) {
			int nx = x+dx, ny = y+dy;
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (board[nx][ny] == '*') ++cm;
		}
		if (cm == 0) {
			FOR(dx,-1,2) FOR(dy,-1,2) {
				int nx = x+dx, ny = y+dy;
				if (nx < 0 || ny < 0 || nx >= r || ny >= c || board[nx][nx] == '*') continue;
				if (!open[nx][ny]) {
					open[nx][ny] = 1; ++cnt;
					q.push(make_pair(nx,ny));
				}
			}
		}
		
		
	}
	return cnt+m == r*c;
}

bool gen(int mines, bool placed, int row, int col) {
	if (row == r) {
		if (mines == 0 && placed) {
			if (solve()) {
				REP(i,r) cout << board[i] << endl;
				return true;
			}
		}
		return false;
	}

	int leftObj = mines + (placed?0:1), leftCells = (r-row-1)*c+c-col;
	if (leftCells < leftObj) return false;

	if (mines) {
		board[row][col] = '*';
		if (gen(mines-1, placed, col==c-1?row+1:row, (col+1)%c)) return true;
		board[row][col] = '.';
	}

	if (!placed) {
		board[row][col] = 'c';
		if (gen(mines, true, col==c-1?row+1:row, (col+1)%c)) return true;
		board[row][col] = '.';
	}

	if (gen(mines, placed, col==c-1?row+1:row, (col+1)%c)) return true;

	return false;
}
 

int main() {
	int t;
	char b[64][64];

	cin >> t;

	REP(tc,t) {
		cin >> r >> c >> m;
		cout << "Case #" << tc+1 << ":" << endl;

		/*REP(i,r) REP(j,c) board[i][j] = '.';
		REP(i,r) board[i][c] = 0;
		if (!gen(m, false, 0, 0)) cout << "Impossible" << endl;*/
		
		bool ok = true;

		REP(i,r) REP(j,c) b[i][j] = '.';
		REP(i,r) b[i][c] = 0;

		if (r*c-m == 1) {
			REP(i,r) REP(j,c) b[i][j] = '*';
			b[0][0] = 'c';
		} else if (r == 1) {
			REP(i,m) b[0][i] = '*';
			b[0][c-1] = 'c';
		} else if (c == 1) {
			REP(i,m) b[i][0] = '*';
			b[r-1][0] = 'c';
		} else if (r == 2) {
			if (m%2 || r*c-m==2) ok = false;
			else {
				REP(i,m/2) b[0][i] = b[1][i] = '*';
				b[0][c-1] = 'c';
			}
		} else if (c == 2) {
			if (m%2 || r*c-m==2) ok = false;
			else {
				REP(i,m/2) b[i][0] = b[i][1] = '*';
				b[r-1][0] = 'c';
			}
		} else {
			if (r*c-m < 4 || r*c-m == 5 || r*c-m == 7) ok = false;
			else {
				b[r-1][c-1] = 'c';
				REP(i,r-2) REP(j,c-2) if (m>0) { b[i][j] = '*'; --m; }
				if (m > 0) {
					if (m%2) { ++m; b[r-3][c-3] = '.'; }
					int rix = 0, cix = 0;
					while (m > 0) { 
						if (r-rix > c-cix) { b[rix][c-2] = b[rix][c-1] = '*'; m -= 2; ++rix; }
						else { b[r-2][cix] = b[r-1][cix] = '*'; m -= 2; ++cix; }
					}
				}
			}
		}

		if (ok) {
			REP(i,r) cout << b[i] << endl;
		} else
			cout << "Impossible" << endl;
	}

	return 0;
} 