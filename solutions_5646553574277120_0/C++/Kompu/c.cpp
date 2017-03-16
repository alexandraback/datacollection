#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef long long LL;
typedef vector<LL> VLL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

int main()
{
	int t;
	cin >> t;
	FOR(o, 1, t)
	{
		int c, d, v, r = 0;
		cin >> c >> d >> v;
		VI coins(d);
		REP(x, d)
		{
			cin >> coins[x];
		}
		vector<bool> can(v + 1, false);
		can[0] = true;

		REP(x, d)
		{
			FORD(y, v, 0) if(can[y] && y + coins[x] <= v)
			{
				can[y + coins[x]] = true;
			}
		}
		// REP(x, v + 1)
		// {
		// 	if(can[x]) cout << x << " ";
		// }
		// cout << endl;
		while(true)
		{
			int p = -1;
			REP(x, SIZE(can))
			{
				if(!can[x])
				{
					p = x;
					break;
				}
			}
			if(p == -1) break;
			FORD(y, v, 0) if(can[y] && y + p <= v)
			{
				can[y + p] = true;
			}
			r++;
		}
		cout << "Case #" << o << ": " << r << endl;
	}
	return 0;
}