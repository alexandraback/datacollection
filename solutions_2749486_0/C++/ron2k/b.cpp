#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
	freopen("small", "r", stdin);
	freopen("output", "w", stdout);
	int cases;
	cin >> cases;

	int x,y;
	for (int caseNo = 0; caseNo < cases; caseNo ++)
	{
		cin >> x >> y;
		cout << "Case #" << caseNo + 1 << ": ";

		if (x > 0)
			for (int i  = 0; i < x; i ++)
				cout << "WE";
		else if (x < 0)
			for (int i  = 0; i < abs(x); i ++)
				cout << "EW";

		if (y > 0)
			for (int i  = 0; i < y; i ++)
				cout << "SN";
		else if (y < 0)
			for (int i  = 0; i < abs(y); i ++)
				cout << "NS";
		cout<< endl;
	}
	return 0;
}
