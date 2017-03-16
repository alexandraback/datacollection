#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int BOARD = 50;
const int NINF = -100000000;

bool chess_board[BOARD][BOARD];
bool vis[BOARD][BOARD];
int record[BOARD][BOARD];

int pow(int a, int b) {
	if (b == 0) {
		return 1;
	}
	return a * pow(a, b - 1);
}

void init_vis(){
	for (int i = 0; i < BOARD; i++) {
		for (int j = 0; j < BOARD; j++) {
			vis[i][j] = false;
		}
	}
}


// will return whether it's enclosed
int dfs(int x, int y, int size_x, int size_y){
	if (vis[x][y]) {
		return 0;
	}
	if ((x == 0 || x == size_x - 1 || y == 0 || y == size_y - 1) && chess_board[x][y] == 0) {
		return NINF;
	}
	if (chess_board[x][y] == 1){
		vis[x][y] = true;
		return 0;
	}

	vis[x][y] = true;

	int n1 = dfs(x + 1, y, size_x, size_y);
	int n2 = dfs(x - 1, y, size_x, size_y);
	int n3 = dfs(x, y + 1, size_x, size_y);
	int n4 = dfs(x, y - 1, size_x, size_y);
	return n1 + n2 + n3 + n4 + 1;
}

int solution(int n, int m, int k){

	int min_chess = n * m;
	for (int perm = 0; perm < pow(2, n * m); perm++) {
		// cout << "permutation: " << perm << endl;
		int chess = 0;
		for (int j = 0; j < n * m; j++) {
			if ((1 << j) & perm) {
				chess++;
				chess_board[j % n][j / n] = 1;
			} else {
				chess_board[j % n][j / n] = 0;
			}
		}
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < m; j++) {
		// 		cout << chess_board[i][j];
		// 	}
		// 	cout << endl;
		// }
		// this permutation computed

		// cout << "chess: " << chess << endl;
		int enclosed = 0;
		init_vis();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(!vis[i][j]){
					int s = dfs(i, j, n, m);
					if (s > 0) {
						enclosed += s;
					}
				}
			}
		}
		enclosed += chess;
		// cout << "enclosed: " << enclosed << endl;
		if (enclosed >= k && chess < min_chess) {
			min_chess = chess;
		}
	}
	return min_chess;
}

int main(int argc, const char *argv[]){


	int times;
	cin >> times;
	for (int ti = 1; ti <= times; ti++) {
		int n, m, k;
		cin >> n >> m >> k;
		printf("Case #%d: %d\n", ti, solution(n, m, k));
	}
	
	return 0;
}

