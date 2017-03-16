
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

const int SIZE = (1 << 21);
#define TYP int

struct D{
    TYP tab[2*SIZE+7],caly[2*SIZE+7];
    D(){for(int i=0;i<=2*SIZE;i++) {tab[i]=0; caly[i]=0;}}
    void clear() { 
        for(int i=0;i<=2*SIZE;i++) {tab[i]=0; caly[i]=0;}
    }

    void set(int pp,int kk,TYP w,int x=1,int p=0,int k=SIZE - 1){
        if(p>=pp && k<=kk){caly[x]= max(caly[x],w); tab[x]=max(caly[x],tab[x]); return;}
        if(p>kk || k<pp) return;
        set(pp,kk,w,2*x,p,(p+k)/2);
        set(pp,kk,w,2*x+1,(p+k+1)/2,k);
        tab[x]=max(caly[x], min(tab[2*x],tab[2*x+1]));
    }

    TYP get(int pp,int kk,int x=1,int p=0,int k=SIZE - 1){
        if(p>=pp && k<=kk) return tab[x]; 
        if(p>kk || k<pp) {
            return INF;
        }
        int z = max(caly[x], min(get(pp,kk,2*x,p,(p+k)/2),get(pp,kk,2*x+1,(p+k+1)/2,k)));
        return z;
    }
};

D tree;

#define mdays 700006
vector<pair<P, int> > attacks[mdays];

VI xx;
int params[1005][10];
map<int, int> mapx;

void normalize() {
    sort(ALL(xx));
    int idx = 0;
    fup(i, 0, siz(xx) - 1) {
        if (i == 0 || xx[i] != xx[i - 1]) { ++idx; mapx[xx[i]] = idx; }
    }
}


void solve() {
    int n;
    cin >> n;
    mapx.clear();
    fup(i, 1, n) {
        int d, at, w, e, s, dd, dp, ds;
        fup(j, 1, 8) cin >> params[i][j];
        at = params[i][2];
        w = params[i][3];
        e = params[i][4];
        dp = params[i][7];

        fup(a, 0, at - 1) {
            int ww, ee;
            ww = w + a * dp;
            ee = e + a * dp;
            ee--;
            xx.PB(ww);
            xx.PB(ee);
        }
    }
    normalize();
    tree.clear();

    fup(i, 1, n) {
        int d, at, w, e, s, dd, dp, ds;
        d = params[i][1];
        at = params[i][2];
        w = params[i][3];
        e = params[i][4];
        s = params[i][5];
        dd = params[i][6];
        dp = params[i][7];
        ds = params[i][8];
        fup(a, 0, at - 1) {
            int ww, ee;
            ww = w + a * dp;
            ee = e + a * dp;
            ee--;
            ww = mapx[ww];
            ee = mapx[ee];

            int ss = s + a * ds;
            int day = d + a * dd;
        //    cout << "ATTACK " << day << " " << ww << " " << ee << " "<< ss << endl;
            attacks[day].PB(MP(MP(ww, ee), ss));
        }
    }
    int sum = 0;
    fup(day, 0, mdays - 1) {
        FORE(it, attacks[day]) {
            int l, r;
            l = it -> FI.FI;
            r = it -> FI.SE;
            int z = tree.get(l, r);

          //  cout << "GET " << day << " " << l << " " << r << " " << z << " " << it -> SE << endl;
            if (z < it -> SE) {
                ++sum;
            }
        }

        FORE(it, attacks[day]) {
            int l, r;
            l = it -> FI.FI;
            r = it -> FI.SE;
         //   cout << "SET " << l << " " << r << " " << it -> SE << endl;
            tree.set(l, r, it -> SE);
        }
        attacks[day].clear();
    }
    cout << sum;
}

int main(){
	ios_base::sync_with_stdio(false);
    int cas;
  
    cin >> cas;
    fup(c, 1, cas) {
        cout << "Case #" << c << ": ";
        solve();
        cout << endl;
    }

	return 0;
}

