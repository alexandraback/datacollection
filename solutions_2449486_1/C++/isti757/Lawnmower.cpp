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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
#endif

    int T;
    cin >> T;

    REP(t, T) {
        int N, M;
        cin >> N >> M;

        set<int> vals;
        VVI brd(N, VI(M, 0));
        REP(i, N) {
            REP(j, M) {
                cin >> brd[i][j];
                vals.insert(brd[i][j]);
            }
        }

        while(vals.size() != 1) {
            int lo = *vals.lower_bound(0);
            int hi = *vals.upper_bound(lo);

            bool found = false;
            VB r(N, 0), c(M, 0);
            REP(i, N) {
                REP(j, M) {
                    if(brd[i][j] == lo) {
                        r[i] = true, c[j] = true;
                        REP(k, M) {
                            if(brd[i][k] != lo)
                                r[i] = false;
                        }

                        REP(k, N) {
                            if(brd[k][j] != lo)
                                c[j] = false;

                        }
                    }
                }
            }

            REP(i, N) {
                if(r[i]) {
                    found = true;
                    REP(j, M) {
                        brd[i][j] = hi;
                    }
                }
            }

            REP(j, M) {
                if(c[j]) {
                    found = true;
                    REP(i, N) {
                        brd[i][j] = hi;
                    }
                }
            }

            vals = set<int>();
            REP(i, N) {
                REP(j, M) {
                    vals.insert(brd[i][j]);
                }
            }

            if(!found) {
                break;
            }
        }

        if(vals.size() == 1) {
            printf("Case #%d: YES\n", (t+1));
        }
        else {
            printf("Case #%d: NO\n", (t+1));
        }
    }


    return 0;
}
