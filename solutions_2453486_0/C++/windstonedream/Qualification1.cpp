#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
	int cas, c = 1;
	char d[4][5];
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	for(scanf("%d ", &cas); cas; --cas, ++ c) {
		printf("Case #%d: ", c);
		for(int i = 0; i < 4; i ++) {
			scanf("%s", d[i]);
		}
		bool resX = false, res;
		for(int i = 0; i <  4; ++ i) {
			res = true;
			for (int j = 0; j < 4; ++ j) {
				if (d[i][j] != 'X' && d[i][j] != 'T') {
					res = false;
				}
			}
			if (res) {
				resX = true;
				break;
			}
		}
		for(int i = 0; i <  4; ++ i) {
			res = true;
			for (int j = 0; j < 4; ++ j) {
				if (d[j][i] != 'X' && d[j][i] != 'T') {
					res = false;
				}
			}
			if (res) {
				resX = true;
				break;
			}
		}
		res = true;
		for(int i = 0; i < 4; ++ i) {
			if (d[i][i] != 'X' && d[i][i] != 'T') {
				res = false;
			}
		}
		if (res)	resX = true;
		res = true;
		for(int i = 0; i < 4; ++ i) {
			if (d[i][3 - i] != 'X' && d[i][3 - i] != 'T') {
				res = false;
			}
		}
		if (res)	resX = true;
		if (resX) {
			printf("X won\n");
			continue;
		}


		bool resO = false;
		for(int i = 0; i <  4; ++ i) {
			res = true;
			for (int j = 0; j < 4; ++ j) {
				if (d[i][j] != 'O' && d[i][j] != 'T') {
					res = false;
				}
			}
			if (res) {
				resO = true;
				break;
			}
		}
		for(int i = 0; i <  4; ++ i) {
			res = true;
			for (int j = 0; j < 4; ++ j) {
				if (d[j][i] != 'O' && d[j][i] != 'T') {
					res = false;
				}
			}
			if (res) {
				resO = true;
				break;
			}
		}
		res = true;
		for(int i = 0; i < 4; ++ i) {
			if (d[i][i] != 'O' && d[i][i] != 'T') {
				res = false;
			}
		}
		if (res)	resO = true;
		res = true;
		for(int i = 0; i < 4; ++ i) {
			if (d[i][3 - i] != 'O' && d[i][3 - i] != 'T') {
				res = false;
			}
		}
		if (res)	resO = true;
		if (resO) {
			printf("O won\n");
			continue;
		}

		if (!resX && !resO) {
			bool fin = true;
			for (int i = 0; i < 4; ++ i) {
				for (int j = 0; j < 4; ++ j) {
					if (d[i][j] == '.')	fin = false;
				}
			}
			if (fin) {
				printf("Draw\n");
			} else {
				printf("Game has not completed\n");
			}
		}
	}
	return 0;
}