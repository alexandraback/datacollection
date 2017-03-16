// New Ryan
// Create @ 10:26 04-27 2013
// Comment - 

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define all(x) (x).begin(), (x).end()
#define clz(x) memset (x, 0, sizeof(x))
#define read(x) freopen (x, "r", stdin)
#define wrte(x) freopen (x, "w", stdout)
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<double, double> pdd;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

const int N = 3;
const int M = 5;
const int K = 7;

const int allP = (M - 1) * (M - 1) * (M - 1);

map<multiset<int>, int> allp;
map<multiset<int>, map<int, double> > allc;
map<multiset<int>, double> ans;

void pre(multiset<int> p) {
    cerr << "pre multiset " << endl;
    int a[N], cnt = 0;
    repeach (it, p) {
        a[cnt++] = *it;
    }
    map<int, int> allC;
    rep (k1, 2) rep (k2, 2) rep (k3, 2) {
        int cur = 1;
        if (k1 == 1) cur *= a[0];
        if (k2 == 1) cur *= a[1];
        if (k3 == 1) cur *= a[2];
        allC[cur]++;
    }
    repeach (it, allC) {
        allc[p][it->first] = (double)it->second / 8;
    }
}

void pre() {
    cerr << "Pre " << endl;
    repf (i, 2, M) repf (j, 2, M) repf (k, 2, M) {
        multiset<int> now;
        now.insert(i);
        now.insert(j);
        now.insert(k);
        allp[now]++;
    }
    repeach (it, allp) {
        pre(it->first);
    }
}

void solve() {
    cerr << "solve " << endl;
    ans.clear();
    rep (k, K) {
        int x;
        scanf ("%d", &x);
        repeach (it, allc) {
            ans[it->first] += log((it->second)[x]);
        }
    }
    repeach (it, allp) {
        ans[it->first] += log((double)it->second / allP);
    }
    multiset<int> res;
    double maxp = -1e20;
    repeach (it, ans) {
        if (sgn(it->second - maxp) > 0) {
            maxp = it->second;
            res = it->first;
        }
    }
    repeach (it, res) {
        printf ("%d", *it);
    }
    puts ("");
}

int main() {
    wrte ("C.out");
    pre();
    
    int R;
    scanf ("%*d%d%*d%*d%*d", &R);
    printf ("Case #1:\n");
    rep (i, R) {
        solve();
    }
    return 0;
}

