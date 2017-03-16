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

vector<int> adj[1000];
bool risp;
bool vis[1000];

void dfs(int v) {
    vis[v] = true;
    iter(it, adj[v]) {
        if (risp) return;
        if (vis[*it]) risp = true;
        else dfs(*it);
    }
}

int main() {
    freopen("diamonds.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {

        rep(i,1000) adj[i].clear();
        risp = false;

        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            for (int j = 0; j < m; j++) {
                int a; cin >> a;
                a--;
                adj[i].pb(a);
            }
        }

        for (int i = 0; i < n && !risp; i++) {
            for (int j = 0; j < n; j++) vis[j] = false;
            dfs(i);
        }
        cout << "Case #" << test << ": ";
        cout << (risp ? "Yes" : "No");
        cout << "\n";
    }

    return 0;
}




