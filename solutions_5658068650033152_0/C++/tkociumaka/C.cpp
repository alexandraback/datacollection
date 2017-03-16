
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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n,m,k;
    cin >> n >> m >> k;
    int N = 1<<(n*m);
    int res = k;
    REP(msk, N) {
        vector<VI> M(n,VI(m,0));
        int kk = 0;
        REP(i, n) REP(j,m) if (msk & (1<<(i*m+j))) {
            M[i][j] = 1;
            ++kk;
        }
        if (kk < k) continue;
        int r = 0;
        REP(i, n) REP(j,m) {
            if (M[i][j] == 0) continue;
            bool need = false;
            REP(t, 4) {
                int ii = i+dx[t], jj = j+dy[t];
                if (ii < 0 || jj < 0 || ii>=n || jj >= m || M[ii][jj] == 0) need = true;
            }
            if (need) ++r;
        }
        mini(res, r);
    }
    cout << res << endl;



}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}

