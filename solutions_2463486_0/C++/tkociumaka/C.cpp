

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

bool test(vector<int> const &in, vector<int> &out) {
    int n = SZ(in);
    out = VI(2*n-1, 0);
    REP(d, 2*n-1) {
        int v = 0;
        REP(i, d+1) {
            if (i < n && d-i < n) v += in[i]*in[d-i];
        
        }
        out[d] = v;
        if (v >= 10) return false;
    }
    return true;
}

set<string> S;
vector<string> V;
void generate(int n) {
    REP(x, (n+3)/2) REP(y, (n+3)/2) REP(z, (n+3)/2) REP(t, (n+3)/2) {
        vector<int> a(n,0);
        a[0]++;
        a[x]++;
        a[y]++;
        a[z]++;
        a[t]++;
        REP(i, n) a[n-1-i] = a[i];
        vector<int> b;
        bool ok = test(a, b);
        
        if (ok) {
            string s(101, '0');
            REP(i, 2*n-1) s[100-i] = b[i]+'0';
            S.insert(s);
        }

    }
}
string read() {
    string a, A(101, '0');
    cin >> a;
    int n = a.length();
    REP(i, n) A[100-i] = a[n-i-1];
    return A;
}
int solve() {
    string a = read(),b=read();
    int n1 = lower_bound(ALL(V), a)-V.begin();
    int n2 = upper_bound(ALL(V), b)-V.begin();
    cout << n2 - n1 << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    FOR(i, 1, 50) {
        cerr << i << endl;
    generate(i);
    }
    V = vector<string>(ALL(S));
     int t;
       cin >> t;
       REP(i,t) {
       cout << "Case #" << (i+1) << ": ";
       solve();
       }
    return 0;
}

