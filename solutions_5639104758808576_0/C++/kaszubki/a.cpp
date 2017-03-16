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

bool czek(int a, string &s)
{
	if(a < 0) return false;
	
	int ile = a;
	
	FOR(i, 0, SIZE(s) - 1)
	{
		if(s[i] > '0' && ile < i) 
		{
			return false;
		}
		ile += (s[i] - '0');
	}
	return true;
}

int binsercz(int n, string &s)
{
	int pocz = 0, kon = n;
	while(true)
	{
		int mid = (pocz + kon) / 2;
		if(czek(mid, s))
		{
			if(!czek(mid - 1, s)) return mid;
			kon = mid - 1;
		}
		else
		{
			if(czek(mid + 1, s)) return mid + 1;
			pocz = mid + 2;
		}
	}
	return 0;
}

void jebaj()
{
	int n;
	string s;
	cin >> n >> s;
	cout << binsercz(n, s) << "\n";
}

int main()
{
	IOSYNC;	
	int t;
	t = 1;
	cin >> t;
	
	REP(i, t) 
	{
		cout << "Case #" << i + 1 << ": ";
		jebaj();
	}
}
