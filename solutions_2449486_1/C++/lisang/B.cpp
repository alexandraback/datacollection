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
const int N = 110;

int d[N][N];
int row[N], col[N];


int main() {
	freopen("B-large.in", "r", stdin);
	freopen("outputB.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	REP(TEST, T) {

		CLEAR(row);
		CLEAR(col);

		int n, m;		
		scanf("%d%d", &n, &m);

		REP(i, n) {
			REP(j, m) {
				scanf("%d", &d[i][j]);
				row[i] = max(row[i], d[i][j]);
				col[j] = max(col[j], d[i][j]);
			}
		}

		bool ok = true;
		REP(i, n) {
			REP(j, m) {
				if (d[i][j] < min(row[i], col[j]))
					ok = false;
			}
		}

		if (ok)
			printf("Case #%d: YES\n", TEST + 1);
		else
			printf("Case #%d: NO\n", TEST + 1);
	}
	return 0;
}