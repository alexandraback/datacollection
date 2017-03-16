//Karol Kaszuba
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;

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

int mnoz[4][4] = {
	{1, 2, 3, 4},
	{2, -1, 4, -3},
	{3, -4, -1, 2},
	{4, 3, -2, -1}
};

int bla[1000];

int pomnoz(int a, int b)
{
	int wyn = 1;
	if(a < 0) wyn *= -1;
	if(b < 0) wyn *= -1;
	a = abs(a); b = abs(b);
	wyn *= mnoz[a - 1][b - 1];
	return wyn;
}

bool jebaj()
{
	LL l, x;
	cin >> l >> x;
	if(x > 12)
	{
		x = 12 + x % 4;
	}
	string s, t;
	cin >> s;
	REP(i, x) t = t + s;
	int res = 1;
	
	int pos = 0;
	while(pos < SIZE(t) && res != 2)
	{
		res = pomnoz(res, bla[t[pos]]);
		pos++;
	}
	if(pos == SIZE(t)) return false;
	res = 1;
	while(pos < SIZE(t) && res != 3)
	{
		res = pomnoz(res, bla[t[pos]]);
		pos++;
	}
	if(pos == SIZE(t)) return false;
	
	res = 1;
	while(pos < SIZE(t))
	{
		res = pomnoz(res, bla[t[pos]]);
		pos++;
	}
	
	return (res == 4);
	
}

int main()
{
bla['1'] = 1;
bla['i'] = 2;
bla['j'] = 3;
bla['k'] = 4;
	IOSYNC;	
	int t;
	t = 1;
	cin >> t;
	
	REP(i, t) 
	{
		cout << "Case #" << i + 1 << ": ";
		if(!jebaj()) cout << "NO\n";
		else cout << "YES\n";
	}
}
