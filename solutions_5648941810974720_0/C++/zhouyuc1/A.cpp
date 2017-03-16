#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int mat[26][11];

void init_matrix()
{
	memset(mat, 0, sizeof(mat));
	// ZERO
	mat['Z'-'A'][0] = mat['E'-'A'][0] = mat['R'-'A'][0] = mat['O'-'A'][0] = 1;
	// ONE
	mat['O'-'A'][1] = mat['N'-'A'][1] = mat['E'-'A'][1] = 1;
	// TWO
	mat['T'-'A'][2] = mat['W'-'A'][2] = mat['O'-'A'][2] = 1;
	// THREE
	mat['T'-'A'][3] = mat['H'-'A'][3] = mat['R'-'A'][3] = 1;
	mat['E'-'A'][3] = 2;
	// FOUR
	mat['F'-'A'][4] = mat['O'-'A'][4] = mat['U'-'A'][4] = mat['R'-'A'][4] = 1;
	// FIVE
	mat['F'-'A'][5] = mat['I'-'A'][5] = mat['V'-'A'][5] = mat['E'-'A'][5] = 1;
	// SIX
	mat['S'-'A'][6] = mat['I'-'A'][6] = mat['X'-'A'][6] = 1;
	// SEVEN
	mat['S'-'A'][7] = mat['V'-'A'][7] = mat['N'-'A'][7] = 1;
	mat['E'-'A'][7] = 2;
	// EIGHT
	mat['E'-'A'][8] = mat['I'-'A'][8] = mat['G'-'A'][8] = mat['H'-'A'][8] = mat['T'-'A'][8] = 1;
	// NINE
	mat['I'-'A'][9] = mat['E'-'A'][9] = 1;
	mat['N'-'A'][9] = 2;
}

void swap_rows(int u, int v)
{
	if (u == v)
		return;
	for (int i = 0; i < 11; ++i)
	{
		int tmp;
		tmp = mat[u][i];
		mat[u][i] = mat[v][i];
		mat[v][i] = tmp;
	}
}

void rev_row(int u)
{
	for (int i = 0; i < 11; ++i)
		mat[u][i] = -mat[u][i];
}

void sub_row(int k, int v) // k -> v
{
	int fact = mat[v][k];
	for (int i = 0; i < 11; ++i)
		mat[v][i] -= mat[k][i] * fact;
}

void print_matrix()
{
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 11; ++j)
			printf("%3d", mat[i][j]);
		printf("\n");
	}
}

void mod_matrix()
{
	int i, j, k;
	for (k = 0; k < 10; ++k)
	{
		for (i = k; i < 26; ++i)
		{
			if (mat[i][k] == 1)
			{
				swap_rows(k, i);
				break;
			}
			else if (mat[i][k] == -1)
			{
				rev_row(i);
				swap_rows(k, i);
				break;
			}
		}
		for (i = k+1; i < 26; ++i)
			if (mat[i][k] != 0)
				sub_row(k, i);
	}
	for (k = 9; k >= 0; --k)
	{
		for (i = k-1; i >= 0; --i)
			if (mat[i][k] != 0)
				sub_row(k, i);
	}
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T = 0;
	scanf("%d", &T);

	char s[3000];

	for (int tcase = 1; tcase <= T; ++tcase)
	{
		init_matrix();
		scanf("%s", s);
		for (int i = 0; s[i] != 0; ++i)
			++mat[s[i] - 'A'][10];
		mod_matrix();
		printf("Case #%d: ", tcase);
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < mat[i][10]; ++j)
				printf("%d", i);
		printf("\n");
	}

	return 0;
}






