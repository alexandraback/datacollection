//: Piotr Skotnicki
// Google Code Jam 2012
// Round 1C
// A
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <iterator>
#include <bitset>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>

using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back

#define VAR(a,b) __typeof(b) a=(b)
#define ITER(it,a) __typeof((a).begin()) it=(a).begin(),it##_end=(a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,a) for(ITER(it,a);it!=it##_end;++it)
#define SIZE(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define LEN(a) (sizeof(a)/sizeof(*(a)))
#define TAB(a) (a),(a)+LEN(a)
#define CLR(a,v) memset((a),(v),sizeof(a))
#define CPY(a,b) memcpy((b),(a),sizeof(a))
#define ABS(a) ((a)<0?-(a):(a))
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX(a,b) ((a)>=(b)?(a):(b))
#define LOG(a) (log(a)/log(2.0))
#define QSORT(a) random_shuffle(a);sort(a)
#define REVERSE(v) reverse(ALL(v))
#define UNIQUE(v) QSORT(ALL(v)),(v).resize(unique(ALL(v))-(v).begin())
#define ERASE(a,v) (a).erase(remove(ALL(a),v),(a).end())
#define TWO(x) (1<<(x))

#define DEBUG 1
#define DB(a) if(DEBUG){cerr << __LINE__ << ": " << #a << " = " << a << endl;}
#define DBV(a) if(DEBUG){cerr << __LINE__ << ": " << #a << " = "; FOREACH(__i,a) cerr << *__i << " "; cerr << endl;}

template<class T> inline string str(const T& a) {ostringstream os("");os<<a;return os.str();}
int toInt(const string& s){int r;istringstream in(s);in>>r;return r;}

typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef long long LL;
typedef unsigned long long ULL;
typedef istringstream ISS;

const int INF = 1000000000;
const LL INFLL = LL(INF) * LL(INF);
const double EPS = 1e-9;
inline bool is_zero(double v) { return (v > -EPS && v < EPS); }

bool BFS(const VVI& graf, int start) {
    const int N = graf.size();
    VB vis(N);
    VI parent(N, -1);
    queue<int> Q;
    Q.push(start);
    vis[start] = true;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        VI::const_iterator it = graf[u].begin(), end = graf[u].end();
        for(; it != end; ++it) {
            int v = *it;
            if(!vis[v]) {
                vis[v] = true;
                parent[v] = u;
                Q.push(v);
            } else {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int N, a, v;
    cin >> N;
    VVI graf(N);
    REP(i,N) {
        cin >> a;
        graf[i].reserve(a);
        REP(j,a) {
            cin >> v;
            --v;
            graf[i].PB(v);
        }
    }
    REP(i,N) {
        if(BFS(graf, i)) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);

#define TASK "A"

#define LARGE 1
#define SMALL 1
#define TEST 1

#if LARGE
    freopen(TASK"-large.in", "r", stdin);
    freopen(TASK"-large.out", "w", stdout);
#elif SMALL
    freopen(TASK"-small-attempt2.in", "r", stdin);
    freopen(TASK"-small-attempt2.out", "w", stdout);
#elif TEST
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    FOR(i, 1, T) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    
    fflush(stdout);
    return 0;
}
