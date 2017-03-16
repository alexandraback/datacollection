#include <iostream>
#include <algorithm>

using namespace std;

const int maxR = 50 + 10;

char board[maxR][maxR];
int R, C, K;

bool fill() {
	int num_empty = R*C - K;
	if (num_empty == 1) {
		for (int i=0; i<R; ++i)
			for (int j=0; j<C; ++j)
				board[i][j] = '*';
		return true;
	}
	if (R == 1) {
		for (int i=0; i<K; ++i)
			board[0][i] = '*';
		return true;
	} else if (R == 2) {
		if (num_empty == 2 || K % 2)
			return false;
		for (int i=0; i<K/2; ++i)
			board[0][i] = board[1][i] = '*';
		return true;
	} else if (R == 3) {
		if (num_empty == 2 || num_empty == 3 || num_empty == 5 || num_empty == 7)
			return false;
		for (int i=0; i<K/3; ++i)
			board[0][i] = board[1][i] = board[2][i] = '*';
		if (K % 3 == 1 || K % 3 == 2)
			board[0][K/3] = '*';
		if (K % 3 == 2) {
			if (K == R*C-1)
				board[1][K/3] = '*';
			else
				board[0][K/3 + 1] = '*';
		}
		return true;
	} else {
		int num_empty = R*C - K;
		if (num_empty == 2 || num_empty == 3 || num_empty == 5 || num_empty == 7)
			return false;
		if (K <= R * (C-3)) {
			for (int col=0; col<K/R; ++col)
				for (int i=0; i<R; ++i)
					board[i][col] = '*';
			for (int i=0; i<K%R; ++i)
				board[i][K/R] = '*';
			if (K%R == R-1) {
				board[R-2][K/R] = '.';
				board[0][K/R+1] = '*';
			}
		} else {
			for (int col = 0; col<C-3; ++col)
				for (int i=0; i<R; ++i)
					board[i][col] = '*';
			int orig_K = K;
			K -= R * (C-3);
			for (int i=0; i<K/3; ++i)
				board[i][C-3] = board[i][C-2] = board[i][C-1] = '*';
			if (K%3 == 1 || K%3 == 2) 
				board[K/3][C-3] = '*';
			if (K%3 == 2) {
				if (num_empty == 1)
					board[K/3][C-2] = '*';
				else
					board[K/3+1][C-3] = '*';
			}
			K = orig_K;
		}
		return true;
	}

}

void print_wrong() {
	cout << "something wrong" << endl;
	cout << R << C << K << endl;
	for (int ii=0; ii<R; ++ii) {
		for (int jj=0; jj<C; ++jj)
			cout << board[ii][jj];
		cout << endl;
	}
}

void check() {
	int count = 0;
	for (int i=0; i<R; ++i)
		for (int j=0; j<C; ++j)
			if (board[i][j] == '*')
				count ++;
	if (count != K) {
		print_wrong();
		return;
	}
	int temp[maxR][maxR];
	int moves[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	for (int i=0; i<R; ++i)
		for (int j=0; j<C; ++j)
			temp[i][j] = 0;
	for (int i=0; i<R; ++i)
		for (int j=0; j<C; ++j)
			if (board[i][j] == '*') {
				temp[i][j] = 1;
			}
	for (int i=0; i<R; ++i)
		for (int j=0; j<C; ++j)
			if (temp[i][j] == 1) {
				for (int k = 0; k<8; ++k) {
					int new_i = i + moves[k][0];
					int new_j = j + moves[k][1];
					if (new_i >=0 && new_i < R && new_j>=0 && new_j < C && temp[new_i][new_j] != 1)
						temp[new_i][new_j] = 2;
				}
			}
	for (int i=0; i<R; ++i)
		for (int j=0; j<C; ++j)
			if (temp[i][j] == 2) {
				bool flag = false;
				for (int k = 0; k<8; ++k) {
					int new_i = i + moves[k][0];
					int new_j = j + moves[k][1];
					if (new_i >=0 && new_i < R && new_j>=0 && new_j < C && temp[new_i][new_j] == 0) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					print_wrong();
					return;
				}
			}
}

int main() {
	int T;
	cin >> T;
	for (int tt=1; tt<=T; ++tt) {
		cin >> R >> C >> K;
		bool isTranspose = false;
		if (R > C) {
			swap(R, C);
			isTranspose = true;
		}

		for (int i=0; i<R; ++i)
			for (int j=0; j<C; ++j)
				board[i][j] = '.';
		cout << "Case #" << tt << ":" << endl;
		if (fill()) {
//			check();
			board[R-1][C-1] = 'c';
			if (!isTranspose)
				for (int i=0; i<R; ++i) {
					for (int j=0; j<C; ++j)
						cout << board[i][j];
					cout << endl;
				}
			else
				for (int i=0; i<C; ++i) {
					for (int j=0; j<R; ++j)
						cout << board[j][i];
					cout << endl;
				}
		} else {
			cout << "Impossible" << endl;
		}
	}
}
