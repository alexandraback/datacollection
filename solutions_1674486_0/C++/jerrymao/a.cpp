#include <cstdio>

#define CLASSES 50
#define MAXM    10

int c[CLASSES][MAXM];
int csize[CLASSES];
bool seen[CLASSES];
int n;
bool temp;

bool dfs2(const int at, const int to)
{
	if (at == to)
	{
		if (temp)
			return true;
		temp = true;
		return false;
	}
	seen[at] = true;
	for (int i = 0;i < csize[at];i++) if (!seen[c[at][i]]) if (dfs2(c[at][i], to))
		return true;
	seen[at] = false;
	return false;
}

bool dfs(const int at, const int to)
{
	if (at == to)
		return true;
	seen[at] = true;
	for (int i = 0;i < csize[at];i++) if (!seen[c[at][i]]) if (dfs(c[at][i], to))
		return true;
	seen[at] = false;
	return false;
}

bool solve()
{
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) if (i != j)
	{
		if (!dfs(i, j))
			continue;
		temp = false;
		for (int k = 0;k < n;k++)
			seen[k] = false;
		if (dfs2(i, j))
			return true;
		for (int k = 0;k < n;k++)
			seen[k] = false;
	}
	return false;
}

int main()
{
	FILE* in = fopen("input1.txt", "r");
#ifndef DEBUG
	freopen("output1.txt", "w", stdout);
#endif
	int t;
	fscanf(in, "%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fscanf(in, "%d", &n);
		for (int i = 0;i < n;i++)
		{
			fscanf(in, "%d", &csize[i]);
			for (int j = 0;j < csize[i];j++)
			{
				int k; fscanf(in, "%d", &k);
				c[i][j] = --k;
			}
		}
		if (solve())
			printf("Case #%d: Yes\n", _);
		else
			printf("Case #%d: No\n", _);
	}
	fclose(in);
	return 0;
}

