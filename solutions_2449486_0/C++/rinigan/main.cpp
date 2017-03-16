#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <complex>
#include <ctime>
#include <stack>
#include <thread>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef vector< vector<ll> > VVI;
typedef pair<ll, ll> PII;
typedef vector<PII> VPII;

#define REP(i, n) for(ll i = 0; i < n; ++i)
#define RREP(i, n) for(ll i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define RFOR(i, x, y) for(ll i = x; i >= y; --i)
#define SZ(a) (ll)(a).size()
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a)) 
#define CLEAR(x) memset(x,0,sizeof x);
#define COPY(FROM, TO) memcpy(TO, FROM, sizeof TO);
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define pb push_back
#define sqr(x) (x)*(x)
#define X first
#define Y second
#define y1 Y1
#define y2 Y2
const long double pi=acos(-1.0);
const long double eps = 1e-9;

int n, m;
int a[200][200];
int w[200][200];
int h[200][200];
int T;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	FOR(TEST, 1, T)
	{
		CLEAR(a);
		CLEAR(w);
		CLEAR(h);

		scanf("%d %d", &n, &m);
		FOR(i, 1, n)
			FOR(j, 1, m)
			{
				scanf("%d", &a[i][j]);
				FOR(t, a[i][j], 100)
				{
					++w[t][i];
					++h[t][j];
				}
			}

		string ans = "YES";
		FOR(i, 1, n)
			FOR(j, 1, m)
				if (w[a[i][j]][i] != m && h[a[i][j]][j] != n)
					ans = "NO";

		printf("Case #%d: %s\n", TEST, ans.c_str());
	}
}