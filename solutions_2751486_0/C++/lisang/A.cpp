#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <utility>
#include <functional>
#include <bitset>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;


#define FOR(i, x, y) for(ll i=x; i<=y; i++)
#define FORD(i, x, y) for (ll i = x; i >= y; --i)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REPD(i, n) for(ll i = n - 1; i >= 0; --i) 

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define UNIQ(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define SZ(c) (int)(c).size()

#define CLEAR(x) memset(x,0,sizeof x)
#define FILL(x,v) memset(x,v,sizeof x)

#define pb push_back
#define mp make_pair
#define X first
#define Y second



const double eps = 1.0e-11;
const double pi = acos(-1.0);

char cons[] = {'a', 'e', 'o', 'u', 'i'};

bool check(char c) {
	REP(i, 5)
		if (c == cons[i])
			return true;
	return false;
}

ll solve() {
	string s;
	int n;
	cin >> s >> n;

	ll res = 0;
	int curr = 0;
	int last = SZ(s);
	REPD(i, SZ(s)) {
		if (!check(s[i]))
			++curr;
		else
			curr = 0;		
		if (curr >= n)
			last = i + n - 1;
		res += SZ(s) - last;
	}
	return res;
}


int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("outputA", "w", stdout);

	int T;
	cin >> T;
	REP(test, T) {
		printf("Case #%lld: %lld\n", test + 1, solve());
	}
	return 0;
}