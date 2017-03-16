#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 55;

int col[N];
char map[N][N];
int r, c, m;

int dfs(int tot, int row, int last) {
	if (tot > r * c - m)
		return 0;
	if (tot == r * c - m)
		return 1;
	if (row > r)
		return 0;
	
	for(int i = last; i >= 2; i--) {
		col[row] = i;
		if (dfs(tot + i, row + 1, i))
			return 1;
	}
	col[row] = 0;
	return 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	while(test--) {
		static int testCount = 0;
		printf("Case #%d:\n", ++testCount);
		bool flag = false;
		scanf("%d %d %d", &r, &c, &m);
		for(int i = 1; i <= r; i++)
			col[i] = 0;
		if (r == 1) {
			col[1] = c - m;
			flag = true;
		} else if (c == 1) {
			for(int i = 1; i <= r - m; i++)
				col[i] = 1;
			flag = true;
		}
		
		if (m + 1 == r * c) {
			col[1] = 1;
			flag = true;
		}
		for(int first = c; flag == false && first >= 2; first--) {
			col[1] = col[2] = first;
			if (dfs(first * 2, 3, first)) {
				flag = true;
			}
		}
		if (!flag) {
			printf("Impossible\n");
		} else {
			for(int i = 1; i <= r; i++, printf("\n"))
				for(int j = 1; j <= c; j++) {
					if (i == 1 && j == 1) {
						printf("c");
					} else if (j <= col[i]) {
						printf(".");
					} else {
						printf("*");
					}
				}
		}
	}
	return 0;
}
