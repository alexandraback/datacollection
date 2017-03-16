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

int Play(int c, int w)
{
	int r = 0;
	while(c > (2 * w))
	{
		c -= w;
		r++;
	}
	if(c > w) r += 1;
	r += w;
	return r;
}

int main()
{
	int t;
	cin >> t;
	FOR(o, 1, t)
	{
		int r, c, w, res;
		cin >> r >> c >> w;
		res = (r - 1) * (Play(c, w) - w + 1) + Play(c, w);
		cout << "Case #" << o << ": " << res << endl;
	}
	return 0;
}