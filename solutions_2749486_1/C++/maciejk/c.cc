
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
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<typename T1, typename T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { out << "(" << pair.FI << ", " << pair.SE << ")"; return out; }

bool moge(LL x, LL y, LL k) {
   LL u = (abs(x) + abs(y));
   LL z = (k * (k + 1)) / 2;
   if (u <= z && u % 2 == z % 2) return 1;
   else return 0;
}
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
string dir = "WENS";

void go(LL x, LL y, LL k) {
    if (k == 0) return;

    fup(u, 0, 3) {
        LL xx, yy;
        xx = x - dx[u] * k;
        yy = y - dy[u] * k;
        //cout << xx << " " << yy << " " << k - 1 << endl;
        if (moge(xx, yy, k - 1)) {
            go(xx, yy, k - 1);
            cout << dir[u];
            return ;
        }
    }    
    assert(false);
}

int main(){
	ios_base::sync_with_stdio(false);
    int cas;
    cin >> cas;
    fup(c, 1, cas) {
        cout << "Case #" << c << ": ";
        LL x, y;
        cin >> x >> y;
        LL move = 0;
        fup(k, 1, 10000) {
            if (moge(x, y, k)) { move = k; break; }
        }
        //debug(move);

        go(x, y, move);
        cout << endl;


    }

	return 0;
}

