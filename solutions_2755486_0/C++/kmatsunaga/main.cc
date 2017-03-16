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

struct Attack {
    int d, w, e, s;
};
inline bool operator < (const Attack &a, const Attack &b)
{
    return a.d < b.d;
}
inline bool operator > (const Attack &a, const Attack &b)
{
    return b < a;
}

int main(void)
{
    int T; cin>>T;
    //cout << T << endl;
    for(int case_no = 1; case_no <= T; case_no++) {
        int N; cin>>N;
        //cout << N << endl;
        priority_queue <Attack, vector<Attack>, greater<Attack> > q;
        int d, n, w, e, s, delta_d, delta_p, delta_s;
        int wmax = -100, emax = 100;
        REP(i,N){
            cin >> d >> n >> w >> e >> s >> delta_d >> delta_p >> delta_s;
            //cout << d << n << w << e << s << delta_d << delta_p << delta_s << endl;
            for(int i = 1; i <= n; i++) {
                q.push((Attack){d, w, e, s});
                chmin(wmax, w);
                chmax(emax, e);
                d += delta_d;
                w += delta_p;
                e += delta_p;
                s += delta_s;
            }
            //cout << q.size() << endl;
        }
        int ans = 0;
        int old = -1;
        vector<Attack> rec;
        vector<int> height(emax - wmax, 0);
        while(q.empty() == false) {
            Attack attack = q.top(); q.pop();
#ifdef DEBUG
            cout << attack.d << " " << attack.w << " " << attack.e << " " << attack.s << endl;
#endif
            if(attack.d == old) {
                rec.push_back(attack);
            } else { // attack.d > old
                // èCïúÇ∑ÇÈ
#ifdef DEBUG
                cout << "Repair....." << endl;
#endif
                REP(i, rec.size()) {
                    for(int p = rec[i].w ; p < rec[i].e; p++) {
                        int idx = p - wmax;
                        chmax(height[idx], rec[i].s);
#ifdef DEBUG
                        cout << idx << "->" << rec[i].s << endl;
#endif
                    }
                }
                rec.clear();
                rec.push_back(attack);
            }
#ifdef DEBUG
            pp(height);
#endif
            old = attack.d;
            bool success = false;
            for(int p = attack.w;  p < attack.e; p++) {
                int idx = p - wmax;
                if(attack.s > height[idx]) success = true;
            }
            if(success) ans++;
#ifdef DEBUG
            cout << (success ? "OK" : "NG") << endl;
#endif
        }
#ifdef DEBUG
        cout << wmax << "," << emax << endl;
#endif
        cout << "Case #" << case_no << ": ";
        cout << ans << endl;

    }
    return 0;
}
