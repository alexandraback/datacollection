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

typedef long double flt;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const flt eps = 1e-10;
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

double solveSlow() {
    maxval = 0;
    int64 have = go(0);
    int64 all = fpow(k, s);
    return double(all * maxval - have) / all;
}

const int maxn = 105;
pii nextState[maxn][260];
flt dp[maxn][maxn][maxn];
double solveFast() {
    for (int i = 0; i < l; ++i) for (char cc : kbd) {
        int c = int(cc);
        string have = req.substr(0, i) + string(1, cc);
        int startj = 0;
        if (have == req) {
            nextState[i][c].first = 1;
            startj = 1;
        } else {
            nextState[i][c].first = 0;
        }
        nextState[i][c].second = 0;
        for (int j = startj; j < Sz(have); ++j) {
            string s = have.substr(j);
            string os = req.substr(0, Sz(s));
            //E(j); E(s); Eo(os);
            if (s == os) {
                nextState[i][c].second = Sz(s);
                break;
            }
        }
        //E(i); E(cc); E(have); Eo(req); Eo(nextState[i][c]);
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1.0;
    for (int typed = 0; typed < s; ++typed) {
        flt sum = 0;
        for (int words = 0; words < maxn ; ++words)
            for (int pos = 0; pos < maxn; ++pos)
                sum += dp[typed][words][pos];
        Eo(sum);
#if 1
        for (int words = 0; words < maxn ; ++words)
            for (int pos = 0; pos < maxn; ++pos)
                dp[typed][words][pos] /= sum;
#endif

        for (int words = 0; words < maxn ; ++words) {
            for (int pos = 0; pos < maxn; ++pos) {
                const flt cur = dp[typed][words][pos];
                if (cur < eps) continue;
                const flt next = cur / Sz(kbd);
                for (char c : kbd) {
                    const int nwords = words + nextState[pos][int(c)].first;
                    const int npos = nextState[pos][int(c)].second;
                    dp[typed + 1][nwords][npos] += next;
                }
            }
        }
    }
    flt res = 0;
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) {
        res += dp[s][i][j] * i;
    }
    //Eo(res);

    bool isRealAtLeastOne = true;
    for (char c : req) {
        bool ok = false;
        for (char w : kbd) {
            if (c == w) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            isRealAtLeastOne = false;
            break;
        }
    }
    if (!isRealAtLeastOne) return 0.0;
    int wordLen = l;
    int wordStep = l - nextState[l - 1][int(req[l - 1])].second;
    int maxcnt = (s - wordLen) / wordStep + 1;
    //E(wordLen); E(wordStep); Eo(maxcnt);

    return flt(maxcnt) - res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int at; cin >> at;
    for (int test = 1; test <= at; ++test) {
        cin >> k >> l >> s;
        cin >> kbd >> req;
        //double res0 = solveSlow();
        double res1 = solveFast();
        //assert(abs(res0 - res1) < eps);
        if (res1 < 0) res1 = 0;
        printf("Case #%d: %.10lf\n", test, res1);
    }

    return 0;
}
