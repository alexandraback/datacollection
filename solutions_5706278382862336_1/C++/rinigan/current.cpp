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
 
 
ll gcd(ll a, ll b)
{
	return b ? gcd (b, a % b) : a;	
}

ll solve(ll a, ll b)
{
	ll b1 = b;
	while (b1 % 2 == 0) b1 /= 2;
	if (b1 != 1) return -1;
	
	ll res = 0;
	ll d = 1;
	while (b > a * d)
	{
		if (res > 40) return -1;
		++res;
		d *= 2;
	}
	return res;
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
		ll p, q;
		scanf("%lld/%lld\n", &p, &q);
		ll g = gcd(p, q);
		p /= g;
		q /= g;
		ll r = solve(p, q);
		cout << "Case #" << test << ": ";
		if (r == -1) cout << "Impossible\n";
		else cout << r << endl;
	}
} 
