#include<iostream>
#include<cstdio>
#define loop(i, c) for(int i = 0; i < c; i++)

using namespace std;

int X, Y, M, NM;

struct sq {
	int num;
	bool bomb, visited;
} board[50][50];

bool valid(int x, int y) { return x < X && x >= 0 && y < Y && y >= 0; }

int dir[3] = {-1, 0, 1};
void recurse1(int x, int y) {
	board[x][y].visited = true;
	if(board[x][y].num != 0) return;
	loop(i, 3) loop(j, 3) {
		int _x = x+dir[i], _y = y+dir[j];
		if(!valid(_x, _y)) continue;
		if(!board[_x][_y].visited && !board[_x][_y].bomb)
			recurse1(_x, _y);
	}
}

void setNums() {
	loop(x, X) loop(y, Y) {
		if(!board[x][y].bomb) continue;
		loop(i, 3) loop(j, 3) {
			int _x = x+dir[i], _y = y+dir[j];
			if(!valid(_x, _y)) continue;
			board[_x][_y].num++;
		}
	}
}

bool check() {
	int count = 0;
	setNums();
	loop(x, X) loop(y, Y) {
		if(!board[x][y].bomb) {
			count++;
			if(!board[x][y].num) {
				recurse1(x, y);
				loop(i, X) loop(j, Y) {
					if(!board[i][j].bomb && !board[i][j].visited)
						return false;
				}
				return true;
			}
		}
	}
	return count == 1;
}

bool run() {
	for(int w = 1; w <= X; w++) {
		for(int h = (NM-w)/(w+1); h <= NM/w && h <= Y; h++) {
			int xtra = NM-w*h;
			int xside = h < xtra ? h : xtra;
			for(int xbot = xtra-xside; xbot <= w && xside >= 0; xbot++, xside--) {
				if(xbot != 0 && h == Y) break;
				if(xside != 0 && w == X) continue;
				loop(x, X) loop(y, Y) {
					board[x][y].num = 0;
					board[x][y].bomb = true;
					board[x][y].visited = false;
				}
				loop(i, w) loop(j, h) board[i][j].bomb = false;
				loop(i, xbot) board[i][h].bomb = false;
				loop(i, xside) board[w][i].bomb = false;
				if(check()) return true;
			}
		}
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	loop(t, T) {
		cin >> Y >> X >> M;
		NM = Y*X-M;
		printf("Case #%d:\n", t+1);
		if(!run()) printf("Impossible\n");
		else {
			loop(y, Y) {
				loop(x, X) {
					if(x == 0 && y == 0) cout << 'c';
					else cout << (board[x][y].bomb ? '*' : '.');
				}
				cout << '\n';
			}
		}
	}
}













