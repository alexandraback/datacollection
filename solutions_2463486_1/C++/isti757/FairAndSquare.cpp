#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define F first
#define S second
#define PB push_back
#define PF push front
#define MP make_pair
#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define VAR(v,n) __typeof(n) v=(n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define MOD(x, n) ((x)%(n)+(n))%(n)
#define SZ(x) (int((x).size()))
#define ALL(x) ((x).begin()),((x).end())
#define SORT(v) sort((v).begin(),(v).end())
#define REV(v) reverse((v).begin(),(v).end())
#define UNIQUE(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
LL GCD( LL a , LL b ) { while( b ) b ^= a ^= b ^= a %= b ; return a ; }
LL LCM( LL a , LL b ) { return a * ( b / GCD( a , b ) ) ; }

typedef vector<int>    VI;
typedef vector<VI>     VVI;
typedef vector<LL>     VLL;
typedef vector<bool>   VB;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII>    VPII;
typedef pair<LL, LL>   PLL;
typedef vector<PLL>    VPLL;

const double EPS = 10e-9;
const LL INF = (1LL << 30);

using namespace std;

bool isPoly(LL n) {
    int sz = 0;
    int digs[15];
    for(int i = 0; n > 0 ; n /= 10, i++) {
        digs[i] = n % 10;
        sz++;
    }

    for(int i = 0; i < sz/2; i++) {
        if(digs[i] != digs[sz-i-1])
            return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
#endif

    LL MINA = 1, MAXB = 100000000000000;

    set<LL> poly;
    for(LL i = MINA; i*i <= MAXB; i++) {
        if(isPoly(i) && isPoly(i*i)) {
            poly.insert(i*i);
        }
    }

    int T;
    scanf("%d", &T);

    REP(t, T) {
        LL A, B;
        scanf("%lld %lld", &A, &B);

        auto lo = poly.lower_bound(A);
        auto hi = poly.upper_bound(B);
        printf("Case #%d: %lld\n", (t+1), distance(lo, hi));
    }

    return 0;
}
