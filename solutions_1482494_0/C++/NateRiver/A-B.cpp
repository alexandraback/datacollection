//============================================================================
// Name        : A-A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
int n;
int a[11], b[11];
int level[11];

int work(int dep, int star, int count) {
	int mystate[11];
	for (int i = 0; i < n; ++i)
		mystate[i] = level[i];
	bool find = true;
	while (find) {
		find = false;
		for (int i = 0; i < n; ++i) {
			if (level[i] < 2 && star >= b[i]) {
				star += 2 - level[i];
				level[i] = 2;
				find = true;
				count++;
			}
		}
	}
	/*printf("%d %d %d\n", dep, star, count);
	for (int i = 0; i < n; ++i)
		printf("%d ", level[i]);
	printf("\n");*/
	if (star == 2 * n) {
		return count;
	}
	find = false;
	int best = 3 * n;
	for (int i = 0; i < n; ++i) {
		if (level[i] == 0 && star >= a[i]) {
			find = true;
			level[i] = 1;
			int t = work(dep + 1, star + 1, count + 1);
			if (best > t)
				best = t;
			level[i] = 0;
		}
	}
	for (int i = 0; i < n; ++i)
		level[i] = mystate[i];
	return best;

}

int main() {
	int nc, c;
	freopen("/home/panda/codejam/in", "r", stdin);
	freopen("/home/panda/codejam/out2", "w", stdout);
	scanf("%d", &nc);
	for (c = 1; c <= nc; ++c) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &a[i], &b[i]);
		for (int i = 0; i < n; ++i)
			level[i] = 0;
		int ans = work(0, 0, 0);
		if (ans < 3 * n)
			printf("Case #%d: %d\n", c, ans);
		else
			printf("Case #%d: Too Bad\n", c);
	}
	return 0;
}
