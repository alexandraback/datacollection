#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

int comp(const void *a, const void *b) {
	return (*(int *)a) - (*(int *)b);
}

int analyze(int a, int b, int c, int d) {
	int cx = (a == 'X') + (b == 'X') + (c == 'X') + (d == 'X'), 
		co = (a == 'O') + (b == 'O') + (c == 'O') + (d == 'O'),
		cz = (a == '.') + (b == '.') + (c == '.') + (d == '.'),
		ct = (a == 'T') + (b == 'T') + (c == 'T') + (d == 'T');
	int res = (cz != 0);
	if (cx + ct == 4) 
		res |= 1 << 1;
	if (co + ct == 4)
		res |= 1 << 2; 
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	char a[5][5];
	scanf("%d", &n);
	for (int t = 1; t <= n; t++) {
		scanf("\n");
		printf("Case #%d: ", t);
		for (int i = 0; i < 4; i++)
			scanf("%s\n", a[i]);
		int res = 0;
		res |= analyze(a[0][0], a[0][1], a[0][2], a[0][3]);
		res |= analyze(a[1][0], a[1][1], a[1][2], a[1][3]);
		res |= analyze(a[2][0], a[2][1], a[2][2], a[2][3]);
		res |= analyze(a[3][0], a[3][1], a[3][2], a[3][3]);
		res |= analyze(a[0][0], a[1][0], a[2][0], a[3][0]);
		res |= analyze(a[0][1], a[1][1], a[2][1], a[3][1]);
		res |= analyze(a[0][2], a[1][2], a[2][2], a[3][2]);
		res |= analyze(a[0][3], a[1][3], a[2][3], a[3][3]);
		res |= analyze(a[0][0], a[1][1], a[2][2], a[3][3]);
		res |= analyze(a[0][3], a[1][2], a[2][1], a[3][0]);
		if (res & (1 << 1))
			printf("X won\n");
		else if (res & (1 << 2)) 
			printf("O won\n");
		else if (res & 1) 
			printf("Game has not completed\n"); 
		else
			printf("Draw\n"); 
		
	}
	return 0;
}