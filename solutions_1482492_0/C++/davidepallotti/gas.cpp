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

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define writeln(x) cout << x << "\n"
inline string readln() { string _s; getline(cin,_s); return _s; }
inline int nextInt() {
    #ifdef linux
        int _i = 0;
        char _c;
        while (!isdigit(_c = getchar_unlocked()));
        do {
            _i = 10*_i + (_c-'0');
        } while (isdigit(_c = getchar_unlocked()));
        return _i;
    #else
        int _i;
        cin >> _i;
        return _i;
    #endif
}

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

pair<double,double> tx[2];
#define time first
#define pos second

int main() {
    freopen("gass.in", "r", stdin);
    freopen("gas.out", "w", stdout);
    int t; cin >> t;
    for (int test = 1; test <= t; test++) {
        cout << "Case #" << test << ":\n";
        double d; int n, a;
        cin >> d >> n >> a;
        assert(n <= 2);
        pair<double,double> tx0, tx1;
        if (n == 2) cin >> tx0.time >> tx0.pos >> tx1.time >> tx1.pos;
        else cin >> tx0.time >> tx0.pos;
        rep(i,a) {
            double risp;double acc; cin >> acc;

            if (n == 2) {
                double valtro = (tx1.pos - tx0.pos) / tx1.time;
                //se x0 oltre? tdaltro negativo
                double tdaltro = (d - tx0.pos) / valtro;
                double tdmio = sqrt(d*2/acc);
                risp = max(tdmio, tdaltro);
            } else {
                double tdmio = sqrt(d*2/acc);
                risp = tdmio;
            }


            cout << setprecision(7) << fixed << risp << "\n";
        }
    }



    return 0;
}




