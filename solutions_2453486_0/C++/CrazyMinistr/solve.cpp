#include <set>
#include <map>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstddef>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>

#define LL long long

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0 ? -x : x; }
template <typename T> T _min(T a, T b) { return a < b ? a : b; }
template <typename T> T _max(T a, T b) { return a > b ? a : b; }

using namespace std;

string s[10];
int t;

char check(int x, int y, int dx, int dy)
{
	for (int i = 0; i < 4; i++)
		if (s[x + dx * i][y + dy * i] == '.')
			return '.';
	if (s[x][y] == 'T')
		s[x][y] = s[x + dx][y + dy];
	bool r = true;
	for (int i = 1; i < 4; i++)
		if (s[x][y] != s[x + dx * i][y + dy * i] && s[x + dx * i][y + dy * i] != 'T')
			r = false;
	if (r)
		return s[x][y];
	else
		return '.';
}

int main()
{
//*
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
//*/
	cin>> t;
	for (int test = 1; test <= t; test++)
	{
		bool d = false;
		for (int i = 0; i < 4; i++)
		{
			cin>> s[i];
			for (int j = 0; j < 4; j++)
				if (s[i][j] == '.')
					d = true;
		}
		char f = '.';
		for (int i = 0; i < 4; i++)
		{
			if (s[i][0] != '.' && s[i][1] != '.' && s[i][2] != '.' && s[i][3] != '.')
			{
				bool b = false;
				if (s[i][0] == 'T')
				{
					s[i][0] = s[i][1];
					b = true;
				}
				if ((s[i][0] == s[i][1] || s[i][1] == 'T') && (s[i][0] == s[i][2] || s[i][2] == 'T') && (s[i][0] == s[i][3] || s[i][3] == 'T'))
				{
					f = s[i][0];
					break;
				}
				if (b)
				{
					s[i][0] = 'T';
					b = false;
				}
			}
			if (s[0][i] != '.' && s[1][i] != '.' && s[2][i] != '.' && s[3][i] != '.')
			{
				bool b = false;
				if (s[0][i] == 'T')
				{
					s[0][i] = s[1][i];
					b = true;
				}
				if ((s[0][i] == s[1][i] || s[1][i] == 'T') && (s[0][i] == s[2][i] || s[2][i] == 'T') && (s[0][i] == s[3][i] || s[3][i] == 'T'))
				{
					f = s[0][i];
					break;
				}
				if (b)
				{
					s[0][i] = 'T';
					b = false;
				}
			}
		}
		if (f != '.')
		{
			printf("Case #%d: %c won\n", test, f);
			continue;
		}
		f = check(0, 0, 1, 1);
		if (f == '.')
			f = check(0, 3, 1, -1);

		if (f != '.')
			printf("Case #%d: %c won\n", test, f);
		else if (d)
			printf("Case #%d: Game has not completed\n", test);
		else
			printf("Case #%d: Draw\n", test);
	}
	return 0;
}
