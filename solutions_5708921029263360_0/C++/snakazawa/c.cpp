#include <bits/stdc++.h>
using namespace std;

typedef ostringstream OSS; typedef istringstream ISS;
typedef long long LL;
typedef pair<int, int> PII;  typedef pair<LL, LL> PLL;
typedef vector<int>    VI;   typedef vector<VI>   VVI;   typedef vector<VVI>   VVVI;
typedef vector<LL>     VLL;  typedef vector<VLL>  VVLL;  typedef vector<VVLL>  VVVLL;
typedef vector<double> VD;   typedef vector<VD>   VVD;   typedef vector<VVD>   VVVD;
typedef vector<string> VS;   typedef vector<VS>   VVS;   typedef vector<VVS>   VVVS;
typedef vector<bool>   VB;   typedef vector<VB>   VVB;   typedef vector<VVB>   VVVB;
typedef vector<PII>    VPII; typedef vector<VPII> VVPII; typedef vector<VVPII> VVVPII;
typedef vector<PLL>    VPLL; typedef vector<VPLL> VVPLL; typedef vector<VVPLL> VVVPLL;

typedef unsigned int  UI;
typedef vector<UI>    VUI;
typedef vector<VUI>   VVUI;

#define fst first
#define snd second
// #define Y first
// #define X second
#define MP make_pair
#define PB push_back
#define EB emplace_back 
#define ALL(x)  (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define RANGEBOX(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))
#define RANGE(x, l, r) ((l) <= (x) && (x) <= (r))
#define rep(i, N)  for (int i = 0; i < (int)(N); i++)
#define rrep(i, N) for (int i = N - 1; i >= 0; i--)
#define REP(i, init, N)  for (int i = (init); i < (int)(N); i++)
#define RREP(i, N, last) for (int i = (init - 1); i >= last; i--)
#define MAXUD(orig, target) orig = max(orig, target)
#define MINUD(orig, target) orig = min(orig, target)
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

template < typename T > inline T fromString(const string &s) { T res; ISS iss(s); iss >> res; return res; };
template < typename T > inline string toString(const T &a)   { OSS oss; oss << a; return oss.str(); };

template<typename T=int> inline void dump(vector<T> vs, bool ent=false) { rep(i, vs.size()) cout << vs[i] << (i+1==vs.size() ? '\n' : ' '); if (ent) cout << endl; }
template<typename T = int> inline void dump(vector<vector<T>> vs, bool ent = false) { rep(i, vs.size()) dump<T>(vs[i]); if (ent) cout << endl; }

const int    INF  = 0x3f3f3f3f;
const LL     INFL = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = 0x3f3f3f3f;
const int    DX[] = {1,  0, -1, 0};
const int    DY[] = {0, -1,  0, 1};
const double EPS  = 1e-12;
// const double PI   = acos(-1.0);
// lambda: [](T1 x)->T2{return y;}
// simple lambda: [](T x){return x;}

VVI solve() {
    int J, P, S, K;
    cin >> J >> P >> S >> K;

    VVI xs;
    rep(j, J) rep(p, P) rep(s, S) {
        xs.PB({j, p, s});
    }
    int xn = xs.size();

    int ans = 0;
    for (int q = (1 << xn) - 1; q; --q) {
        if (__builtin_popcount(q) < ans) continue;

        VVI jp(J, VI(P));
        VVI ps(P, VI(S));
        VVI sj(S, VI(J));
        bool ok = true;
        rep(i, xn) {
            if (!(q >> i & 1)) continue;

            int j = xs[i][0];
            int p = xs[i][1];
            int s = xs[i][2];

            if (++jp[j][p] > K) { ok = false; break; }
            if (++ps[p][s] > K) { ok = false; break; }
            if (++sj[s][j] > K) { ok = false; break; }
        }

        if (ok) {
            ans = q;
        }
    }

    VVI res;
    rep(i, xn) {
        if (ans >> i & 1) {
            VI &x = xs[i];
            res.PB({x[0] + 1, x[1] + 1, x[2] + 1});
        }
    }


    return res;
}

int main(void) {
    int T;
    cin >> T;
    rep(t, T) {
        cout << "Case #" << (t + 1) << ": ";

        VVI res = solve();
        cout << res.size() << endl;
        dump(res);
    }

    return 0;
}

