
#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
#include<cstdio>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define maxn 105
int t[maxn][maxn];
int h, w;

int s[maxn][2];
bool check(int wys) {
    CLR(s);
    fup(i, 1, h) fup(j, 1, w) {
        if (t[i][j] <= wys) s[i][0]++, s[j][1]++;
    }
    fup(i, 1, h) fup(j, 1, w) if (t[i][j] == wys) {
        if (s[i][0] == w || s[j][1] == h); else return 0;
    }
    return 1;
}

void solve(int cas) {
    cin >> h >> w; 
    fup(i, 1, h) {
        fup(j, 1, w) cin >> t[i][j];
    }
    printf("Case #%d: ", cas);
    fup(i, 1, 100) if(!check(i)) { cout << "NO" << endl; return; }
    cout << "YES" << endl;
}

int main(){
    int cas;
    cin >> cas;
    fup(c, 1, cas) {
        solve(c);
    }

	return 0;
}

