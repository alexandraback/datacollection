#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <climits>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
typedef pair<ld, ld> ptd;

const int INF = INT_MAX / 2;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

int x, y;

inline bool read()
{
	if (scanf("%d%d", &x, &y) != 2)
		return false;
		
	return true;
}

const int N = 400 + 3;
const int SH = N / 2;

bool z[N][N][N];
pt p[N][N][N];
char pp[N][N][N];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
char w[] = { 'W', 'E', 'S', 'N' };

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);

	memset(z, false, sizeof(z));

	x += SH, y += SH;
	z[0][SH][SH] = true;
	
	int cnt = -1;
	
	forn(k, N - 1)
		forn(i, N)
			forn(j, N)
			{
				if (!z[k][i][j])
					continue;
					
				if (mp(i, j) == mp(x, y))
				{
					cnt = k;
					goto END;
				}
					
				forn(dir, 4)
				{
					int nx = i + dx[dir] * (k + 1);
					int ny = j + dy[dir] * (k + 1);

					if (correct(nx, ny, N, N))
					{
						z[k + 1][nx][ny] = true;
						p[k + 1][nx][ny] = mp(i, j);
						pp[k + 1][nx][ny] = w[dir];
					}
				}
			}
			
END:
	assert(cnt != -1);
			
	string ans = "";
	
	assert(z[cnt][x][y]);
	
	for(int k = cnt, i = x, j = y; k > 0; )
	{
		int ok = k, oi = i, oj = j;

		ans.pb(pp[ok][oi][oj]);
		
		k = ok - 1;
		i = p[ok][oi][oj].ft;
		j = p[ok][oi][oj].sc;
	}
	
	reverse(all(ans));
	printf("%s\n", ans.c_str());
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int testCnt;

    assert(scanf("%d\n", &testCnt) == 1);

    forn(test, testCnt)
    {
    	assert(read());
		solve(test);
	}

    return 0;
}
