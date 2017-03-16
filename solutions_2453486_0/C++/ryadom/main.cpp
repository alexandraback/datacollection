#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <utility>
#include <memory>
#include <malloc.h>
#include <string>
#include <string.h>
#include <fstream>
#include <set>
#include <map>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

typedef long long ll;

const int n = 4;

int a[n][n];


bool prov(int s)
{
	if (s == 3 || s == 4)
	{
		cout << "X won\n";
		return true;
	}
	if (s == -3 || s == -4)
	{
		cout << "O won\n";
		return true;
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	
	for (int er = 0; er < t; ++er)
	{
		cout << "Case #" << er + 1 << ": ";
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				char c = 0;
				while (c != 'T' && c != 'X' && c != 'O' && c != '.')
					cin >> c;
				if (c == 'T')
					a[i][j] = 0;
				else if (c == 'X')
					a[i][j] = 1;
				else if (c == 'O')
					a[i][j] = -1;
				else
					a[i][j] = 20000000;
			}
		for (int i = 0; i < n; ++i)
		{
			int s = 0;
			for (int j = 0; j < n; ++j)
				s += a[i][j];
			if (prov(s))
				goto l123;
			s = 0;
			for (int j = 0; j < n; ++j)
				s += a[j][i];
			if (prov(s))
				goto l123;
		}
		int s = 0;
		for (int i = 0; i < n; ++i)
			s += a[i][i];
		if (prov(s))
			goto l123;
		s = 0;
		for (int i = 0; i < n; ++i)
			s += a[n - 1 - i][i];
		if (prov(s))
			goto l123;
		s = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				s += a[i][j];
		if (s > 10000000)
			cout << "Game has not completed\n";
		else
			cout << "Draw\n";
l123:
		;
	}
	return 0;
}