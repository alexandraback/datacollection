#include<stdio.h>
#include<string.h>

int T, K, L, S, pos, cnt, i, j, k,M;
char D[1000000][10], A[10],key[10],target[10];

void dfs(int x, int p){
	if (x == p){
		strcpy(D[pos], A);
		pos++;
		return;
	}
	int i;
	for (i = 0; i < K; i++){
		A[x] = key[i];
		dfs(x + 1, p);
	}
}

int main(){
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		scanf("%d %d %d ", &K, &L, &S);
		scanf("%s ", key);
		scanf("%s", target);
		pos = 0;
		cnt = 0;
		M = 0;
		dfs(0, S);
		for (i = 0; i < pos; i++){
			int C = 0;
			for (j = 0; j < S-L+1; j++){
				if (D[i][j] == target[0]){
					bool flag = true;
					for (k = 1; k < L; k++){
						if (D[i][j + k] != target[k]){
							flag = false;
							break;
						}
					}
					if (flag){
						cnt++;
						C++;
						if (C>M)M = C;
					}
				}
			}
		}
		double ans = (double)cnt / (double)pos;
		printf("Case #%d: %.9lf\n", t, (double)M-ans);
	}
	return 0;
}