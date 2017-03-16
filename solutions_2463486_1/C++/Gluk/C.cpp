#include <algorithm>
#include <string>
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

using namespace std;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define INF 1000000000
#define X first
#define Y second
#define pb push_back

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

bool isPalindrome(long long x) {
    VI a;
    while (x) {
        a.pb (x%10);
        x/=10;
    }
    REP (i, a.size()/2)
        if (a[i] != a[a.size()-1-i])
            return false;

    return true;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w+", stdout);

    vector<long long> res;
    REP (i, 10000001)
        if (isPalindrome(i)) {
            long long ii = i;
            ii*=i;
            if (isPalindrome(ii)) {
                res.pb(ii);
            }
        }

    int t;
    cin >> t;
    REP (tt, t) {
        std::cout << "Case #" << tt+1 << ": ";
        long long a, b;
        cin >> a >> b;
        int r = 0;
        REP (i, res.size())
            if (res[i] >= a && res[i] <= b)
                r++;

        cout << r << endl;
    }

    return 0;
}
