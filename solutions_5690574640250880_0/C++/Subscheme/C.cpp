#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#define fo(i,n) for(int i=0,_n=(n); i<_n; ++i)

int T;
int r, c, m, l;
const int R = 55, C = 55;
char grid[R][C];

bool ismine(int i, int j) {
	if(i < 0 || j < 0 || i == r || j == c) return false;
	if(grid[i][j] == '*') return true;
	return false;
}

void mark(int i, int j) {
	if(grid[i][j] == 'c') return;
	grid[i][j] = 'c';
	bool go = true;
	for(int nr = i-1; nr <= i+1; ++nr) for(int nc = j-1; nc <= j+1; ++nc) {
		if(ismine(nr,nc)) go = false;
	}
	if(go) {
		for(int nr=max(i-1,0); nr <= min(i+1,r-1); ++nr) for(int nc=max(j-1,0); nc <= min(j+1,c-1); ++nc) mark(nr,nc);
	}
}

bool test_grid() {
	int tr = -1, tc;
	fo(i,r) fo(j,c) {
		bool poss = true;
		for(int nr=max(i-1,0); nr <= min(i+1,r-1); ++nr)
			for(int nc=max(j-1,0); nc <= min(j+1,c-1); ++nc)
				if(grid[nr][nc] == '*')
					poss = false;
		if(poss) {
			tr = i;
			tc = j;
		}
	}
	if(tr == -1) return false;
	mark(tr,tc);
	bool poss = true;
	fo(i,r) fo(j,c) if(grid[i][j] == '.') poss = false; else if(grid[i][j] != '*') grid[i][j] = '.';
	if(poss) {
		grid[tr][tc] = 'c';
		return true;
	}
	return false;
}

bool test(int i, int j, int k) {
	if(j == c) {
		if(k) return false;
		return test_grid();
	}
	if(k) {
		grid[i][j] = '*';
		if(test((i+1)%r, j + ((i+1)/r), k-1)) return true;
	}
	grid[i][j] = '.';
	if(test((i+1)%r, j + ((i+1)/r), k)) return true;
	return false;
}

int main() {
	cin >> T;
	fo(t,T) {
		cout << "Case #" << t + 1 << ":\n";
		cin >> r >> c >> m;
		if(r * c - m == 1) {
			cout << 'c';
			fo(j,c-1) cout << '*';
			cout << '\n';
			fo(i,r-1) {
				fo(j,c) cout << '*';
				cout << '\n';
			}
		} else if(test(0,0,m)) {
			fo(i,r) grid[i][c] = '\0', cout << grid[i] << '\n';
		} else {
			cout << "Impossible\n";
		}
	}
}