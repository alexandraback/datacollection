//============================================================================
// Name        : A-A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
int a[1100], b[1100];
int level[1100];

int main() {
	int nc, c, n;
	freopen("/home/panda/codejam/in", "r", stdin);
	freopen("/home/panda/codejam/out", "w", stdout);
	scanf("%d", &nc);
	for (c = 1; c <= nc; ++c) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &a[i], &b[i]);
		for (int i = 0; i < n; ++i)
			level[i] = 0;
		int star = 0, count = 0;
		while (true) {
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
			if (star == 2 * n)
				break;
			find = false;
			int big = -1;
			int tag;
			for (int i = 0; i < n; ++i) {
				if (level[i] == 0 && star >= a[i]) {
					find = true;
					if (b[i] > big) {
						big = b[i];
						tag = i;
					}
				}
			}
			if (!find)
				break;
			else {
				level[tag] = 1;
				star++;
				count++;
			}
		}
		if (star == 2 * n)
			printf("Case #%d: %d\n", c, count);
		else
			printf("Case #%d: Too Bad\n", c);
	}
	return 0;
}
