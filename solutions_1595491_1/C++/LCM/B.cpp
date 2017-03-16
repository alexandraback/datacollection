#include<cstdio>

int a, b, c, d, e, re[110];

int main() {
	scanf("%d", &a);
	for (int i = 0 ; i < a ; i++) {
		scanf("%d %d %d", &b, &c, &d);
		for (int j = 0 ; j < b ; j++) {
			scanf("%d", &e);
			if (e == 0 && c) continue;
			if(e >= 3 * d - 2) re[i]++;
			else if (c && e >= 3 * d - 4) {
				c--;
				re[i]++;
			}
		}
	}
	for (int i = 0 ; i < a ; i++) printf("Case #%d: %d\n", i + 1, re[i]);
	scanf("\n");
	return 0;
}
/*
4
3 1 5 15 13 11
3 0 8 23 22 21
2 1 1 8 0
6 2 8 29 20 8 18 18 21
*/
