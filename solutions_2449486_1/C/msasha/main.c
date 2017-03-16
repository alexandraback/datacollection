#include <stdio.h>
#include <strings.h>

#define MAXN 100
#define MAXM 100

int max(int v1, int v2){
	return v1 > v2 ? v1 : v2;
}

int isPossibleLawn(int lawn[MAXN][MAXM], int n, int m){
	int maxRow[MAXM];
	int maxCol[MAXN];
	
	bzero(maxRow, sizeof(maxRow));
	bzero(maxCol, sizeof(maxCol));
	
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			maxRow[i] = max(maxRow[i], lawn[i][j]);
			maxCol[j] = max(maxCol[j], lawn[i][j]);
		}
	}
	
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			if ((lawn[i][j] < maxRow[i]) && (lawn[i][j] < maxCol[j]))
				return 0;
		}
	}
	
	return 1;
		
}

int main(void){
	int t, caseNumber;
	scanf("%d\n", &t);
	
	for (caseNumber = 1; caseNumber <= t; caseNumber++){
		int n, m, i, j;
		int lawn[MAXN][MAXM];
		
		scanf("%d %d\n", &n, &m);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%d", &lawn[i][j]);
		
		printf("Case #%d: %s\n", caseNumber, isPossibleLawn(lawn, n, m) ? "YES" : "NO");
	}
	
	return 0;
}