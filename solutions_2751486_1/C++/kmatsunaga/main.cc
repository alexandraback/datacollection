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

bool isvowel(int c)
{
    switch (c)
    {
    case 'a': return true;
    case 'e': return true;
    case 'i': return true;
    case 'o': return true;
    case 'u': return true;
    }
    return false;
}

ll solve(const string L, const int N)
{
    ll ans = 0;
    int len = L.length();
    int right = 0;
    int add = 0;
    for(int i = 0; i < len; i++) {
        if(isvowel(L[i])) {
            right = 0;
        } else {
            right ++;
        }
        if(right >= N) {
            add = i - N + 2;
            ans += add;
        } else {
            ans += add;

        }
            //cout << i << " " << right << " " << ans << endl;
    }
    return ans;
}

int main(void)
{
    int T; cin>>T;
    for(int case_no = 1; case_no <= T; case_no++) {
        int n;
        string L;
        cin>>L>>n;
        ll ans = solve(L, n);
        cout << "Case #" << case_no << ": ";
        cout << ans << endl;

    }
    return 0;
}
