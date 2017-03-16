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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define RFOR(i, x, y) for(int i = x; i >= y; --i)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a)) 
#define CLEAR(x) memset(x, 0, sizeof x);
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

int tests;
string s;
int n;
char cons[] = {'a', 'e', 'i', 'o', 'u'};

bool f(char c)
{
	REP(i, 5) if (c == cons[i]) return false;
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("A-large.in.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> tests;
	FOR(T, 1, tests)
	{
		cin >> s >> n;
		ll len = s.size();
		ll ans = len * (len + 1) / 2;
		int p2 = -1;
		int cur = 0;
		REP(p1, s.size())
		{
			while(cur < n)
			{
				if (p2 == s.size()) break;
				++p2;
				if (p2 == s.size()) break;
				if (f(s[p2])) ++cur;
				else cur = 0;
			}
			ans -= (p2 - p1);
			if (p2 - p1 + 1 == n) --cur;
		}
		printf("Case #%d: ", T);
		cout << ans << endl;
	}
}
