
#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}


const int INF = 1e9;

int monot(int h, int w, int budget) {
    if (budget < w) return -INF;
    if (w == 1) return min(h, budget);
    if (h == 1) return min(w, budget);
    if (budget == w) return monot(h-1, w-2, budget-2);
    if (budget == w+1) return monot(h-1, w-1, budget-2);
    return monot(h-1, w, budget-2);
}

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n,m,k;
    cin >> n >> m >> k;
    if (n <= 2 || m <= 2 || k <= 4) {
        cout << k << endl;
        return;
    }
    int perp = 2*(n+m);
    vector<vector<VI>> mon(m+1, vector<VI>(n+1, VI(1+perp, 0)));
    FOR(h,1,m) FOR(w,1, n) FOR(b,0, perp) {
        if (b < w) mon[h][w][b] = -INF;
        else if (w == 1) mon[h][w][b] = min(h,b);
        else if (h == 1) mon[h][w][b] = min(w,b);
        else if (b == w) mon[h][w][b] = w+mon[h-1][w-2][b-2];
        else if (b == w+1) mon[h][w][b] = w+mon[h-1][w-1][b-2];
        else mon[h][w][b] = w+mon[h-1][w][b-2];
        if (b >= w) maxi(mon[h][w][b], mon[h][w][b-1]);
    }
    int bg = 0, nd = perp;
    while(nd > bg) {
        int b = (bg+nd)/2;
        /// test
        bool ok = false;
        FOR(w, 3, n) {
            if (b < 2*w-2) break;
            FORD(ww, w, 1) if (w+mon[m-1][ww][b-w] >= k) ok = true;
            // any
            FOR(h, 1, m-2) {
                int hh = m-1-h;
                REP(dx, 3) REP(dy,3) {
                    REP(bb, b-2) {
                       // if (b == 5 && w == 3 && h == 1 && dx == 2 && dy == 2 && bb == 2) debug(w+mon[h][w-dy][bb]+mon[hh][w-dx][b-bb-2]);
                        if (w+mon[h][w-dy][bb] + mon[hh][w-dx][b-bb-2] >= k) {
                            ok = true;
                        }
                    }
                }
            }
        }
        if (ok) nd = b;
        else bg = b+1;
    }
    cout << bg << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}

