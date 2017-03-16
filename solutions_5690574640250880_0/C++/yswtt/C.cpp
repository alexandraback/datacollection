#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	for (int tt = 1; tt <= t; ++tt)
	{
		cout << "Case #" << tt << ":" << endl;
		int r, c, m, b;
		char a[60][60];
		cin >> r >> c >> m;
		
		b = r * c - m;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				a[i][j] = '.';
		a[0][0] = 'c';
		if (b == 1)
		{
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
					if ((i == 0) && (j == 0))
						cout << "c";
					else
						cout << "*";
				cout << endl;
			}
			continue;
		}
		else if (r == 1)
		{
			cout << "c";
			for (int i = 1; i < c; ++i)
				if (i < b)
					cout << ".";
				else
					cout << "*";
			cout << endl;
			continue;
		}
		else if (c == 1)
		{
			cout << "c" << endl;
			for (int i = 1; i < r; ++i)
				if (i < b)
					cout << "." << endl;
				else
					cout << "*" << endl;
			continue;
		}
		else if (r == 2)
		{
			if (b % 2 == 1)
			{
				cout << "Impossible" << endl;
				continue;
			}
			else if ((b == 2) && (c > 1))
			{
				cout << "Impossible" << endl;
				continue;
			}
			int i = c - 1;
			while (m > 0)
			{
				a[0][i] = '*';
				a[1][i] = '*';
				i--;
				m -= 2;
			}
		}
		else if (c == 2)
		{
			if (b % 2 == 1)
			{
				cout << "Impossible" << endl;
				continue;
			}
			else if ((b == 2) && (r > 1))
			{
				cout << "Impossible" << endl;
				continue;
			}
			int i = r - 1;
			while (m > 0)
			{
				a[i][0] = '*';
				a[i][1] = '*';
				i--;
				m -= 2;
			}
		}
		else
		{
			for (int i = r - 1; i > 2; --i)
			{
				if (m != c - 1)
				{
					for (int j = c - 1; j >= 0; --j)
					{
						if (m-- > 0)
							a[i][j] = '*';
						else
							break;
					}
				}
				else
				{
					for (int j = 2; j < c; ++j)
					{
						a[i][j] = '*';
						m--;
					}
				}
			}
			if ((b == 2) || (b == 3) || (b == 5) || (b == 7))
			{
				cout << "Impossible" << endl;
				continue;
			}
			if (m < c - 1)
			{
				for (int j = c - 1; j >= 0; --j)
				{
					if (m-- > 0)
						a[2][j] = '*';
					else
						break;
				}
			}
			else if (m % 3 == 2)
			{
				for (int j = 0; j < m / 3 + 2; ++j)
					a[2][c-1-j] = '*';
				for (int j = 0; j < m / 3; ++j)
				{
					a[1][c-1-j] = '*';
					a[0][c-1-j] = '*';
				}
			}
			else
			{
				for (int j = c - 1; j >= 0; --j)
				{
					for (int i = 2; i >= 0; --i)
						if (m-- > 0)
							a[i][j] = '*';
				}
			}
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				cout << a[i][j];
			cout << endl;
		}		
	}
	
	return 0;
}
