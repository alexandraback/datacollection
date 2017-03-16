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

int T;
string ans[] = {"X won", "O won", "Draw", "Game has not completed"};
string a[4];

bool win(char c)
{
	REP(i, 4)
	{
		int k1 = 0, k2 = 0;
		REP(j, 4)
		{
			if (a[i][j] == c || a[i][j] == 'T')
				++k1;
			if (a[j][i] == c || a[j][i] == 'T')
				++k2;
		}
		if (k1 == 4 || k2 == 4) 
			return true;		
	}

	int k1 = 0, k2 = 0;
	REP(i, 4)
	{
		if (a[i][i] == c || a[i][i] == 'T')
			++k1;

		if (a[i][3 - i] == c || a[i][3 - i] == 'T')
			++k2;
	}
	return k1 == 4 || k2 == 4;
}

string solve()
{
	if (win('X')) return ans[0];
	if (win('O')) return ans[1];
	REP(i, 4)
		REP(j, 4)
			if (a[i][j] == '.')
				return ans[3];
	return ans[2];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	FOR(TEST, 1, T)
	{
		REP(i, 4)
			cin >> a[i];
		printf("Case #%d: %s\n", TEST, solve().c_str());
	}
}