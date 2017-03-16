#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

char table[4][4];

int dy[] = {1, 0, 1, 1};
int dx[] = {0, 1, 1, -1};

int win(char c)
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++) {
			for (int dir = 0; dir < 4; dir++) {
				int y2 = y + 3 * dy[dir];
				int x2 = x + 3 * dx[dir];
				if (0 <= y2 && 0 <= x2 && y2 < 4 && x2 < 4) {
					int nc = 0, nt = 0;
					for (int i = 0; i < 4; i++) {
						int y2 = y + i * dy[dir];
						int x2 = x + i * dx[dir];
						if (table[y2][x2] == c)
							nc ++;
						if (table[y2][x2] == 'T')
							nt ++;

					}
					if (nc + nt == 4)
						return 1;
				}
			}
		}

	return 0;
}

int main(int argc, char ** argv)
{
	int ntest;

	scanf("%d", &ntest);
	
	for (int t = 0; t < ntest; t++) {
		int nfill = 0;

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++) {
				scanf(" %c", &table[y][x]);
				nfill += (table[y][x] != '.');
			}

		printf("Case #%d: ", t+1);

		if (win('X'))
			printf("X won\n");
		else if (win('O'))
			printf("O won\n");
		else if (nfill < 16)
			printf("Game has not completed\n");
		else
			printf("Draw\n");
	}

	return 0;
}
