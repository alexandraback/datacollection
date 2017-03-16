#include <stdio.h>

#define MAX_CLASSES	1000
#define MAX_EDGES	10

int map[MAX_CLASSES][MAX_CLASSES];
int mm[MAX_CLASSES][MAX_EDGES+1];
int stack[MAX_CLASSES*MAX_EDGES];

int main(void) {
	int t, n;
	int sentinel, sidx, flag;
	int c, i, j;
	FILE *out=fopen("A-small.out", "w");

	scanf("%d", &t);
	for(c=1; c<=t; c++) {
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++)
				map[i][j] = 0;
		}

		for(i=0; i<n; i++) {
			scanf("%d", &mm[i][0]);
			for(j=1; j<=mm[i][0]; j++)
				scanf("%d", &mm[i][j]);
		}

		flag = 0;
		for(i=0; !flag && i<n; i++) {
			sidx = 0;
			stack[sidx++] = i;
			while(!flag && sidx--) {
				sentinel = stack[sidx];
				for(j=1; j<=mm[sentinel][0]; j++) {
					if(map[i][mm[sentinel][j]-1]) {
						flag = 1;
						break;
					}
					map[i][mm[sentinel][j]-1] = 1;
					stack[sidx++] = mm[sentinel][j] - 1;
				}
			}
		}

		printf("Case #%d: %s\n", c, (flag ? "Yes" : "No"));
	}

	fclose(out);

	return 0;
}