#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <functional>
using namespace std;

typedef	long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, p, k) for(int i = (p); i <= (k); ++i)
#define FOREACH(x,Z) for(__typeof((Z).begin()) x=(Z).begin();x!=(Z).end();++x)

#define PB(x) push_back(x)
#define MP(x, y) make_pair((x), (y))

vector<pair<ll, int> > nv, mv;

void input()
{
	int n, m;
	scanf("%d %d", &n, &m);
	REP(i, n)
	{
		ll c;
		int t;
		scanf("%lld %d", &c, &t);
		if(nv.size() && nv.back().second == t) nv.back().first += c;
		else nv.PB(MP(c, t));
	}
	
	REP(i, m)
	{
		ll c;
		int t;
		scanf("%lld %d", &c, &t);
		if(mv.size() && mv.back().second == t) mv.back().first += c;
		else mv.PB(MP(c, t));
	}
	reverse(nv.begin(), nv.end());
	reverse(mv.begin(), mv.end());
}

ll solve()
{
	ll res = 0;
	if(nv.size())
	{
		pair<ll, int> nvb = nv.back();
		nv.pop_back();
		res = solve();
		nv.PB(nvb);
		
		vector< pair<ll, int> > S;
		while(mv.size() && mv.back().second != nv.back().second)
		{
			S.PB(mv.back());
			mv.pop_back();
		}
		
		if(mv.size())
		{
			ll k = min(mv.back().first, nv.back().first);
			pair<ll, int> nvb = nv.back(), mvb = mv.back();
			
			if(mv.back().first == k) mv.pop_back();
			else mv.back().first -= k;
			
			if(nv.back().first == k) nv.pop_back();
			else nv.back().first -= k;
			
			ll res2 = solve() + k;
			if(res2 > res) res = res2;
			
			if(mvb.first == k) mv.PB(mvb);
			else mv.back().first += k;
			
			if(nvb.first == k) nv.PB(nvb);
			else nv.back().first += k;
			
		}
		
		while(S.size())
		{
			mv.PB(S.back());
			S.pop_back();
		}
	}
	return res;
}

int main()
{
	int Z;
	scanf("%d", &Z);
	FOR(t, 1, Z)
	{
		input();
		printf("Case #%d: %lld\n", t, solve());
		nv.clear();
		mv.clear();
	}
	return 0;
}
