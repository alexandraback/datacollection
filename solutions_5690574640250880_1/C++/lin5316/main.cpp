//#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");
ofstream fout("in.txt");

int main(){
	int T;
	int r, c, m;
	char ans[50][50];
	cin >> T;
	fout << T << endl;
	for (int t = 1; t <= T; t++){
		cin >> r >> c >> m;
		fout << r << ' ' << c << ' ' << m << endl;
		cout << "Case #" << t << ":" << endl;
		if (m == 0)
		{
			cout << "c";
			for (int i = 1; i < c; i++)
				cout << ".";
			cout << endl;
			for (int i = 1; i < r; i++)
			{
				for (int j = 0; j < c; j++)
					cout << ".";
				cout << endl;
			}
			continue;
		}
		if (r == 1 || c == 1)
		{
			if (r == 1)
			{
				for (int i = 0; i < m; i++)
					cout << "*";
				for (int i = 0; i < c - m - 1; i++)
					cout << ".";
				cout << "c" << endl;
			}
			else
			{
				for (int i = 0; i < m; i++)
					cout << "*" << endl;
				for (int i = 0; i < r - m - 1; i++)
					cout << "." << endl;
				cout << "c" << endl;
			}
			continue;
		}
		if (r == 2 || c == 2)
		{
			if (m % 2 == 0)
			{
				if (r * c - m >= 4)
				{
					if (r == 2)
					{
						for (int j = 0; j < m / 2; j++)
							cout << "*";
						for (int j = 0; j < c - m / 2 - 1; j++)
							cout << ".";
						cout << "c" << endl;
						for (int j = 0; j < m / 2; j++)
							cout << "*";
						for (int j = 0; j < c - m / 2; j++)
							cout << ".";
						cout << endl;
					}
					else
					{
						for (int i = 0; i < m / 2; i++)
							cout << "**" << endl;
						for (int i = 0; i < r - m / 2 - 1; i++)
							cout << ".." << endl;
						cout << "c." << endl;
					}
				}
				else
				{
					cout << "Impossible" << endl;
				}
			}
			else
			{
				if (r * c - m == 1)
				{
					for (int i = 0; i < r; i++)
					{
						if (i == r - 1)
						{
							for (int j = 0; j < c - 1; j++)
								cout << "*";
							cout << "c" << endl;
						}
						else
						{
							for (int j = 0; j < c; j++)
								cout << "*";
							cout << endl;
						}
					}
				}
				else
				{
					cout << "Impossible" << endl;
				}
			}
			continue;
		}
		int i, j, swapped = 0;
		if (r > c)
		{
			i = r;
			r = c;
			c = i;
			swapped = 1;
		}
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
				ans[i][j] = '.';
		}
		if (r <= c)
		{
			if (r*(c - r) >= m)
			{
				for (i = 0; i < r; i++)
				{
					for (j = 0; j < m / r; j++)
						ans[i][j] = '*';
				}
				if (m % r == 0)
				{
					ans[0][m / r + 1] = 'c';
				}
				else
				{
					j = m / r;
					for (i = 0; i < m % r; i++)
						ans[i][j] = '*';
					ans[r - 1][j + 1] = 'c';
					if (m % r == r - 1)
					{
						ans[r - 2][j] = '.';
						ans[0][j + 1] = '*';
					}
				}
			}
			else
			{
				for (i = 0; i < r; i++)
				{
					for (j = 0; j < c - r; j++)
						ans[i][j] = '*';
				}
				m = m - r * (c - r);
				for (i = 0; i < r - 3; i++)
				{
					if (2 * (r - i) - 1 < m)
					{
						m -= 2 * (r - i) - 1;
						for (j = c - r; j < c; j++)
							ans[i][j] = '*';
						for (j = 0; j < r; j++)
							ans[j][c - r + i] = '*';
					}
					else
					{
						if (r - i <= m)
						{
							for (j = 0; j < r; j++)
								ans[j][c - r + i] = '*';
							m -= r - i;
							for (j = c - r; j < c - (r - i - 1 - m); j++)
								ans[i][j] = '*';
							ans[i + 2][c - 1] = 'c';
							if (r - i - 1 == m + 1)
							{
								ans[i][c - 2] = '.';
								ans[i + 1][c - (r - i - 1)] = '*';
							}
							m = 0;
						}
						else
						{
							for (j = i; j < i + m; j++)
								ans[j][c - r + i] = '*';
							ans[r - 1][c - r + i + 1] = 'c';
							if (m == r - i - 1)
							{
								ans[i + m - 1][c - r + i] = '.';
								ans[i][c - r + i + 1] = '*';
							}
							m = 0;
						}
						break;
					}
				}
				if (m > 0)
				{
					if (m == 1)
					{
						ans[i][c - 3] = '*';
						ans[r - 1][c - 1] = 'c';
					}
					else if (m == 3)
					{
						ans[i][c - 3] = '*';
						ans[i + 1][c - 3] = '*';
						ans[i + 2][c - 3] = '*';
						ans[r - 1][c - 1] = 'c';
					}
					else if (m == 5)
					{
						ans[i][c - 3] = '*';
						ans[i + 1][c - 3] = '*';
						ans[i + 2][c - 3] = '*';
						ans[i][c - 2] = '*';
						ans[i][c - 1] = '*';
						ans[r - 1][c - 1] = 'c';
					}
					else if (m == 8)
					{
						for (i = i; i < r; i++)
						{
							for (j = c - 3; j < c; j++)
								ans[i][j] = '*';
						}
						ans[r - 1][c - 1] = 'c';
					}
					else
					{
						ans[0][0] = '0';
					}
				}
			}
		}
		if (ans[0][0] == '0')
			cout << "Impossible" << endl;
		else
		{
			if (swapped)
			{
				for (int i = 0; i < c; i++)
				{
					for (int j = 0; j < r; j++)
						cout << ans[j][i];
					cout << endl;
				}
			}
			else
			{
				for (int i = 0; i < r; i++)
				{
					for (int j = 0; j < c; j++)
						cout << ans[i][j];
					cout << endl;
				}
			}
		}
	}
}