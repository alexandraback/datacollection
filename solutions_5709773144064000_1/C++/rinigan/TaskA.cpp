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
typedef vector<ll> VI;
typedef vector< vector<ll> > VVI;
typedef pair<ll, ll> PII;
typedef vector<PII> VPII;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
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

int ans1, ans2;
int	line1[20], line2[20];
int x;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	int tests;
	cin >> tests;
	FOR(test, 1, tests)
	{
		double c, f, x;
		cin >> c >> f >> x;
		double ans = x / 2.0;
		double t = 0;
		double prod = 2.0;
		FOR(farms, 1, 1000000)
		{
			t = t + c / prod;
			
			prod += f;
			double ans1 = t + x / prod;
			ans = min(ans, ans1);
		}	
		
		printf("Case #%d: %.12lf\n", test, ans);
	
	}
}
