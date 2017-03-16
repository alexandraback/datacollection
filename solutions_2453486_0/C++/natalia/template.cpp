#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back                      
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define pi 3.1415926535897932

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

char a[4][4];

bool winRow(int i, char c)
{
	forn(j, 4)
	{
		if (a[i][j] != c && a[i][j] != 'T') return false;
	}
	return true;
}

bool winCol(int j, char c)
{
	forn(i, 4)
	{
		if (a[i][j] != c && a[i][j] != 'T') return false;
	}
	return true;
}

bool winDiag1(char c)
{
	forn(i, 4)
	{
		if (a[i][i] != c && a[i][i] != 'T') return false;
	}
	return true;
}

bool winDiag2(char c)
{
	forn(i, 4)
	{
		if (a[i][3 - i] != c && a[i][3 - i] != 'T') return false;
	}
	return true;
}

bool isEmpty()
{
	forn(i, 4) forn(j, 4) if (a[i][j] == '.') return true;
	return false;
}

void solve(int test)
{
	printf("Case #%d: ", test);

	forn(i, 4)
	{
		forn(j, 4)
		{
			scanf("%c", &a[i][j]);
		}
		scanf("\n");
	}	

	forn(i, 4) 
	{
		if (winRow(i, 'X') || winCol(i, 'X'))
		{
			cout << "X won\n";
			return;
		}
		if (winRow(i, 'O') || winCol(i, 'O'))
		{
			cout << "O won\n";
			return;
		}
	}

	if (winDiag1('X') || winDiag2('X'))
	{
		cout << "X won\n";
		return;
	}
	if (winDiag1('O') || winDiag2('O'))
	{
		cout << "O won\n";
		return;
	}

	if (!isEmpty())
	{
		cout << "Draw\n";
	}
	else
	{
		cout << "Game has not completed\n";
	}
}

int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; scanf("%d\n", &tc);

    forn(it, tc) solve(it + 1);

    return 0;
}
