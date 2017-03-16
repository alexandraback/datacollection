#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define FOREQ(i,a,b) for(int i = a; i <= (int)b; i++)
#define FOREACH(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define SZ(c) (c).size()
template <class T> void pp(T v) { FOREACH(it, v) cout << *it << ' '; cout << endl ; }
template <class T> void pp(T v, int n) { REP(i,n) cout<<v[i]<< ' '; cout << endl; }
template <class T> inline void chmax(T &a, const T b) { a = max(a, b); }
template <class T> inline void chmin(T &a, const T b) { a = min(a, b); }
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef complex<double> P;
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef unsigned uint;
const int INF = 1<<28;
const double EPS = 1.0e-9;
static const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
#undef MOD_CALC
#ifdef MOD_CALC
const ll MOD = 1000 * 1000 * 1000 + 7 ; // 1000000007
inline void chadd(ll &a, const ll b) { a = (a + b) % MOD;}
inline ll add(const ll a, const ll b){ return (a + b) %  MOD;}
inline void chsub(ll &a, const ll b) { a = (a - b + MOD) % MOD;}
inline ll sub(const ll a, const ll b){ return (a - b + MOD) % MOD; }
inline void chmul(ll &a, const ll b) { a = (a * b) %  MOD;}
inline ll mul(const ll a, const ll b){ return (a * b) %  MOD;}
#endif
int solve(void)
{
    int E, R, N; cin>>E>>R>>N;
    vint v(N, 0);
    REP(i,N)cin>>v[i];
    int dp[N+1][E+1] ;
    memset(dp, 0, sizeof(dp));
    REP(n,N) {
        for(int e = 0; e <= E; e++) {
            for(int useE = 0; useE <= e; useE++) {
                const int nxtE = min(e - useE + R, E);
                chmax(dp[n+1][nxtE], dp[n][e] + useE * v[n]);
            }
        }
    }
#ifdef DEBUG
    REP(e,E+1) {
        REP(n,N+1) {
            cout << dp[n][e] << " ";
        }
        cout << endl;
    }
#endif
    int ans = 0;
    REP(e,E+1) chmax(ans, dp[N][e]);
    return ans;
}

int main(void)
{
    int T; cin>>T;
    for(int case_no = 1; case_no <= T; case_no++) {
        int ans = solve();
        cout << "Case #" << case_no << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}

