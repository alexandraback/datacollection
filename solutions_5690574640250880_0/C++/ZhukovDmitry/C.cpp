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
typedef long long i64;
typedef __int128 i128;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int qq;
int n, m, k;
char a[64][64];

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d:\n", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);
		
		scanf("%d%d%d", &n, &m, &k);
		int r = n * m - k;
		memset(a, '*', sizeof(a));
		bool ok = true;

		if (n == 1 || m == 1)
		{
			forn(i, n)
			{
				forn(j, m)
				{
					if (r --> 0)
					{
						a[i][j] = '.';
					}
				}
			}
			a[0][0] = 'c';
		}
		else if (r == 2 || r == 3 || r == 5 || r == 7) ok = false;
		else if ((n == 2 || m == 2) && r % 2 == 1 && r > 1) ok = false;
		else
		{
			memset(a, '.', sizeof(a));
			ford(i, n)
			{
				if (i < 2) break;
				ford(j, m)
				{
					if (k --> 0)
					{
						a[i][j] = '*';
						if (!k)
						{
							if (j == 1)
							{
								a[i][j] = '.';
								a[i - 1][m - 1] = '*';
								if (i == 2)
								{
									a[i][j + 1]	= '.';
									a[0][m - 1] = '*';
								}
							}
						}
					}
				}
			}
			if (k > 0)
			{
				ford(j, m)
				{
					ford(i, 2)
					{
						if (k --> 0)
						{
							a[i][j] = '*';
							if (!k)
							{
								if (i == 1 && j > 0)
								{
									a[2][0] = a[2][1] = a[2][2] = '.';
									a[0][j] = a[0][j - 1] = a[1][j - 1] = '*';
								}
							}
						}
					}
				}
			}
			a[0][0] = 'c';
		}

		if (ok)
		{
			forn(i, n)
			{
				a[i][m] = '\0';
				puts(a[i]);
			}
		}
		else puts("Impossible");
		
		fflush(stdout);
	}

	return 0;
}
