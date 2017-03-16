//Karol Kaszuba

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;
typedef unordered_set<int> USI;
typedef unordered_set<LL> USLL;

#define FOR(i,x,y) for(auto i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(auto i=(x);i>=(y);--i)
#define VAR(i,c) __typeof(c) i=(c)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define SIZE(c) (int)((c).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define IN insert
#define ER erase
#define MP make_pair
#define ST first
#define ND second
#define IOSYNC ios_base::sync_with_stdio(0)
#define FREOPEN(f) freopen(f, "r", stdin),freopen(f, "w", stdout)

LL solve(LL n, LL w)
{
	LL res = 0;
	while(n >= 3 * w)
	{
		res += 2;
		n -= 2 * w;
	}
	if(n == w)
	{
		return res + w;
	}
	else
	{
		if(n <= 2 * w)
		{
			return res + w + 1;
		}
		return res + w + 2;
	}
}

LL make_sure_empty(LL n, LL w)
{
	LL res = 0;
	while(n >= w)
	{	
		res++;
		n -= w;
	}
	return res;
}

void jebaj()
{
	LL n, m, w;
	cin >> n >> m >> w;
	cout << make_sure_empty(m, w) * (n - 1) + solve(m, w) << "\n";
}

int main()
{
	IOSYNC;
	int t = 1;
	cin >> t;
	
	REP(i, t)
	{
		cout << "Case #" << i + 1 << ": ";
		jebaj();
	}
}
