#include <stdio.h>
#include <algorithm>
using namespace std;
const int init_mat[4][4] = {
	{0, 1, 2, 3},
	{1, 4, 3, 6},
	{2, 7, 4, 1},
	{3, 2, 5, 4}};
int mat[8][8];
int t, n, ord[8], rev[8], rep[8];
long long m;
char s[10001];
bool Work()
{
	int mul = 0, tot_mul = 0;
	for(int i = 0; i < 8; i++)
		ord[i] = rev[i] = rep[i] = -1;
	ord[0] = rev[0] = rep[0] = 0;
	for(int i = 0; i < n; i++)
	{
		mul = mat[mul][s[i]];
		if(ord[mul] == -1)
			ord[mul] = i + 1;
	}
	long long tmp = m, ansi = m * n, ansk = m * n;
	for(int j = mul; tmp; tmp >>= 1)
	{
		if(tmp & 1)
			tot_mul = mat[tot_mul][j];
		j = mat[j][j];
	}
	if(tot_mul != mat[mat[1][2]][3])
		return false;
	for(int i = n - 1, j = 0; i >= 0; i--)
	{
		j = mat[s[i]][j];
		if(rev[j] == -1)
			rev[j] = n - i;
	}
	for(int i = 1, j = 0; i <= 100 && i <= m; i++)
	{
		j = mat[j][mul];
		if(rep[j] == -1)
			rep[j] = i;
	}
	for(int i = 0; i < 8; i++)
	{
		if(rep[i] == -1)
			continue;
		for(int j = 0; j < 8; j++)
		{
			if(ord[j] >= 0 && mat[i][j] == 1)
				ansi = min(ansi, (long long)rep[i] * n + ord[j]);
		}
		for(int j = 0; j < 8; j++)
		{
			if(rev[j] >= 0 && mat[j][i] == 3)
				ansk = min(ansk, (long long)rep[i] * n + rev[j]);
		}
	}
	return ansi + ansk <= m * n;
}
int main()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
			mat[i][j] = init_mat[i & 3][j & 3] ^ (i & 4) ^ (j & 4);
	}
	FILE *fin = fopen("C.in", "r"), *fout = fopen("C.out", "w");
	fscanf(fin, "%d", &t);
	for(int t_id = 1; t_id <= t; t_id++)
	{
		fscanf(fin, "%d%d%s", &n, &m, s);
		for(int i = 0; i < n; i++)
			s[i] -= 'h';
		fprintf(fout, "Case #%d: %s\n", t_id, Work() ? "Yes" : "No");
	}
	fclose(fin), fclose(fout);
	return 0;
}
