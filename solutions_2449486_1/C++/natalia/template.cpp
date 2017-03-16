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

#define NMAX 105

int n, m;
int a[NMAX][NMAX];

bool canReach(int x, int y)
{
	bool can = true;

	forn(i, n)
	{
		if (a[i][y] > a[x][y]) can = false;
	}

	if (can) return true;

	can = true;

	forn(j, m)
	{
		if (a[x][j] > a[x][y]) can = false;
	}
		
	return can;
}

void solve(int test)
{
	printf("Case #%d: ", test);

	cin >> n >> m;
	forn(i, n)
	{
		forn(j, m)
		{
			cin >> a[i][j];
		}
	}

	forn(i, n)
	{
		forn(j, m)
		{
			if (!canReach(i, j)) 
			{
				cout << "NO\n";
				return;
			} 
		}
	}

	cout << "YES\n";

}

int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; scanf("%d\n", &tc);

    forn(it, tc) solve(it + 1);

    return 0;
}
