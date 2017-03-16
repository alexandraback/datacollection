
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
ostream& operator<< (ostream &rout, pair<T1, T2> pair) { return rout << "(" << pair.X << ", " << pair.Y << ")";}
const int ALPH =26;

const int P = 1e9+7;

void solve(int tc) {
    int forb[ALPH];
    int cnt[ALPH][ALPH];
    int me[ALPH];
    int in[ALPH], out[ALPH];
    int vis[ALPH];
    cout << "Case #" << tc << ": ";
    int n;
    cin >> n;
    REP(i, ALPH) {
        forb[i] = 0;
        me[i] = 0;
        in[i] = out[i] = 0;
        vis[i] = 0;
        REP(j, ALPH) cnt[i][j] = 0;
    }
    bool ok = true;
    REP(_, n) {
        string s;
        cin >> s;
        char b = s[0], e = s[SZ(s)-1];
        if (b == e) {
            if (s != string(SZ(s), b)) ok = false;
            me[b-'a']++;
        } else {
            int i = 0; while(s[i] == b) ++i;
            int j = SZ(s)-1; while(s[j] == e) --j;
            for (; i <= j; ++i) if (s[i] != s[i-1]) {
                forb[s[i]-'a']++;
            }
            cnt[b-'a'][e-'a']++;
            in[e-'a']++;
            out[b-'a']++;
        }
    }
    REP(i, ALPH) {
        REP(j, ALPH) {
            if ((forb[i] || forb[j]) && cnt[i][j] > 0) ok = false;
        }
        if (forb[i] > 1) ok = false;
        if (forb[i] && me[i] > 0) ok = false;
        if (in[i] > 1 || out[i] > 1) ok = false;
    }
    // cykle
    int cc = 0;
    REP(i,ALPH) {
        if (in[i] == 0 && out[i] == 1) {
            ++cc;
            int p = i;
            while(out[p] == 1) {
                vis[p] = 1;
                REP(j,ALPH) if (cnt[p][j] == 1) {
                    p = j;
                    break;
                }
            }
            vis[p] = 1;
        }
    }
    REP(i,ALPH) {
        if (in[i] + out[i] > 0 && vis[i] == 0) ok = false;
        if (me[i] > 0 && vis[i] == 0) ++cc;
    }
    if (!ok) {
        cout << 0 << endl;
        return;
    }
    LL res = 1;
    while (cc > 0) {
        res = (res * cc) % P;
        cc--;
    }
    REP(i, ALPH) {
        while(me[i] > 0) {
            res = (me[i]*res) % P;
            --me[i];
        }
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

