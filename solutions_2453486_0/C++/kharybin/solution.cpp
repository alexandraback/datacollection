#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int n = 4;

string g[n];
int dy[4] = {0, 1, 1, 1};
int dx[4] = {1, 0, 1, -1};
char owner;
bool free_cell;

bool check(int i, int j)
{
	return i >= 0 && j >= 0 && i < n && j < n;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int testCaseCount;
	cin >> testCaseCount;
	for(int testCaseNumber = 1; testCaseNumber <= testCaseCount; ++testCaseNumber)
	{
		for (int i = 0; i < n; ++i)
			cin >> g[i];
		owner = '#';
		free_cell = false;
		for (int i = 0; owner == '#' && i < n; ++i)
		{
			for (int j = 0; owner == '#' && j < n; ++j)
			{
				if (g[i][j] == '.')
					free_cell = true;
				for (int q = 0; owner == '#' && q < 4; ++q)
				{
					if (!check(i + (n-1)*dy[q], j + (n-1)*dx[q]))
						continue;
					owner = '*';
					for (int k = 0; owner != '#' && k < n; ++k)
					{
						int ni = i + k * dy[q];
						int nj = j + k * dx[q];
						if (g[ni][nj] == '.')
							owner = '#';
						else if (g[ni][nj] == 'T')
							continue;
						else if (owner == '*')
							owner = g[ni][nj];
						else if (g[ni][nj] != owner)
							owner = '#';
					}
				}
			}
		}
		cout << "Case #" << testCaseNumber << ": ";
		if (owner != '#')
			cout << owner << " won";
		else if (free_cell)
			cout << "Game has not completed";
		else
			cout << "Draw";
		cout << endl;
	}
	return 0;
}