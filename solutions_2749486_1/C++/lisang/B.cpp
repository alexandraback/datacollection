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

char dir[] = {'E', 'N', 'W', 'S'};

void move(int d, int flag) {
	if (d > 0) {
		REP(i, d) {
			cout << dir[2 + flag] << dir[flag];
		}
	}
	else {
		d *= -1;
		REP(i, d) {
			cout << dir[flag] << dir[2 + flag];
		}
	}
}

int step_count(int x, int y) {
	int sum = abs(x) + abs(y);
	int curr = 0;
	int i = 0;
	while(curr < sum || (curr % 2 != sum % 2)) {
		++i;
		curr += i;
	}
	return i;
}



void solve() {
	int x, y;
	cin >> x >> y;
	int s = step_count(x, y);
	string res;
	FORD(i, s, 1) {
		if (abs(x) > abs(y)) {
			if (x > 0) {
				x -= i;
				res += dir[0];
			}
			else {
				x += i;
				res += dir[2];
			}
		}
		else {
			if (y > 0) {
				y -= i;
				res += dir[1];
			}
			else {
				y += i;
				res += dir[3];
			}
		}
	}
	reverse(ALL(res));
	cout << res << endl;
	if (x || y) {
		cout << "FAIL\n";
	}
}


int main() {
	freopen("B-large.in", "r", stdin);
	freopen("outputB", "w", stdout);

	int T;
	cin >> T;
	REP(test, T) {
		printf("Case #%lld: ", test + 1);
		solve();
	}
	return 0;
}