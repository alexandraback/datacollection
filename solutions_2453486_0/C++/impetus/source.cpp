#pragma comment (linker, "/STACK:268435456")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <functional>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>

using namespace std;
template <class T> T sqr(T a) { return a * a; }

char s[5][5];

int check(int x0, int y0, int dx, int dy, char c)
{
	for (int i = 0; i < 4; i++, x0 += dx, y0 += dy)
		if (s[x0][y0] != c && s[x0][y0] != 'T')
			return 0;
	return 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tn;
	cin >> tn;
	for (int tc = 0; tc < tn; tc++)
	{
		gets(s[0]);
		for (int i = 0; i < 4; i++)
			gets(s[i]);
		int xwon = check(0, 0, 1, 1, 'X') || check(0, 3, 1, -1, 'X');
		int owon = check(0, 0, 1, 1, 'O') || check(0, 3, 1, -1, 'O');
		for (int i = 0; i < 4; i++)
		{
			xwon |= check(i, 0, 0, 1, 'X') || check(0, i, 1, 0, 'X');
			owon |= check(i, 0, 0, 1, 'O') || check(0, i, 1, 0, 'O');
		}
		string result;
		if (xwon)
			result = "X won";
		else if (owon)
			result = "O won";
		else
		{
			int full = 1;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					full &= s[i][j] != '.';
			result = full ? "Draw" : "Game has not completed";
		}
		cout << "Case #" << tc + 1 << ": " << result;
		cout << endl;
	}
	return 0;
}