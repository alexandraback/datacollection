#include <bits/stdc++.h>
using namespace std;

#ifdef ILIKEGENTOO
#   define Eo(x) { cerr << #x << " = " << (x) << endl; }
#   define E(x) { cerr << #x << " = " << (x) << "   "; }
#   define FREOPEN(x)
#else
#   define Eo(x) {}
#   define E(x) {}
#   define FREOPEN(x) (void)freopen(x ".in", "r", stdin);(void)freopen(x ".out", "w", stdout);
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<class A, class B> ostream &operator<<(ostream &os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

template<class C> void operator<<(vector<C> &v, const C &x){v.push_back(x);}
template<class D> void operator>>(vector<D> &v, D &x){assert(!v.empty()); x=v.back(); v.pop_back();}
template<class E> void operator<<(set<E> &v, const E &x){v.insert(x);}

typedef double flt;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const flt eps = 1e-8;
const flt pi = acos(-1.0);
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

random_device rdev; mt19937 rmt(rdev()); uniform_int_distribution<> rnd(0, 0x7fffffff);
inline int mrand(int mod = 0x7fffffff) { return rnd(rmt) % mod; }

struct Hiker {
    int64 d, m;
} hs[3];
int hcnt;

int solve() {
    if (hcnt < 2) return 0;
    assert(hcnt == 2);
    if (hs[0].m < hs[1].m) swap(hs[0], hs[1]);

    if (hs[0].m * (360 - hs[0].d) < hs[1].m * (720 - hs[1].d))
        return 0;
    else
        return 1;
    //return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        hcnt = 0;
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            int d, h, m; cin >> d >> h >> m;
            for (int j = 0; j < h; ++j) {
                hs[hcnt++] = Hiker{d, m + j};
            }
        }
        cout << "Case #" << test << ": " << solve() << endl;
    }

    return 0;
}
