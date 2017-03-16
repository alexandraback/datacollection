#ifndef STDAFX_H
#define STDAFX_H

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
#define REVERSE(v) reverse((v).begin(),(v).end())
#define UNIQUE(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
LL GCD( LL a , LL b ) { while( b ) b ^= a ^= b ^= a %= b ; return a ; }
LL LCM( LL a , LL b ) { return a * ( b / GCD( a , b ) ) ; }

typedef vector<int>    VI;
typedef vector<string> VS;
typedef vector<VI>     VVI;
typedef vector<LL>     VLL;
typedef vector<bool>   VB;
typedef vector<double> VD;
typedef vector<VD>     VVD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII>    VPII;
typedef pair<LL, LL>   PLL;
typedef vector<PLL>    VPLL;

const double EPS = 10e-9;
const double PI = acos(-1.0);
const LL INF = (1LL << 30);

using namespace std;

template<typename T>
string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

bool intersect(int w1, int e1, int w2, int e2) {
    return !(e1 < w2) && !(w1 > e2);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    REP(t, T) {
        int N;
        cin >> N;

        VI d(N, 0), n(N, 0), w(N, 0), e(N, 0), s(N, 0), dd(N, 0), dp(N, 0), ds(N, 0);
        REP(i, N) {
            cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
        }

        int cnt = 0;
        REP(i, N) { // for each tribe
            REP(ni, n[i]) { // for each day
                // find if the current interval is covered by previous attacks
                VPII attacks;
                int si = s[i]+ni*ds[i];
                int dayi = d[i]+dd[i]*ni;
                int cwi = w[i]+dp[i]*ni, cei = e[i]+dp[i]*ni;
                REP(j, N) {
                    if(j == i) continue;
                    REP(nj, n[j]) {
                        int dayj = d[j]+dd[j]*nj, sj = s[j]+ds[j]*nj;
                        if(dayj >= dayi) break;
                        int cwj = w[j]+dp[j]*nj, cej = e[j]+dp[j]*nj;
                        if(intersect(cwi, cei, cwj, cej) && sj >= si)
                            attacks.push_back({cwj, cej});
                    }
                }

                SORT(attacks);
                int posMax = cwi;
                bool breach = false;
                REP(a, attacks.size()) {
                    if(attacks[a].first > posMax)
                        breach = true;
                    else
                        posMax = max(posMax, attacks[a].second);
                }
                if(posMax < cei)
                    breach = true;
                cnt += breach;
            }
        }

        printf("Case #%d: %d\n", (t+1), cnt);
    }

    return 0;
}

#endif // STDAFX_H

