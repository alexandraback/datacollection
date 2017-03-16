#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

int m[4][4];
int n, tx, ty, t;
string s;
bool hasDot;

int sx[] = {0, 0, 0, 0, 0, 1, 2, 3, 0, 3};
int sy[] = {0, 1, 2, 3, 0, 0, 0, 0, 0, 0};
int dx[] = {1, 0, 1, -1};
int dy[] = {0, 1, 1, 1};
int won() {
	int x, y, c;
	for (int i = 0; i < 10; i++) {	// starting point
		for (int j = 0; j < 4; j++) {	// four checking line
			x = sx[i];
			y = sy[i];
			c = m[x][y];

			for (int k = 0; k < 3; k++) {	// check
				x += dx[j];
				y += dy[j];
				if (x >= 0 && y >= 0 && x < 4 && y < 4)
					c += m[x][y];
			}

			if (c == 4 || c == -4)
				return c / 4;
		}
	}
	return 0;
}

void pw(int c) {
	printf("%c won\n", c == 1? 'X' : 'O');
}

void pd() {
	if (!hasDot)
		printf("Draw\n");
	else
		printf("Game has not completed\n");
}

int main() {
	
	scanf("%d", &n);
	getline(cin, s);
	
	for (int C = 1; C <= n; C++) {
		tx = ty = -1;
		hasDot = 0;
		for (int i = 0; i < 4; i++) {
			getline(cin, s);
			for (int j = 0; j < 4; j++)
				if (s[j] == 'X')
					m[i][j] = 1;
				else if (s[j] == 'T') {
					m[i][j] = 1;
					tx = i;
					ty = j;
				}
				else if (s[j] == 'O')
					m[i][j] = -1;
				else {
					m[i][j] = 0;
					hasDot = 1;
				}
		}
		getline(cin, s);

		printf("Case #%d: ", C);
		if ((t = won())) {
			pw(t);
			continue;
		}
		if (tx != -1 && ty != -1) {
			m[tx][ty] = -1;
			if ((t = won()))
				pw(t);
			else
				pd();
		}
		else
			pd();
	}

	return 0;
}
