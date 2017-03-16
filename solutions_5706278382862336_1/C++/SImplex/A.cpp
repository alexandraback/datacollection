#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <set>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <map>
using namespace std;

#define forn(i,n) for(int i = 0; i < (int)n; ++i)
#define _mp(a,b) make_pair(a,b)
#define _pb(x) push_back(x)
#define mins(a,b) a = min(a,b)
#define maxs(a,b) a = max(a,b)

bool ok(long long p, long long q)
{
    forn(i,41)
        if (1LL << i == q)
            return true;
    return false;
}

long long solve(long long p, long long q)
{
    forn(i, 41)
    {
        long long t = 1LL << i;
        if (t*p >= q)
            return i;
    }
    return -1;
}

int main() {
   ios_base::sync_with_stdio(false);
//    cout << fixed;
//    cout << setprecision(9);
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T = 0;
    cin >> T;
    forn(test, T)
    {
        long long p,q;
        char c;
        cin >> p;
        cin >> c;
        cin >> q;
        long long d = __gcd(p,q);
        p /= d;
        q /= d;
        cout << "Case #" << test + 1 << ": ";
        if (ok(p,q))
            cout << solve(p,q) << "\n";
        else
            cout << "impossible\n";
    }

    return 0;
}
