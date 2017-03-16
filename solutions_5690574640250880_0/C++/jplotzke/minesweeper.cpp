#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

struct Point {
	int r, c;
	Point(int R=0, int C=0){ r = R; c = C; }
};

const int N = 50;
int row, col, mines, cnt; char grid[N][N]; bool visit[N][N];

void place_mines(){
	int r = 0, c = 0, m = mines;
	for (int y = 0; y < row; ++y){
		for (int x = 0; x < col; ++x){
			grid[y][x] = '.';
			visit[y][x] = false;
		}
	}
	while (m > 0){
		if (row - r < col - c && m >= row - r){
			for (int y = r; y < row; ++y, --m)
				grid[y][c] = '*';
			++c;
		}
		else if (m >= col - c){
			for (int x = c; x < col; ++x, --m)
				grid[r][x] = '*';
			++r;
		}
		else break;
	}
	for (int z = c; m > 0; ++z)
		for (int y = r, x = z; y < row && x >= c && m > 0; ++y, --x, --m)
			grid[y][x] = '*';
	grid[row-1][col-1] = 'c';
}

bool zero(const int & r, const int & c){
	if (r == 0 && c == 0) return true;
	if (r == 0) return (grid[r][c-1] == '.');
	if (c == 0) return (grid[r-1][c] == '.');
	return (grid[r][c-1] == '.' && grid[r-1][c-1] == '.' && grid[r-1][c] == '.');
}

void visit_grid(){
	Point p; stack<Point> s;
	visit[row-1][col-1] = true;
	s.push(Point(row-1, col-1));
	for (cnt = 0; !s.empty(); ++cnt){
		p = s.top(); s.pop();
		if (zero(p.r, p.c)){
			if (p.c > 0 && !visit[p.r][p.c-1]){
				visit[p.r][p.c-1] = true;
				s.push(Point(p.r, p.c-1));
			}
			if (p.r > 0 && p.c > 0 && !visit[p.r-1][p.c-1]){
				visit[p.r-1][p.c-1] = true;
				s.push(Point(p.r-1, p.c-1));
			}
			if (p.r > 0 && !visit[p.r-1][p.c]){
				visit[p.r-1][p.c] = true;
				s.push(Point(p.r-1, p.c));
			}
		}
	}
}

int main(){
	FILE * fin, * fout;
	freopen_s(&fin, "C-small-attempt1.in", "r", stdin);
	freopen_s(&fout, "minesweeper.out", "w", stdout);
	int run; bool flipped; Point p; stack<Point> s;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		cin >> row >> col >> mines;
		if (row > col){
			int temp = row; row = col; col = temp;
			flipped = true;
		}
		else flipped = false;
		place_mines();
		visit_grid();
		cout << "Case #" << a << ":" << endl;
		if (mines + cnt < row * col)
			cout << "Impossible" << endl;
		else {
			if (flipped){
				for (int x = 0; x < col; ++x){
					for (int y = 0; y < row; ++y) cout << grid[y][x];
					cout << endl;
				}
			}
			else {
				for (int y = 0; y < row; ++y){
					for (int x = 0; x < col; ++x) cout << grid[y][x];
					cout << endl;
				}
			}
		}
	}
	return 0;
}
