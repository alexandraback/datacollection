#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

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

FILE *g_f_;
int g_s_;
char *g_g_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))
#define gets(s) (g_g_ = gets(s))

#ifdef ROOM_311
time_t et_0;

__attribute__((constructor)) void init_main()
{
	et_0 = clock();
}

__attribute__((destructor)) void fini_main()
{
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
}
#endif

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

int n;
i64 a[1024000];
i64 p10[102];

bool check_pal(i64 x)
{
	int s[24];
	int l = 0;
	do
	{
		s[l++] = x % 10;
		x /= 10;
	}
	while (x);
	forn(i, l / 2)
	{
		if (s[i] != s[l - i - 1]) return false;
	}
	return true;
}

void precalc()
{
	p10[0] = 1;
	For(i, 1, 20)
	{
		p10[i] = p10[i - 1] * 10;
	}
	n = 0;
	For(len, 1, 7)
	{
		int t = (len + 1) / 2;
		For(i, p10[t - 1], p10[t] - 1)
		{
			i64 y = i;
			int x = i;
			if (len & 1)
			{
				x /= 10;
			}
			forn(j, len / 2)
			{
				y = y * 10 + x % 10;
				x /= 10;
			}
			y *= y;
			if (check_pal(y)) a[n++] = y;
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	precalc();

/*	fprintf(stderr, "%d\n", n);
	forn(i, n)
	{
		fprintf(stderr, "%lld\n", a[i]);
	}
*/
	int tn;
	scanf("%d", &tn);
	For(ii, 1, tn)
	{
		printf("Case #%d: ", ii);
		fprintf(stderr, "Case #%d: ", ii);

		i64 l, r;
		scanf("%lld%lld", &l, &r);
		int ans = 0;
		forn(i, n)
		{
			if (a[i] >= l && a[i] <= r) ans++;
		}
		printf("%d\n", ans);
		fprintf(stderr, "%d", ans);

		fprintf(stderr, "\n");
	}
	
	return 0;
}
