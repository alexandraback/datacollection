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

int64 fpow(int64 a, int64 p) {
    int64 res = 1;
    for (; p; p >>= 1) {
        if (p&1)
            res *= a;
        a *= a;
    }
    return res;
}

int k, l, s;
string kbd;
string req;

int64 maxval;
string word;
int64 go(int pos) {
    if (pos == s) {
        int64 cnt = 0;
        for (int i = 0; i + l <= s; ++i)
            if (word.substr(i, l) == req)
                ++cnt;
        maxval = max(maxval, cnt);
        return cnt;
    }
    int64 res = 0;
    word.push_back('_');
    for (int i = 0; i < k; ++i) {
        word.back() = kbd[i];
        res += go(pos + 1);
    }
    word.pop_back();
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int at; cin >> at;
    for (int test = 1; test <= at; ++test) {
        E("================"); EO(test);
        cin >> k >> l >> s;
        cin >> kbd >> req;
        maxval = 0;
        int64 have = go(0);
        int64 all = fpow(k, s);
        E(maxval); E(have); Eo(all);
        printf("Case #%d: %.10lf\n", test, double(all * maxval - have) / all);
    }

    return 0;
}
