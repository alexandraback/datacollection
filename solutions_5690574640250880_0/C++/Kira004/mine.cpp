#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

class pos {
	public:
		int row;
		int col;
		pos (int r, int c) : row(r), col(c) {};
};

pos nextp (pos p, int c) {
	if (p.col + 1 < c)
		p.col++;
	else {
		p.col = 0;
		p.row++;
	}
	return p;
}

bool check(vector<vector<int> > &board, vector<vector<int> > & visited, int m) {
	int row_num = board.size();
	int col_num = board[0].size();
	int i1, j1;
	bool flag = false;
	for (i1 = 0; i1 < row_num; ++i1) {
		for (j1 = 0; j1 < col_num; ++j1) {
			if (board[i1][j1] == 0) {
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	if (i1 == row_num || j1 == col_num)
		return false;
	pos p(i1,j1);
	int num = 1;
	visited[i1][j1] = 1;
	queue<pos> myqueue;
	myqueue.push(p);
	while (!myqueue.empty()) {
		pos tmp = myqueue.front();
		myqueue.pop();
		for (int i = tmp.row-1; i <= tmp.row+1; ++i) {
			if (i < 0 || i >= row_num)
				continue;
			for (int j = tmp.col-1; j <= tmp.col+1; ++j) {
				if (j < 0 || j >= col_num)
					continue;
				if (visited[i][j] == 0 && board[i][j] >= 0) {
					visited[i][j] = 1;
					num++;
					if (board[i][j] == 0) {
						pos tmp2(i, j);
						myqueue.push(tmp2);
					}
				}
			}
		}
	}
	if (num == row_num*col_num - m)
		return true;
	else
		return false;
}

void putmine(vector<vector<int> > &board, pos p) {
	int r = board.size();
	int c = board[0].size();

	for (int i = p.row-1; i <= p.row+1; ++i) {
		if (i < 0 || i >= r)
			continue;
		for (int j = p.col-1; j <= p.col+1; ++j) {
			if (j < 0 || j >= c)
				continue;
			if (i == p.row && j == p.col)
				continue;
			if (board[i][j] >= 0)
				board[i][j]++;
		}
	}
	board[p.row][p.col] = -1;
}

void removemine(vector<vector<int> > &board, pos p) {
	int r = board.size();
	int c = board[0].size();

	board[p.row][p.col] = 0;
	for (int i = p.row-1; i <= p.row+1; ++i) {
		if (i < 0 || i >= r)
			continue;
		for (int j = p.col-1; j <= p.col+1; ++j) {
			if (j < 0 || j >= c)
				continue;
			if (i == p.row && j == p.col)
				continue;
			if (board[i][j] > 0)
				board[i][j]--;
			else
				board[p.row][p.col]++;
		}
	}
}


bool dfs(vector<vector<int> > &board, pos p, int m_num, int m) {
	int row_num = board.size();
	int col_num = board[0].size();

	if (m_num == m) {
		vector<vector<int> > visited(row_num, vector<int>(col_num, 0));
		if (check(board, visited, m)) {
			/*
			for (int i = 0; i < row_num; ++i) {
				for (int j = 0; j < col_num; ++j)
					cout << right << setw(3) << board[i][j];
				cout << endl;
			}
			cout << endl;
			*/
			return true;
		}
		else
			return false;
	}
	if (p.row >= row_num)
		return false;

	for (int i = p.row; i < row_num; ++i) {
		for (int j = p.col; j < col_num; ++j) {
			pos cp(i, j);
			putmine(board, cp);
			pos np = nextp(cp, col_num);
			if (dfs(board, np, m_num+1, m))
				return true;
			removemine(board, cp);
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i) {
		int r, c, m;
		cin >> r >> c >> m;
		vector<vector<int> > board(r, vector<int>(c, 0));
		if (m == r*c - 1) {
			cout << "Case #" << i << ":" << endl;
			for (int row = 0; row < r; ++row) {
				for (int col = 0; col < c; ++col) {
					if (row == 0 && col == 0)
						cout <<"c";
					else 
						cout << "*";
				}
				cout << endl;
			}
			continue;
		}

		pos p(0, 0);
		bool res = dfs(board, p, 0, m);
		cout << "Case #" << i << ":" << endl;
		if (res) {
			bool flag = true;
			for (int row = 0; row < r; ++row) {
				for (int col = 0; col < c; ++col) {
					if (board[row][col] == 0 &&flag) {
						cout <<"c";
						flag = false;
					}
					else if (board[row][col] == -1)
						cout << "*";
					else
						cout << ".";
				}
				cout << endl;
			}	
		}
		else {
			cout << "Impossible" << endl;
		}
	}
}
