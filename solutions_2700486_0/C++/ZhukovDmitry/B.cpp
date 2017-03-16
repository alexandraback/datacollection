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

const int MAXN = 2024;

int qq, n, x, y;
ld c[MAXN][MAXN];

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	c[0][0] = 1.0;
	For(i, 1, MAXN - 1)
	{
		c[i][0] = c[i - 1][0] * 0.5;
		c[i][i] = c[i - 1][i - 1] * 0.5;
		For(j, 1, i - 1)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) * 0.5;
		}
	}
//	ld t = 0;
//	forn(i, 101)
//	{
//		t += c[100][i];
//	}
//	fprintf(stderr, "%0.10lf\n", (double)(t));
//	return 0;
//	fprintf(stderr, "%0.10lf\n", (double)(c[1416][1416 / 2]/* * 1e-300*/));

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d: ", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);
		
		scanf("%d%d%d", &n, &x, &y);
		if (x < 0) x = -x;
		ld ans = 0.0;

		int k = (x + y) / 2;
		i64 s = 0;
		int last = 0;
		forn(i, k + 1)
		{
			last = s;
			s += 1 + i * 4;
		}
//		cerr << "s = " << s << endl;
		if (n <= last) ans = 0.0;
		else if (n >= s) ans = 1.0;
		else
		{
			if (!x) ans = 0.0;
			else
			{
				int t = n - last;
				if (t >= k * 2 + y + 1) ans = 1.0;
				else if (t <= y) ans = 0.0;
				else
				{
//					cerr << t << " " << ans << endl;
					forn(i, t + 1)
					{
						if (i + k * 2 < t) continue;
						if (i > y) ans += c[t][i];
					}
				}
			}
		}

		printf("%0.9lf\n", (double)ans);
		
		fflush(stdout);
	}

	return 0;
}
