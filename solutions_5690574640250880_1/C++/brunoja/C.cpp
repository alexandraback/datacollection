#include <iostream>
#include <cstring>
using namespace std;

const int N = 50;
char mat[N][N];
int r, c, m;

bool solve()
{
	memset(mat, '.', sizeof mat);
	mat[r-1][c-1] = 'c';
	
	if (r == 1)
	{
		for (int j = 0; j < c && m; ++j)
			mat[0][j] = '*', --m;
		return true;
	}
	if (c == 1)
	{
		for (int i = 0; i < r && m; ++i)
			mat[i][0] = '*', --m;
		return true;
	}
	
	int all = r*c;
	all -= m;
	
	if (all == 1)
	{
		memset(mat, '*', sizeof mat);
		mat[r-1][c-1] = 'c';
		return true;
	}
	
	for (int i = 0; i < r-2 && m; ++i)
		for (int j = 0; j < c-2 && m; ++j)
			mat[i][j] = '*', --m;	
	
	int g = 0;
	if (m&1)
	{
		if (r == 2 || c == 2) return false;
		mat[r-3][c-3] = '.';
		++m;
		g = 1;
	}
	
	for (int j = 0; j < c-2-g && m; ++j)
		mat[r-2][j] = '*', mat[r-1][j] = '*', m -= 2;
	
	for (int i = 0; i < r-2-g && m; ++i)
		mat[i][c-2] = '*', mat[i][c-1] = '*', m -= 2;
	
	if (m) return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	
	for (int q = 1; q <= t; ++q)
	{
		cout << "Case #" << q << ":" << endl;
		cin >> r >> c >> m;
		if (!solve())
		{
			cout << "Impossible" << endl;
			continue;
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				cout << mat[i][j];
			cout << endl;
		}
	}
}

