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
const ll MOD = 10000 * 10000 + 7 ;
inline void chadd(ll &a, const ll b) { a = (a + b) % MOD;}
inline ll add(const ll a, const ll b){ return (a + b) %  MOD;}
inline void chsub(ll &a, const ll b) { a = (a - b + MOD) % MOD;}
inline ll sub(const ll a, const ll b){ return (a - b + MOD) % MOD; }
inline void chmul(ll &a, const ll b) { a = (a * b) %  MOD;}
inline ll mul(const ll a, const ll b){ return (a * b) %  MOD;}
#endif
int solve(void)
{
    int ans = 0;
    int A, B; cin>>A>>B;
    set<pint> sans;
    for(int m = A; m <= B; m++) {
        char buf[256];
        sprintf(buf, "%d", m);
        string num(buf);
        //cout << num << endl;
        bool ok = false;
        for(int i = 1; i < num.size(); i++) {
//            set<int> s; int tmp = 0;
            string cand = num.substr(i) + num.substr(0,i);
            //cout << cand << endl;
            //if(cand[0] == '0') continue;
            int n; sscanf(cand.c_str(), "%d", &n);
            if(A <= n && n < m) {
//                s.insert(n);
                sans.insert(mp(n,m));
//                tmp++;
//                cout << n << "," << m << endl;
            }
//            if(s.size() != tmp) cout << m << endl;
//            ans += s.size();
        }
    }
    return sans.size();
//    return ans;
}
int main(void)
{
    int N; cin>>N;
    for(int n = 1; n <= N; n++) {
        int ans = solve();
        cout << "Case #" << n << ": "  << ans << endl;
    }
    return 0;
}
