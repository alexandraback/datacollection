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

const int INF = 0x3f3f3f3f;

int qq, k, n;
char a[1024000][16];
int l[1024000];
char s[10240];
int d[10240][8];
int st[256][256];
int en[256][256];

inline void upd(int &a, int b)
{
	if (a > b) a = b;
}

void go(int i, int pos, int mi, int ma)
{
//	cerr << mi << " " << ma << endl;
	if (mi < 0) mi = 0;
	if (ma > k - 1) ma = k - 1;
	For(j, mi, ma)
	{
		if (l[j] + i > n) continue;
		int dif = 101;
		int last = -100;
		int cnt = 0;
		forn(t, l[j])
		{
			if (s[i + t] != a[j][t])
			{
				cnt++;
				if (dif >= 100) dif = t;
				if (t - last < 5)
				{
					dif = -1;
					break;
				}
				last = t;
			}
		}
		if (dif < 0 || dif + pos < 5) continue;
		dif = l[j] - last;
		if (dif > 5) dif = 5;
		upd(d[i + l[j]][dif], d[i][pos] + cnt);
	}
}

int main()
{
	FILE *f = fopen("garbled_email_dictionary.txt", "rt");
	k = 0;
	while (fscanf(f, "%s", a[k]) == 1) k++;
	forn(i, k)
	{
		l[i] = strlen(a[i]);
	}
	fclose(f);

	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	memset(st, 0xff, sizeof(st));
	memset(en, 0xff, sizeof(en));
	forn(i, k)
	{
		int c1 = a[i][0];
		if (st[c1][0] < 0) st[c1][0] = i;
		en[c1][0] = i;
		if (l[i] >= 2)
		{
			int c2 = a[i][1];
			if (st[c1][c2] < 0) st[c1][c2] = i;
			en[c1][c2] = i;
		}
	}

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d: ", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);
		
		scanf("%s", s);
		n = strlen(s);
		memset(d, 0x3f, sizeof(d));
		d[0][5] = 0;
		forn(i, n)
		{
			For(pos, 1, 5)
			{
				if (d[i][pos] >= INF) continue;

				go(i, pos, st[(int)s[i]][0], en[(int)s[i]][0]);
				For(cc, 'a', 'z')
				{
					if (cc == s[i]) continue;
					go(i, pos, st[cc][0], st[cc][0]);
				}
				if (i + 2 <= n)
				{
					For(cc, 'a', 'z')
					{
						if (cc == s[i]) continue;
						int c2 = s[i + 1];
//						For(c2, 'a', 'z')
						go(i, pos, st[cc][c2], en[cc][c2]);
					}
				}
//				go(i, pos, 0, k - 1);
			}
		}
		int ans = INF;
		For(i, 1, 5)
		{
			ans = min(ans, d[n][i]);
		}
		printf("%d\n", ans);
		
		fflush(stdout);
	}

	return 0;
}
