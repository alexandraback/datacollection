#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char input[1000000];

int main () {
	//freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.txt", "w", stdout);
	int i, j, k, l;
	int T, nm;
	scanf("%d", &T);
	for (nm=1;nm<=T;nm++) {
		int ans= 0;
		int n;
		scanf("%s %d", input, &n);
		//printf("input= %s, n= %d\n", input, n);
		int len= strlen(input);
		//printf("len= %d\n", len);
		int mn;
		for (i=0;i<len;i++) {
			for (j=i;j<len;j++) {
				k= 0;
				for (mn= i;mn<=j;mn++) {
					if (input[mn]=='a' || input[mn]=='e' || input[mn]=='i' || input[mn]=='o' || input[mn]=='u') {
						k= 0;
					}
					else {
						k++;
					}
					if (k>=n) {
						/*
						printf("k= %d\n", k);
						for (l=i;l<=j;l++) {
							printf("%c", input[l]);
						}
						printf("\n");
						*/
						ans++;
						break;
					}
				}
			}
		}

		printf("Case #%d: %d\n", nm, ans);
	}
	return 0;
}
