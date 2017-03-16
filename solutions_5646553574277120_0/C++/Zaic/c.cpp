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

const int maxd = 1000;

int c, d, v;
int ad;
int nom[maxd];
bool used[maxd];

inline uint bit(int t) { return uint(1) << t; }

bool check() {
    uint have = 0;
    for (int i = 0; i < ad; ++i) {
        have = (have | (have << nom[i]));
        have |= bit(nom[i]);
    }
    for (int i = 1; i <= v; ++i) if (!(have & bit(i))) return false;
    return true;
}

bool solve(int pos, int last = 1) {
    if (pos == ad) return check();
    for (; last <= v; ++last) if (!used[last])  {
        nom[pos] = last;
        if (solve(pos + 1, last + 1)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int at; cin >> at;
    for (int t = 1; t <= at; ++t) {
        E("==="); EO(t);
        cin >> c >> d >> v;
        assert(c == 1);
        for (int i = 0; i < d; ++i) cin >> nom[i];
        memset(used, 0, sizeof(used));
        for (int i = 0; i < d; ++i) used[nom[i]] = true;

        for (ad = d; ad <= d + 5; ++ad) {
            if (solve(d)) {
                for (int i = 0; i < ad; ++i) E(nom[i]);
                Eo("_");
                break;
            }
        }
        cout << "Case #" << t << ": " << ad - d << endl;
    }

    return 0;
}
