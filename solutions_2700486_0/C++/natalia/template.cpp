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

struct Point
{
	int x, y;
};

#define NMAX 25

int n;
Point p[NMAX];

bool taken(int n, int x, int y)
{
	forn(i, n)
	{
		if (p[i].x == x && p[i].y == y) return true;
	}
	return false;
}

void solve(int test)
{
	printf("Case #%d: ", test);

	cin >> n;
	Point q; cin >> q.x >> q.y;

	int ans = 0;

	forn(mask, (1 << n))
	{
		forn(i, n)
		{
			p[i].x = 0;
			p[i].y = 0;
			forn(j, i)
			{
				if (p[j].x == 0) p[i].y = max(p[i].y, p[j].y + 2);
			}			
			while (p[i].y > 0)
			{
				bool left = taken(i, p[i].x - 1, p[i].y - 1);
				bool right = taken(i, p[i].x + 1, p[i].y - 1);

				if (left && right) break;

				if (!right && (left || (mask & (1 << i))))
				{
					p[i].x++;
				}
				else
				{
					p[i].x--;
				}
				p[i].y--;
			}
		}

		if (taken(n, q.x, q.y)) ans++; 
	}

	cerr << test << endl;

	printf("%.10lf\n", double(ans) / (1 << n));
}

int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; scanf("%d\n", &tc);

    forn(it, tc) solve(it + 1);

    return 0;
}
