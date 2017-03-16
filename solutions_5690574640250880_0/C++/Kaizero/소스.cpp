#pragma warning(disable:4996)
#include<stdio.h>
char P[6][6][26][6][6];
bool M[6][6];
int C[6][6], chk[6][6][26];
bool v[6][6];
void DFS2(int n, int m, int a, int b){
	int i, j;
	v[a][b] = true;
	if (C[a][b])return;
	for (i = -1; i != 2; i++){
		for (j = -1; j != 2; j++){
			if (a + i < 0 || b + j < 0 || a + i >= n || b + j >= m)continue;
			if (!v[a + i][b + j])DFS2(n, m, a + i, b + j);
		}
	}
}
void DFS(int n, int m, int x, int y, int cnt){
	if (n == x){
		if (cnt == n*m)return;
		if (chk[n][m][cnt])return;
		int i, j, xx = -1, yy = -1;
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				v[i][j] = false;
				if (!C[i][j])xx = i, yy = j;
			}
		}
		if (cnt != n*m - 1){
			if (xx == -1)return;
			DFS2(n, m, xx, yy);
			for (i = 0; i < n; i++){
				for (j = 0; j < m; j++){
					if (!v[i][j] && !M[i][j])break;
				}
				if (j != m)break;
			}
		}
		else{
			for (i = 0; i < n; i++)for (j = 0; j < m; j++)if (!M[i][j])xx = i, yy = j;
		}
		if (i == n){
			chk[n][m][cnt] = true;
			for (i = 0; i < n; i++){
				for (j = 0; j < m; j++){
					if (M[i][j])P[n][m][cnt][i][j] = '*';
					else P[n][m][cnt][i][j] = '.';
				}
			}
			P[n][m][cnt][xx][yy] = 'c';
		}
		return;
	}
	M[x][y] = false;
	int nx = x, ny = y + 1;
	if (ny == m)nx++, ny = 0;
	DFS(n, m, nx, ny, cnt);
	M[x][y] = true;
	int i, j;
	for (i = x - 1; i <= x + 1; i++){
		for (j = y - 1; j <= y + 1; j++){
			if (i < 0 || j < 0 || i >= n || j >= m)continue;
			C[i][j]++;
		}
	}
	DFS(n, m, nx, ny, cnt + 1);
	for (i = x - 1; i <= x + 1; i++){
		for (j = y - 1; j <= y + 1; j++){
			if (i < 0 || j < 0 || i >= n || j >= m)continue;
			C[i][j]--;
		}
	}
	M[x][y] = false;
}
int main()
{
	int TC, T, R, C, cnt, i, j;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &TC);
	for (i = 1; i <= 5; i++){
		for (j = 1; j <= 5; j++){
			DFS(i, j, 0, 0, 0);
		}
	}
	for (T = 1; T <= TC; T++){
		printf("Case #%d:\n", T);
		scanf("%d%d%d", &R, &C, &cnt);
		if (!chk[R][C][cnt]){
			printf("Impossible\n");
		}
		else{
			for (i = 0; i < R; i++){
				printf("%s\n", P[R][C][cnt][i]);
			}
		}
	}
}