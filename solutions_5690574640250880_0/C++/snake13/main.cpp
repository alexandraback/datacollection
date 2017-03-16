#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
#include <math.h>
#include <map>
#include <string>
#include <ctime>
#define LL long long int
#define double long double
using namespace std;

bool arr[55][55];
void solve ()
{
	int r, c, m, i, j;
	cin >> r >> c >> m;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			arr[i][j] = false;
	if (m == r*c - 1)
	{
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
				if (i == r-1 && j == c-1)
					cout<<'c';
				else
					cout<<'*';
			cout<<endl;
		}
		return;
	}
	if (r == 1)
	{
		for (j = 0; j < min(m, c - 1); j++) arr[0][j] = true;
		m -= min(m, c - 1);
	}
	if (c == 1)
	{
		for (i = 0; i < min(m, r - 1); i++) arr[i][0] = true;
		m -= min(m, r - 1);
	}
	for (i = 0; i < r - 2 && m; i++)
	{
		for (j = 0; j < c - 2 && m; j++)
		{
			if (i != r - 3 || j != c - 3)
			{
				arr[i][j] = 1;
				m--;
			}
		}
	}

	bool flag = 0;
	if (m%2 && r - 3 >= 0 && c - 3 >= 0)
	{
		arr[r-3][c-3] = 1;
		m--;
		flag = true;
	}
	for (j = 0; j < c - 3 && m; j++)
	{
		arr[r - 2][j] = arr[r - 1][j] = 1;
		m-=2;
	}
	for (i = 0; i < r - 3 && m; i++)
	{
		arr[i][c - 2] = arr[i][c - 1] = 1;
		m-=2;
	}
	//cout << m << endl;
	if (m%2 == 0 && m && r > 2 && c > 2 && !flag)
	{
		cout << "Impossible" << endl;
		return;
	}
	if (r > 2 && m)
	{
		arr[r - 3][c - 2] = arr[i][c - 1] = 1;
		m-=2;
	}
	if (c > 2 && m)
	{
		arr[r - 2][c - 3] = arr[r - 1][c - 3] = 1;
		m-=2;
	}
	if (m) cout << "Impossible" << endl;
	else
	{
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				if (arr[i][j]) cout<<'*';
				else
				{
					if (i == r - 1 && j == c - 1)
						cout << 'c';
					else
						cout << '.';
				}
			}
			cout << endl;
		}
	}
}

int main()
{
	freopen("C-small-attempt3.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i, t;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ":" << endl;
		solve();
	}
	return 0;
}