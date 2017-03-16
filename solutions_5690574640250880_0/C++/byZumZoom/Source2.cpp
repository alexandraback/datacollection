#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <string>

using namespace std;

int n, m;
char M[50][50];

int GO[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};

bool check(int i, int j, int k)
{
	return i + GO[k][0] >= 0 && i + GO[k][0] < n && j + GO[k][1] >= 0 && j + GO[k][1] < m;
}

void dfs(int i, int j)
{
	M[i][j] = '!';
	bool has_mines = false;
	for(int k = 0; k < 8; ++k)
		if(check(i, j, k) && M[i + GO[k][0]][j + GO[k][1]] == '*')
			has_mines = true;
	if(!has_mines)
		for(int k = 0; k < 8; ++k)
			if(check(i, j, k) && M[i + GO[k][0]][j + GO[k][1]] == '.')
				dfs(i + GO[k][0], j + GO[k][1]);
}

void reset_M(vector < vector < char > > const & old)
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			M[i][j] = old[i][j];
}

bool check_integrity(int x, int y)
{
	dfs(x, y);
	bool ok = true;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(M[i][j] == '.')
				ok = false;
	return ok;
}

bool checker()
{
	vector < vector < char > > saveM(n, vector<char>(m));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			saveM[i][j] = M[i][j];

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(M[i][j] == '.')
			{
				M[i][j] = 'c';
				bool ok = check_integrity(i, j);
				reset_M(saveM);
				if(ok)
				{
					M[i][j] = 'c';
					return true;
				}
			}

	return false;
}

bool gen(int i, int j, int k)
{
	if(i == n)
		return k == 0 && checker();

	if(k > 0)
	{
		M[i][j] = '*';
		if(gen(i + (j + 1) / m, (j + 1) % m, k - 1))
			return true;
	}
	M[i][j] = '.';
	return gen(i + (j + 1) / m, (j + 1) % m, k);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		int k;
		cin >> n >> m >> k;
		cout << "Case #" << t << ":" << endl;
		if(gen(0, 0, k))
		{
			for(int i = 0; i < n; ++i)
			{
				for(int j = 0; j < m; ++j)
					cout << M[i][j];
				cout << endl;
			}
		}
		else
		{
			cout << "Impossible" << endl;
		}
	}

	return 0;
}