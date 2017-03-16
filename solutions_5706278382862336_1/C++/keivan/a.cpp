#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>

using namespace std;

#define FOREACH(i, c) for(__typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for(__typeof(n) i = (a); i<(n); ++i)
#define REP(i, a, n) for(__typeof(n) i = (a); i<=(n); ++i)
#define ROF(i, n, a) for(__typeof(n) i = (n); i>=(a); --i)
#define error(n) cout << #n << " = " << n << endl
#define all(c) c.begin(), c.end()
#define pb push_back
#define po pop_back
#define Size(n) ((int)(n).size())
#define X first
#define Y second
#define scanf _ = scanf
// #define X real()
// #define Y imag()

typedef long long   ll ;
typedef long double ld ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll;

int T;

pll Fraction(string s) {
    pll ans = pll(0,0);
    int id = 0;
    while (s[id] != '/') {
        ans.X = ans.X*10+(s[id]-'0');
        ++id;
    }
    ++id;
    while (id < Size(s)) {
        ans.Y = ans.Y*10+(s[id]-'0');
        ++id;
    }
    return ans;
}

int MSB(ll a) {
    int ans = 0;
    while(a > 1)
        a /= 2 , ++ans;
    return ans;
}

bool PowerTwo(ll a) {
    return a == (1ll<<MSB(a)) ;
}

int main() {
    cin >> T;
    REP (lv,1,T) {
        cout << "Case #" << lv << ": ";
        string s;
        cin >> s;
        pll f = Fraction(s);
        ll g = __gcd(f.X,f.Y);
        f.X /= g , f.Y /= g;
        if (!PowerTwo(f.Y)) {
            cout << "impossible" << endl;
        } else {
            ll p = f.X*((1ll<<40)/f.Y);
            cout << 40-MSB(p) << endl;
        }
    }
    return 0 ;
}
