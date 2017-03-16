#include <iostream>

#define MAX(a, b) (a > b ? a : b)
#define PAR(a) (!(a % 2))

using namespace std;

char tab[50][50];

void winEasy(const int r, const int c)
{
	bool first = true;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (first)
			{
				cout << "c";
				first = false;
			}
			else
				cout << ".";
		}
		cout << "\n";
	}
}

void win1(const int r, const int c)
{
	bool first = true;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (first)
			{
				cout << "c";
				first = false;
			}
			else
				cout << "*";
		}
		cout << "\n";
	}
}

void winLine(const int r, const int c, const int m)
{
	bool first = true;
	int space = r * c - 1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (first)
			{
				cout << "c";
				first = false;
			}
			else if (space-- > m)
				cout << ".";
			else
				cout << "*";
		}
		cout << "\n";
	}
}

void winRectangle(const int r, const int c, const int d1, const int d2, const int m)
{
	bool first = true;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (first)
			{
				cout << "c";
				first = false;
			}
			else if (i < d1 && j < d2)
				cout << ".";
			else
				cout << "*";
		}
		cout << "\n";
	}
}

bool pushMaxI(const int maxi, const int r)
{
	for (int i = 0; i < r; i++)
	{
		if (tab[i][maxi] == '*')
		{
			tab[i][maxi] = '.';
			return true;
		}
	}
	return false;
}

bool winFilling(const int r, const int c, const int m)
{
	int free = r * c - m - 4;
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			tab[i][j] = '*';
		}
	}
	tab[0][0] = 'c';
	tab[0][1] = '.';
	tab[1][0] = '.';
	tab[1][1] = '.';
	int dir = 0, maxi = 2;
	i = 2;
	j = 0;
	while (free)
	{
		if (free > 3 || free == 2)
		{
			if (!dir)
			{
				if (i < c)
				{
					tab[j][i] = tab[j + 1][i] = '.';
					i++;
					maxi = (i > maxi ? i : maxi);
					free -= 2;
				}
				else
				{
					dir = 1;
					i = 0;
					j += 2;
					tab[j][i] = tab[j][i + 1] = '.';
					j++;
					free -= 2;
				}
			}
			else
			{
				if (j < r)
				{
					if (i + 1 < c)
					{
						tab[j][i] = tab[j][i + 1] = '.';
						j++;
					}
					else
					{
						tab[j][i] = tab[j + 1][i] = '.';
						j += 2;
					}
					free -= 2;
				}
				else
				{
					j = 2;
					i += 2;
					if (i + 1 < c)
					{
						tab[j][i] = tab[j][i + 1] = '.';
						j++;
					}
					else
					{
						tab[j][i] = tab[j + 1][i] = '.';
						j += 2;
					}
					free -= 2;
				}
			}
		}
		else if (free == 3)
		{
			i = 0;
			while (!pushMaxI(i, r))
				i++;
			if (i + 1 < c)
			{
				pushMaxI(i + 1, r);
				if (i + 2 < c)
					pushMaxI(i + 2, r);
				else
				{
					if (!pushMaxI(i, r))
						pushMaxI(i + 1, r);
				}
			}
			else
			{
				pushMaxI(i, r);
				pushMaxI(i, r);
			}
			free -= 3;
		}
		else if (free == 1)
		{
			while (!pushMaxI(i, r))
				i += 2;
			if (dir)
			{
				pushMaxI(i, r);
				free--;
			}
			return false;
		}
	}
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			cout << tab[i][j];
		}
		cout << "\n";
	}
	return true;
}

int main(int argc, char* argv[])
{
	int p;
	cin >> p;
	int r, c, m, free;
	bool win;
	for (int n = 1; n <= p; n++)
	{
		win = false;
		cout << "Case #" << n << ":\n";
		cin >> r >> c >> m;
		if (!m)
		{
			win = true;
			winEasy(r, c);
		}
		else if (r * c - 1 == m)
		{
			win1(r, c);
			win = true;
		}
		else if (r == 1 || c == 1)
		{
			winLine(r, c, m);
			win = true;
		}
		else
		{
			free = r * c - m;
			for (int i = 2; i <= r; i++)
			{
				for (int j = 2; j <= c; j++)
				{
					if (free == i * j)
					{
						win = true;
						winRectangle(r, c, i, j, m);
						goto end;
					}
				}
			}
		}
		if (!win)
		{
			free = r * c - m;
			if (!(free % 2 && (r == 2 || c == 2)))
			{
				if (r * c - m >= 8 && winFilling(r, c, m))
					win = true;
			}
		}
end:
		if (!win)
			cout << "Impossible\n";
	}
	return 0;
}
