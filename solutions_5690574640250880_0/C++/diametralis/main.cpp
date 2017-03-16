#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>

#include <cstring>
#include <cstdio>
#include <memory.h>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define ford(i,n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i,a,b) for(int i = int(a); i <= int(b); i++)
#define foreach(it,a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define sz(a) int((a).size())
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pr;
typedef pair<ld, ld> ptd;

#define PI 3.14159265
#define EPS 1E-4

void go(char tdesk[60][60], bool used[60][60], int i, int j, int r, int c)
{
	if (tdesk[i][j] != '*' && !used[i][j])
	{
		used[i][j] = true;
		int ng = 0;
		fore(di, -1, 1)
			fore(dj, -1, 1)
			{
				if (i + di >= 0 && i + di < r && j + dj >= 0 && j + dj < c)
				{
					if (tdesk[i + di][j + dj] == '*')
						ng++;
				}
					
			}
		if (ng == 0)
		{
			fore(di, -1, 1)
				fore(dj, -1, 1)
				{
					if (i + di >= 0 && i + di < r && j + dj >= 0 && j + dj < c && !used[i+di][j+dj])
					{
						go(tdesk, used, i + di, j + dj, r, c);
					}

				}
		}
	}
}

void solveB()
{
	int T;
	cin >> T;
	char desk[60][60];
	//char tdesk[60][60];
	bool used[60][60];
	forn(t, T)
	{
		int r, c, m;
		cin >> r; cin >> c; cin >> m;
		
		forn(i, r)
			forn(j, c)
			desk[i][j] = '.';
		int nr = r, nc = c;
		bool isOk = true;
		while (m != 0)
		{
			if (nr < nc)
			{
				if (m >= nr)
				{
					forn(i, nr)
						desk[i][nc - 1] = '*';
					m -= nr;
					nc--;
				}
				else {
					if (nr - 2 + nc - 2 + 1 < m)
					{
						isOk = false;
						break;
					}
					else {
						forn(i, nc - 2)
						{
							desk[nr - 1][nc - 1 - i] = '*';
							m--;
							if (m == 0)
								break;
						}
						forn(i, m)
							desk[nr - 2 - i][nc - 1] = '*';
						m = 0;
					}
				}
			}
			else {
				if (m >= nc)
				{
					forn(i, nc)
						desk[nr-1][i] = '*';
					m -= nc;
					nr--;
				}
				else {
					if (nr - 2 + nc - 2 + 1 < m)
					{
						isOk = false;
						break;
					}
					else {
						forn(i, nc - 2)
						{
							desk[nr - 1][nc - 1 - i] = '*';
							m--;
							if (m == 0)
								break;
						}
						
						forn(i, m)
							desk[nr - 2 - i][nc - 1] = '*';
						m = 0;
					}
				}
			}
		}

		if (isOk)
		{
			//run
			//forn(i, r)
			//	forn(j, c)
			//	tdesk[i][j]=desk[i][j];
			forn(i, r)
				forn(j, c)
				used[i][j] = false;
			go(desk, used, 0, 0, r, c);
			forn(i, r)
				forn(j, c)
				{
					if (!used[i][j] && desk[i][j] != '*')
					{
						isOk = false;
					}
				}
			if (!isOk)
			{
				//try side
				forn(i, r)
					forn(j, c)
					used[i][j] = false;
				if (c > 1 && desk[0][1] != '*')
				{
					isOk = true;
					go(desk, used, 0, 1, r, c);
					forn(i, r)
						forn(j, c)
						{
							if (!used[i][j] && desk[i][j] != '*')
							{
								isOk = false;
							}
						}
				}
				if (!isOk)
				{
					//try side
					forn(i, r)
						forn(j, c)
						used[i][j] = false;
					if (r > 1 && desk[1][0] != '*')
					{
						isOk = true;
						go(desk, used, 1, 0, r, c);
						forn(i, r)
							forn(j, c)
							{
								if (!used[i][j] && desk[i][j] != '*')
								{
									isOk = false;
								}
							}
					}
				}
			}
		}

		desk[0][0] = 'c';

		cout << "Case #" << t + 1 << ": "<<endl;
		if (!isOk)
		{
			cout << "Impossible" << endl;
		}
		else {
			forn(i, r)
			{
				forn(j, c)
				{
					cout << desk[i][j];
				}
				cout << endl;
			}
		}
	}
}

int main() {
#ifdef diametralis
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solveB();

	//cout << 25<<endl;
	//forn(i, 25)
	//{
	//	cout << "5 5 " << i << endl;
	//}
#ifdef diametralis
	cerr << "Time == " << clock() << endl;
#endif
}