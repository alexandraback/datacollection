#include <stdio.h>

int max(int a, int b){return a > b ? a : b;}

int T, R, C, W;
int d[30][30];

int dfs(int i, int j){
	if(i <= 0 || j <= 0) return 0;
	else if(i == j) return i;
	else if(d[i][j] > 0) return d[i][j];
	else{
		d[i][j] = 0;
		d[i][j] = max(d[i][j], dfs(i-j, j)+1);
		if(2*j-1 >= i) d[i][j] = max(d[i][j], dfs(i-1, j-1)+1);
		else d[i][j] = max(d[i][j], dfs(2*j-1, j-1));
		return d[i][j];
	}
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; z ++){
		scanf("%d %d %d", &R, &C, &W);
		for(int i = 0 ; i < 30 ; i ++){
			for(int j = 0 ; j < 30 ; j ++){
				d[i][j] = 0;
			}
		}
		printf("Case #%d: %d\n", z, dfs(C, W)+C/W*(R-1));
	}
	return 0;
}
