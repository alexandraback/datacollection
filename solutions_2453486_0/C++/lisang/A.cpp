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
#define REP(i, n) for(int i=0; i<n; i++)
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



const double eps = 1.0e-10;
const double pi = acos(-1.0);

string data[4];

bool check(char c) {
	bool main_ok = true;
	bool other_ok = true;
	REP(i, 4) {
		if (data[i][i] != c && data[i][i] != 'T') {	main_ok = false;	}
		if (data[i][3 - i] != c && data[i][3 - i] != 'T') { other_ok = false;	}

		bool row_ok = true;
		bool col_ok = true;
		REP(j, 4) {
			if (data[i][j] != c && data[i][j] != 'T') {	row_ok = false;	}
			if (data[j][i] != c && data[j][i] != 'T') { col_ok = false;	}
		}
		if (row_ok || col_ok)
			return true;
	}
	return (main_ok || other_ok);
}

int count() {
	int counter = 0;
	REP(i, 4)
		REP(j, 4)
			counter += (data[i][j] != '.');
	return counter;
}



int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("outputA.txt", "w", stdout);

	int T;
	cin >> T;
	REP(TEST, T) {		
		REP(i, 4)
			cin >> data[i];

		if (check('X')) {
			printf("Case #%d: X won\n", TEST + 1);
			continue;
		}
		if (check('O')) {
			printf("Case #%d: O won\n", TEST + 1);
			continue;
		}
		if (count() == 16) {
			printf("Case #%d: Draw\n", TEST + 1);
			continue;
		}
		printf("Case #%d: Game has not completed\n", TEST + 1);

		//printf("Case #%d: %d\n", TEST + 1, counter[right_bound] - counter[left_bound - 1]);
	}
	return 0;
}