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

void dorzuc(int a, set<int> &secik, int limit)
{
	set<int> tmp;
	for(auto b : secik) if(a + b <= limit) tmp.IN(a + b);
	for(auto b : tmp) secik.IN(b);
}

int mex(set<int> &secik, int limit)
{
	if(SIZE(secik) == limit + 1) return -1;
	int act = 0;
	auto it = secik.begin();
	while(it != secik.end() && *it == act)
	{
		it++;
		act++;
	}
	return act;
}


void jebaj()
{
	int c, d, lim;
	cin >> c >> d >> lim;
	VI val;
	REP(i, d)
	{
		int a;
		cin >> a;
		val.PB(a);
	}
	set<int> secik; secik.IN(0);
	
	for(auto a : val)
	{
		dorzuc(a, secik, lim);
	}
	int act = mex(secik, lim), res = 0;
	while(act != -1)
	{
		res++;
		dorzuc(act, secik, lim);
		act = mex(secik, lim);
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
