#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAXN 20
#define MAXM MAXN * MAXN * 2
int n, m;

string zipcode[MAXN];
int visit[MAXN];

int mat[MAXN][MAXN];
int arr[MAXN];

string global;

bool judge(int n, int arr[MAXN])
{
	
	int i, j;
	// for (i = 0; i < n; i++) printf("%d ", arr[i]); printf("\n");
	bool flag = false;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
			if (mat[arr[i]][arr[j]])
			{
				flag = true;
				break;
			}
		if (flag == false) return false;
	}
	return true;
}

int main()
{
	int t, cas, i, j;
	int a, b;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		memset(mat, 0, sizeof mat);
		memset(visit, 0, sizeof visit);
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++) cin >> zipcode[i];
		while (m--)
		{
			scanf("%d%d", &a, &b);
			mat[a][b] = mat[b][a] = 1;
		}
		// for (i = 1; i <= n; i++)
		// {
			// for (j = 1; j <= n; j++) printf("%d ", mat[i][j]);
			// printf("\n");
		// }
		for (i = 0; i < n; i++) arr[i] = i + 1;
		global = string("");
		for (i = 0; i < n; i++) global += "99999";
		do
		{
			if (judge(n, arr))
			{
				string tmp = string("");
				for (i = 0; i < n; i++) tmp += zipcode[arr[i]];
				if (tmp < global) global = tmp;
			}
		} while (next_permutation(arr, arr + n));
		cout << "Case #" << cas << ": " << global << endl;
	}
	return 0;
}
