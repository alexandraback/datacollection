#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;

bool check(int len, int x, int y, bool print)
{
	if (len == 0)
	{
		return (x == 0) && (y == 0);
	}
	if (abs(x) > abs(y))
	{
		if (x < 0)
		{
			bool res = check(len-1, x+len, y, print);
			if (print) cout << 'W';
			return res;
		}
		else
		{
			bool res = check(len-1, x-len, y, print);
			if (print) cout << 'E';
			return res;
		}
	}
	else
	{
		if (y < 0)
		{
			bool res = check(len-1, x, y+len, print);
			if (print) cout << 'S';
			return res;
		}
		else
		{
			bool res = check(len-1, x, y-len, print);
			if (print) cout << 'N';
			return res;
		}
	}
}

int main()
{
	int ntest; cin >> ntest;
	FOR(test,1,ntest)
	{
		int x, y; cin >> x >> y;
		cout << "Case #" << test << ": ";
		FOR(len,1,1000000)
		if (check(len, x, y, false))
		{
			check(len, x, y, true);
			break;
		}
		puts("");
	}
	return 0;
}
