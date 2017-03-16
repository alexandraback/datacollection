#include <cstring>
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
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

string testname = "C-small-attempt0";

long long a[32];

int main () {
    freopen((testname+".in").c_str(), "r", stdin);
    freopen((testname+".out").c_str(), "w", stdout);
    int t;
    cin >> t;
    FOR (test, 1, t+1) {
	int n;
	cin >> n;
	REP (i, n) cin >> a[i];
	map<ll, int> b;
	printf("Case #%d:\n", test);
	bool good = false;
	REP (i, 1<<n) {
	    ll S = 0;
	    REP (j, n)
		if (i & (1<<j)) S += a[j];
	    if (b.count(S)) {
		vector<int> q, w;
		REP (j, n) {
		    if (i & (1<<j))
			q.pb(j);
		    if (b[S] & (1<<j))
			w.pb(j);
		}
		REP (j, sz (q)) {
		    if (j) cout << ' ';
		    cout << a[q[j]];
		}
		cout << endl;
		REP (j, sz (w)) {
		    if (j) cout << ' ';
		    cout << a[w[j]];
		}
		cout << endl;
		good = true;
		break;
	    }
	    b[S] = i;
	}
	if (!good) cout << "Impossible\n";
    }
    return 0;
}
