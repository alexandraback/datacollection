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
const int MAXN = 1e3 + 100;

int p[MAXN];


int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	//freopen("", "w", stderr);
    int T;
    cin >> T;
    FOR(test, T) {
        int n;
        cin >> n;
        FOR(i,n) {
            cin >> p[i];
        }
        int ans = INF;
        for (int mx = 1; mx <= 1000; ++mx) {
            int cur = mx;
            FOR(i,n)
                if (p[i] > mx)
                    cur += (p[i] - 1)/ mx;
            ans = min(ans, cur);
        }
        cout << "Case #" << test + 1 << ": " << ans << '\n';

    }

	
	return 0;
}

