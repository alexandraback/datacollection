

#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<cstdio>
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
#define MAXN 1000007

struct chest {
    chest(int o, VI i): open(o), done(false), in(i) {}
    int open;
    bool done;
    VI in;
};
vector<VI>  Cin;
vector<chest> C;
    multiset<int>  K;
bool test(int c) {
    if (C[c].done) return false;
    multiset<int> kk(K);
    
    VAR(kt, kk.find(C[c].open));
    if (kt == kk.end()) return false;
    kk.erase(kt);
    vector<bool> V(201, false);
    queue<int> Q;
    FORE(it, kk) {
        if (!V[*it]){
            V[*it] = true;
            Q.push(*it);
        }
    }
    C[c].done=true;
    FORE(it, C[c].in) {
        if (!V[*it]){
            V[*it] = true;
            Q.push(*it);
        }
    }

    while(!Q.empty()) {
        int f = Q.front();
     //   cerr << f << endl;
        Q.pop();
        FORE(it, Cin[f]) {
            chest & d = C[*it];
            if (d.done) continue;
            FORE(jt, d.in) {
                if (!V[*jt]) {
                    V[*jt] = true;
                    Q.push(*jt);
                }
            }
        }
    }
    FORE(it, C) {
        if (!it->done && !V[it->open]) {
            C[c].done = false;
            return false;
        }
    }
    K.erase(K.find(C[c].open));
    FORE(it, C[c].in) {
        K.insert(*it);
    }
    return true;
} 

int solve() {
    int k, n;
    cin >> k >> n;
    K.clear();
    C.clear();
    Cin.clear();
    Cin = vector<VI > (201, VI());
    VI ile(201, 0);
    REP(i, k) {
        int x;
        cin >> x;
        K.insert(x);
        ile[x]++;
    }
    REP(i, n) {
        int o;
        cin >> o;
        int d;
        VI in;
        cin >> d;
        ile[o]--;
        REP(j, d) {
            int x;
            cin >> x;
            ile[x]++;
            in.PB(x);
        }
        C.PB(chest(o, in));
        Cin[o].PB(i);
    }
    REP(i, 200) {
        if (ile[i] < 0) {
            cout << " IMPOSSIBLE" << endl;
            return 0;
        }
        while(ile[i] > 0) {
            Cin[i].PB(SZ(C));
            C.PB(chest(i, VI()));
            --ile[i];
        }
    }
    VI res;
    REP(i, n) {
        bool ok = false;
        REP(j, n) {
        //    cerr << i << " " << j << endl;
            if (test(j)) {
                res.PB(j);
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << " IMPOSSIBLE" << endl;
            return 0;
        }
    }
    FORE(it, res)
        cout<< " " << *it+1;
    cout << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(i,t) {
        cout << "Case #" << (i+1) << ":";
        solve();
    }
    return 0;
}

