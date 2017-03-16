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
double solve(const vint& a, const vint& b)
{
    const int N = a.size();
    int A = 0;
    int point = 0;
    for(int B = 0; B < N; B++) {
#ifdef DEBUG
        cout << "B: " << B << " " << point << endl;
#endif
        while(true) {
            if(b[B] <= point) break; // ‚Æ‚ê‚é
            if(A >= N) return -1; // a‚ª‚à‚¤‚È‚¢
            if(a[A] > point) return -1; // a‚ª‚Æ‚ê‚È‚¢
            point += 1;
            A++;
        }
#ifdef DEBUG
        cout << "A: " << A << " " << point << endl;
#endif
        point+=2;
    }
    return N + A;
}
int main(void)
{
    int N; cin>>N;
    for(int n = 1; n <= N; n++) {
        int M; cin>>M;
        vector<int> a(M), b(M);
        REP(i,M) cin>>a[i]>>b[i];
        sort(ALL(a));
        sort(ALL(b));
        int ans = solve(a, b);
        if(ans < 0) {
            printf("Case #%d: Too Bad", n);
        } else {
            printf("Case #%d: %d", n, ans);
        }
        puts("");
    }
    return 0;
}
