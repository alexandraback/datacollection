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



const double eps = 1.0e-11;
const double pi = acos(-1.0);

const int N = 10000010;
int counter[N];

bool check(ll num) {
	vector<int> digits;
	while(num) {
		digits.push_back(num % 10);
		num /= 10;
	}
	vector<int> copy = digits;
	reverse(ALL(copy));
	return copy == digits;
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	FOR(i, 1, N) {
		counter[i] = counter[i - 1];
		if (check(i) && check(i * i)) {
			++counter[i];
			// cerr << i * i << endl;
		}
	}

	int T;
	cin >> T;
	REP(TEST, T) {
		int l, r;
		cin >> l >> r;
		int left_bound = int(sqrt(l - eps)) + 1;
		int right_bound = int(sqrt(r + .0));
		// cout << left_bound << " " << right_bound << endl;
		printf("Case #%d: %d\n", TEST + 1, counter[right_bound] - counter[left_bound - 1]);
	}
	return 0;
}