#include<stdio.h>
#include<stdlib.h>

char table[50][50];

int main() {
	int T, nm= 1;
	scanf("%d", &T);
	int i, j, k;
	while (T--) {
		int r, c, x;
		scanf("%d%d%d", &r, &c, &x);
		for (i=0;i<r;i++) {
			for (j=0;j<c;j++) table[i][j]= '*';
		}
		int dot= r*c - x, ct= 0;
		int pass= 1;
		if (dot==1) {
			printf("Case #%d:\n", nm++);
			for (i=0;i<r;i++) {
				for (j=0;j<c;j++) {
					if (i==0 && j==0) printf("c");
					else printf("*");
				}
				printf("\n");
			}
			continue;
		}
		if ((r>1 && c>1) && r*c < x+4) pass= 0;
		else if (((r==2 && c>2) || (c==2 && r>2)) && dot%2) pass= 0;
		else if ((r>2 && c>2) && (dot==5 || dot==7)) pass= 0;
		table[0][0]= 'c';
		if (r==1) {
			for (i=1;i<dot;i++) table[0][i]= '.';
		}
		else if (c==1) {
			for (i=1;i<dot;i++) table[i][0]= '.';
		}
		else if (pass) {
			int odd= dot%2;
			int first_even= dot/2;
			
			for (i=0;i<r;i++) {
				for (j=0;j<c;j++) {
					if (i==0 && j==0) {
						table[i][j]= 'c';
						ct++;
					}
					else if (i<2 && j<2) {
						table[i][j]= '.';
						ct++;
					}
					else if (i<2) {
						if (first_even > c) {
							table[i][j]= '.';
							ct++;
						}
						else {
							if (odd) {
								if (j < first_even-1) {
									table[i][j]= '.';
									ct++;
								}
							}
							else {
								if (j < first_even) {
									table[i][j]= '.';
									ct++;
								}
							}

						}
					}
					else {
						if (ct < dot) {
							if (!(dot-ct==2 && j==c-1)) {
								table[i][j]= '.';
								ct++;
							}
						}
						else break;
					}
				}
			}
		}
		printf("Case #%d:\n", nm++);
		if (!pass) printf("Impossible\n");
		else {
			for (i=0;i<r;i++) {
				for (j=0;j<c;j++) printf("%c", table[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}
