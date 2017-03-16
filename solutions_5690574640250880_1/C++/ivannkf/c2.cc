#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;
typedef vector<int> VI;
typedef vector<VI> MI;

struct point {
	int i;
	int j;
};


void printBoard(MC &board) {
	for(int i = 0; i < board.size(); ++i) {
		for(int j = 0; j < board[i].size(); ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void printIntBoard(MI &board) {
	for(int i = 0; i < board.size(); ++i) {
		for(int j = 0; j < board[i].size(); ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

int getNum(MC &board, int x, int y) {
	int sum = 0;
	for(int i = -1; i <= 1; ++i) {
		for(int j = -1; j <= 1; ++j) {
			if(not(i == 0 and j == 0)) {
				if(x+i >= 0 and x+i < board.size() and y+j >= 0 and y+j < board[0].size()) {
					if(board[x+i][y+j] == '*') ++sum;
				}
			}
		}
	}
	return sum;
}

void search(MI &board, int x, int y) {
	
	queue<point> q;
	point op;
	op.i = x;
	op.j = y;
	q.push(op);
	while(not q.empty()) {
		point p = q.front(); q.pop();
		//cout << "<" << p.i << " "<< p.j << endl;
		if(board[p.i][p.j] == 0) {
			for(int i = -1; i <= 1; ++i) {
				for(int j = -1; j <= 1; ++j) {
					if(not(i == 0 and j == 0)) {
						if(p.i+i >= 0 and p.i+i < board.size() and p.j+j >= 0 and p.j+j < board[0].size()) {
							if(board[p.i+i][p.j+j] != -1) {
								//cout << x+i << " " << y+j <<  endl;
								point np;
								np.i = p.i+i;
								np.j = p.j+j;
								q.push(np);
							}
						}
					}
				}
			}
		}
		board[p.i][p.j] = -1;
	}
}

bool check(MC &board) {
	int x,y;
	bool found = false;
	int points = 0;
	MI numsboard(board.size(), VI(board[0].size(),-1));
	for(int i = 0; i < board.size(); ++i) {
		for(int j = 0; j < board[i].size(); ++j) {
			if(board[i][j] == '.') {
				++points;
				if(not found) {
					x = i;
					y = j;
				}
				int num = getNum(board,i,j);
				numsboard[i][j] = num;
				if (num == 0 and not found) {
					x = i;
					y = j;
					found = true;
				}
			}
		}
	}
	//printIntBoard(numsboard);
	if(not found) {
		if (points == 1) {
			board[x][y] = 'c';
		}
	}
	search(numsboard, x, y);
	//printIntBoard(numsboard);
	for(int i = 0; i < numsboard.size(); ++i) {
		for(int j = 0; j < numsboard[i].size(); ++j) {
			if(numsboard[i][j] != -1) return false;
		}
	}
	board[x][y] = 'c';
	return true;
}

bool permuteBorder(MC &board, int row, int col, int mines, int pos) {
	if(mines == 0) {
		printBoard(board);
		return check(board);
	}
	if(pos == row+col+1) return false;
	int i, j;
	if(pos <= row) {
		i = pos;
		j = col;
	} else {
		j = pos-row-1;
		i = row;
	}
	if(permuteBorder(board,row,col,mines,pos+1)) return true;
	board[i][j] = '*';
	if(permuteBorder(board,row,col,mines-1,pos+1)) return true;
	board[i][j] = '.';
	return false;
}

bool bf(MC &board, int pos, int r, int c, int m) {
	if(m == 0) {
		//printBoard(board);
		return check(board);
	}
	if(m > r*c-pos) return false;
	if(pos == r*c) return false;
	int i = pos/c;
	int j = pos%c;
	if(bf(board,pos+1,r,c,m)) return true;
	board[i][j] = '*';
	if(bf(board,pos+1,r,c,m-1)) return true;
	board[i][j] = '.';
	return false;
}

bool generate(MC &board, int r, int c, int m) {
	int m2 = r*c-m;

	int size = 0;
	while(m2 > 0) {
		for(int i = 0; i <= min(size, r-1) and size < c and m2 > 0; ++i) {
			board[i][size] = '.';
			--m2;
		}
		for(int j = 0; j < min(size, c) and size < r and m2 > 0; ++j) {
			board[size][j] = '.';
			--m2;
		}
		++size;
	}
	--size;
	int row = min(size,r-1);
	int col = min(size,c-1);
	int mines = 0;
	for(int i= 0; i <= row; ++i) {
		if(board[i][col] == '*') {
			++mines;
			board[i][col] = '.';
		}
	}
	for(int i= 0; i <= col; ++i) {
		if(board[row][i] == '*') {
			++mines;
			board[row][i] = '.';
		}
	}
	return bf(board,0,row+1,col+1,mines);
}


void calc(int r, int c, int m) {
	MC board(r, VC(c,'*'));
	if(generate(board,r,c,m)) {
		printBoard(board);
	} else {
		cout << "Impossible" << endl;
	}
}


int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		int r,c,m;
		cin >> r >> c >> m;
		cout << "Case #" << i+1 << ": " << endl;
		calc(r,c,m);
	}
}