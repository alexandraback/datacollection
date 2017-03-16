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
#include <ctime>
#include <stack>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
 
#define REP(i, n) for(int i = 0; i < n; ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(ll i = x; i <= y; ++i)
#define RFOR(i, x, y) for(int i = x; i >= y; --i)
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
const int MAXN = 201011;
const int INF = 1000000000;
const ll MOD = 1000000007;
 
int uu[300];
bool us[30];
int ans = 0;
string s[20];
int a[20];
int n;

void go(int pos)
{
	if (pos >= n)
	{
		 ++ans;
		 return;
	}
	
	REP(cur, n)
	if (!us[cur])
	{
		us[cur] = true;
		a[pos] = cur;
		bool ok = true;
		char prev = 0;
		if (pos) prev = s[a[pos - 1]][s[a[pos - 1]].size() - 1];
		for (char c : s[cur])
		{
			if (prev && prev != c && uu[c]) ok = false;
			prev = c;
			++uu[c];
		}		
		if (ok) go(pos + 1);
		for (char c : s[cur])
		{
			--uu[c];
		}
		us[cur] = false;
	}
}

int main()
{   
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int tests;
	scanf("%d\n", &tests);
	FOR(test, 1, tests)
	{
		CLEAR(a);
		CLEAR(us);
		CLEAR(a);
		cin >> n;
		REP(i, n) cin >> s[i];
		ans = 0;
		go(0);
		
		cout << "Case #" << test << ": " << ans << endl;
	}
} 
