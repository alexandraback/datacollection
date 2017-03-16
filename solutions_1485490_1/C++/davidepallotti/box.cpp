using namespace std;

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits>
#include <utility>
#include <time.h>
#include <assert.h>

#include <tr1/unordered_set>
#include <tr1/unordered_map>
using namespace std::tr1;

#define abs(x) ((x)>=0?(x):(-(x)))
#define sqr(a) ((a)*(a))
const int inf = numeric_limits<int>::max();
const double eps = 1.0e-12;
const double pi = 3.141592653589793238462643383279;

typedef int LL;
typedef unsigned int ULL;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define writeln(x) cout << x << "\n"
inline string readln() { string _s; getline(cin,_s); return _s; }


#define rep(i,n) for (int i=0; i<n; i++)
#define repr(i,b,e) for (int i=b; i<=e; i++)
#define iter(it,ct) for (typeof(ct.begin()) it=ct.begin(); it!=ct.end(); it++)
#define riter(rit,ct) for (typeof(ct.rbegin()) rit=ct.rbegin(); rit!=ct.rend(); rit++)
#define unless(cond) if(!(cond))
#define until(cond) while(!(cond))

template <class T> class reverse_compare {
    public: inline bool operator() (const T& a, const T& b) const { return b < a; }
};

#define DEBUG
#ifdef DEBUG
    #define dbg(var) cerr << "-> " << #var << " = " << (var) << "\n";
    #define dbgarr(arr,n) \
        { \
            cerr << "-> " << #arr << " = "; \
            rep(_i,n) cerr << arr[_i] << " "; \
            cerr << "\n"; \
        }
    #define dbgmat(mat,m,n) \
        { \
            cerr << "-> " << #mat << " =" << "\n"; \
            rep(_i,m) { \
                cerr << "-> "; \
                rep(_j,n) cerr << mat[_i][_j] << " "; \
                cerr << "\n"; \
            } \
        }
    #define dbgv(v) \
        { \
            cerr << "-> " << #v << " = "; \
            iter(_it,v) cerr << *_it << " "; \
            cerr << "\n"; \
        }
#else
    #define dbg(var)
    #define dbgarr(arr,n)
    #define dbgmat(mat,m,n)
    #define dbgv(v)
#endif

/*---------------------------------------------------------------------------*/

pair<long long,int> boxes[101], toys[101];
#define num first
#define tipo second

struct Stato {
    int d1; long long q1; int d2; long long q2;
    Stato(int d1, long long q1, int d2, long long q2) : d1(d1), q1(q1), d2(d2), q2(q2) {}
    bool operator < (Stato s) const {
        if (d1 == s.d1) {
            if (q1 == s.q1) {
                if (d2 == s.d2) {
                    return q2 < s.q2;
                }
                return d2 < s.d2;
            }
            return q1 < s.q1;
        }
        return d1 < s.d1;
    }
};

map<Stato, long long> dp;
int n, m;

long long f(int d1, long long q1, int d2, long long q2) {
    //cout << d1 << " " << q1 << " " << d2 << " " << q2 << "\n";
    if (d1 >= n || d2 >= m) return 0;
    assert(q1 > 0 && q2 > 0);
    Stato s = Stato(d1, q1, d2, q2);
    if (dp.count(s)) return dp[s];
    int t1 = boxes[d1].tipo;
    int t2 = toys[d2].tipo;
    long long r = 0;
    if (t1 != t2) {
        r = max(f(d1+1, boxes[d1+1].num, d2, q2), f(d1, q1, d2+1, toys[d2+1].num));
    } else {
        if (q1 > q2) {
            r = q2 + f(d1, q1-q2, d2+1, toys[d2+1].num);
        } else if (q1 == q2) {
            r = q1 + f(d1+1, boxes[d1+1].num, d2+1, toys[d2+1].num);
        } else { //q1 < q2
            r = q1 + f(d1+1, boxes[d1+1].num, d2, q2-q1);
        }
    }
    /*
    r = max(f(d1+1, boxes[d1+1].num, d2, q2), f(d1, q1, d2+1, boxes[d2+1].num));
    if (t1 == t2) {
        if (q1 > q2) {
            r = max(r, q2 + f(d1, q1-q2, d2+1, boxes[d2+1].num));
        } else if (q1 == q2) {
            r = max(r, q1 + f(d1+1, boxes[d1+1].num, d2+1, boxes[d2+1].num));
        } else { //q1 < q2
            r = max(r, q1 + f(d1+1, boxes[d1+1].num, d2, q2-q1));
        }
    }
    */
    dp[s] = r;
    return r;
}

int main() {
    freopen("boxl.in", "r", stdin);
    freopen("box.out", "w", stdout);

    int t; cin >> t;
    for (int test = 1; test <= t; test++) {
        dp.clear();
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> boxes[i].num >> boxes[i].tipo;
        }

        for (int i = 0; i < m; i++) {
            cin >> toys[i].num >> toys[i].tipo;
        }

        long long risp = f(0, boxes[0].num, 0, toys[0].num);

        cout << "Case #" << test << ": " << risp << "\n";
    }

    return 0;
}
