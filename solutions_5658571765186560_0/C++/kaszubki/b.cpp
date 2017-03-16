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


int jebaj()
{
	int x, r, c;
	cin >> x >> r >> c;
	
	if(r > c) swap(r, c);
	
	if((r * c) % x) return 1;
	
	if(x >= 7) return 1;
	
	if(x <= 2) return 0;
	
	if(x == 3)
	{
		if(r == 1) return 1;
		return 0;
	}
	
	if(x == 4)
	{
		if(r == 1) return 1;
		if(r == 2) return 1;
		if(r == 3) return 0;
		if(r == 4) return 0;
	}
	return 1;
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
		if(jebaj()) 
		{
			cout << "RICHARD\n";
		}
		else 
		{
			cout << "GABRIEL\n";
		}
	}
}
