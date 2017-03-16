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

#define DMAX 555000
#define NMAX 4005
#define INF 1000000009


string t;
int d[NMAX][5];
string s[DMAX];
int m = 0;
int n;

bool tryput(string& s, int i, int& fst, int& lst, int& cnt)
{
	cnt = 0;
	fst = INF;
	lst = -1;

	if (i + (int)s.size() > n) return false;

	forv(j, s)
	{
		if (s[j] != t[i + j])
		{
			cnt++;
			fst = min(fst, j);
			if (lst != -1 && j - lst < 5) return false;
			lst = j;
		}
	}
	return true;
}

void solve(int test)
{
	printf("Case #%d: ", test);

	getline(cin, t);

	n = (int)t.size();

	forn(i, NMAX) forn(j, 5) d[i][j] = INF;	
	d[0][4] = 0;

	forn(i, n)
	{
		forn(k, m)
		{
			int fst, lst, cnt;

			if (!tryput(s[k], i, fst, lst, cnt)) continue;
			
			forn(j, 5)
			{
				if (d[i][j] == INF) continue;
			    if (cnt > 0 && fst + j < 4) continue;

				int nlst = min(j + (int)s[k].size(), 4);
				if (cnt > 0) nlst = min(nlst, (int)s[k].size() - lst - 1);

				d[i + (int)s[k].size()][nlst] = min(d[i + (int)s[k].size()][nlst], d[i][j] + cnt);
			}

					
		}
	}

	cerr << test << endl;

	int ans = INF;
	forn(j, 5)
	{
		ans = min(ans, d[n][j]);
	}
	cout << ans << endl;
}


int main()
{

    freopen("dict.txt", "rt", stdin);
	while (!feof(stdin))
	{
		char str[100];
		gets(str);
		s[m++] = str;
		if (m % 1000 == 0) cerr << m << endl;
	}

    fclose(stdin);     

    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; scanf("%d\n", &tc);

    forn(it, tc) solve(it + 1);

    return 0;
}
