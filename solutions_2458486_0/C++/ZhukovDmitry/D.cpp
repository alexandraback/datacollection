#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int MAXK = 400;

int qq, n, k, m;
int key[512];
int s[512][512];
int sc[512];
int b[512];
int f[512];
int c[512];
int a[512][512];
bool u[512];
int u2[512];
bool u3[512];
bool um[512];
int path[512];
bool mask[512][512];
bool ch[512][512];

bool dfs(int v, int ss)
{
	path[ss] = v;
	u2[v] = 1;

	forn(j1, c[v])
	{
		int j = a[v][j1];
//		cerr << " $ " << v << " " << j << endl;
		forn(i1, sc[j])
		{
			int i = s[j][i1];
			if (u[i] || u3[i]) continue;
//			cerr << " ! " << v << " " << i << endl;
			if (!u2[i])
			{
				if (dfs(i, ss + 1))
				{
					return true;
				}
			}
			else if (u2[i] == 1)
			{
				clr(mask[m]);
				clr(ch[m]);
				int x = ss;
				mask[m][key[i]]++;
				ch[m][i]++;
				u3[i] = true;
				while (path[x] != i)
				{
					u3[path[x]] = true;
					mask[m][key[path[x]]]++;
					ch[m][path[x]]++;
					x--;
				}
				m++;
				return true;
			}
		}
	}

	u2[v] = 2;
	return false;
}

bool check(int *b)
{
	m = 0;

	clr(u2);
	clr(u3);
	forn(i, n)
	{
//		clr(u2);
		if (!u[i] && !u2[i] && !u3[i] && dfs(i, 0))
		{
//			cerr << "! " << i << endl;
			clr(u2);
			i--;
		}
	}
//	cerr << "m = " << m << endl;
/*	forn(i, m)
	{
		forn(j, n)
		{
			if (ch[i][j])
			{
				cerr << j << " ";
			}
		}
		cerr << endl;
	}*/

	memmove(f, b, sizeof(f));
	int cnt = 0;
	forn(i, n)
	{
		if (!u[i]) cnt++;
	}
	clr(u2);
	clr(um);
//	cerr << "cnt = " << cnt << endl;
	while (cnt > 0)
	{
		bool found = false;
		forn(i, m)
		{
			if (um[i]) continue;
			bool ok = false;
			forn(j, MAXK)
			{
				if (mask[i][j] > 0 && f[j] > 0)
				{
					ok = true;
					break;
				}
			}
			if (ok)
			{
				um[i] = true;
//				cerr << "? " << endl;
				forn(j, n)
				{
					if (ch[i][j])
					{
						cnt--;
						found = true;
						f[key[j]]--;
						forn(l, c[j])
						{
							f[a[j][l]]++;
						}
					}
				}
/*				forn(l, 4)
				{
					cerr << f[l] << " ";
				}
				cerr << endl;*/
			}
		}
		if (found) continue;
		forn(i, n)
		{
			if (u[i]) continue;
			if (u2[i]) continue;
			if (u3[i]) continue;

			if (f[key[i]] > 0)
			{
				u2[i] = true;
				found = true;
				cnt--;
				f[key[i]]--;
				forn(j, c[i])
				{
					f[a[i][j]]++;
				}
				break;
/*				cerr << i << ": ";
				forn(l, 4)
				{
					cerr << f[l] << " ";
				}
				cerr << endl;*/
			}
		}
//		cerr << "cnt = " << cnt << endl;
		if (!found) return false;
	}

	return true;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d:", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);
		
		scanf("%d%d", &k, &n);
		clr(b);
		forn(i, k)
		{
			int x;
			scanf("%d", &x);
			x--;
			b[x]++;
		}
		clr(sc);
		clr(u);
		forn(i, n)
		{
			scanf("%d", &key[i]);
			key[i]--;
			scanf("%d", &c[i]);
			forn(j, c[i])
			{
				scanf("%d", &a[i][j]);
				a[i][j]--;
			}
			s[key[i]][sc[key[i]]++] = i;
		}

		if (!check(b))
		{
			puts(" IMPOSSIBLE");
		}
		else
		{
			forn(i, n)
			{
				forn(j, n)
				{
					if (!u[j] && b[key[j]] > 0)
					{
						u[j] = true;
						b[key[j]]--;
						forn(l, c[j])
						{
							b[a[j][l]]++;
						}
//						cerr << "--------------------------------------------" << endl;
//						cerr << "j = " << j << endl;
						if (check(b))
						{
							printf(" %d", j + 1);
							break;
						}
						b[key[j]]++;
						forn(l, c[j])
						{
							b[a[j][l]]--;
						}
						u[j] = false;
					}
				}
			}
			puts("");
			forn(i, n)
			{
				if (!u[i])
				{
					cerr << "Botwa !!!" << endl;
				}
			}
		}
		
		fflush(stdout);
	}

	return 0;
}
