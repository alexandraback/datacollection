#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 1e5;

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	//freopen("", "w", stderr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
	    int mx;
	    cin >> mx;
	    string s;
	    cin >> s;
	    int sum = 0;
	    int ans = 0;
	    FOR(i, mx + 1) {
	        int lst = s[i] - '0';
	        if (sum < i) {
	            int dt = i - sum;
	            sum += dt;
	            ans += dt;
	        }
	        sum += lst;
	    }
	    cout << "Case #" << t << ": " << ans << '\n';

	}
	
	return 0;
}

