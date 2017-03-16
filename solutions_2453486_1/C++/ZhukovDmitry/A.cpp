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

char a[5][5];

void out(char const *s)
{
	printf("%s", s);
	fprintf(stderr, "%s", s);
}

bool win(char c)
{
	forn(i, 4)
	{
		bool bb = true;
		forn(j, 4)
		{
			if (!(a[i][j] == c || a[i][j] == 'T')) bb = false;
		}
		if (bb) return true;
	}
	forn(i, 4)
	{
		bool bb = true;
		forn(j, 4)
		{
			if (!(a[j][i] == c || a[j][i] == 'T')) bb = false;
		}
		if (bb) return true;
	}
	{
		bool bb = true;
		forn(j, 4)
		{
			if (!(a[j][j] == c || a[j][j] == 'T')) bb = false;
		}
		if (bb) return true;
	}
	{
		bool bb = true;
		forn(j, 4)
		{
			if (!(a[3 - j][j] == c || a[3 - j][j] == 'T')) bb = false;
		}
		if (bb) return true;
	}

	return false;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	int tn;
	scanf("%d", &tn);
	For(ii, 1, tn)
	{
		printf("Case #%d: ", ii);
		fprintf(stderr, "Case #%d: ", ii);

		forn(i, 4)
		{
			scanf("%s", a[i]);
		}
		bool em = false;
		forn(i, 4)
		{
			forn(j, 4)
			{
				if (a[i][j] == '.') em = true;
			}
		}
		if (win('X')) out("X won");
		else if (win('O')) out("O won");
		else if (em) out("Game has not completed");
		else out("Draw");

		puts("");
		fprintf(stderr, "\n");
	}
	
	return 0;
}
