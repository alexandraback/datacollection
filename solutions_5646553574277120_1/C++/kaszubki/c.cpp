//Karol Kaszuba

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<LL> VI;
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


void jebaj()
{
	LL c, d, lim;
	cin >> c >> d >> lim;
	VI val;
	REP(i, d)
	{
		LL a;
		cin >> a;
		val.PB(a);
	}
	
	sort(ALL(val));
	LL koniec = 0;
	int pos = 0;
	LL res = 0;
	while(koniec < lim)
	{
		if(pos == SIZE(val) || val[pos] > koniec + 1)
		{
			res++;
			koniec += (koniec + 1) * c;
		}
		else
		{
			koniec += val[pos] * c;
			pos++;
		}
	}
	cout << res << "\n";
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
