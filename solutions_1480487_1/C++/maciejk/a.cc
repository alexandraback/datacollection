
#include<cassert>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<cstring>
#include<stack>
#include<sstream>
#include<complex>
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define DEBU true
#define debug(x) { if (DEBU) cerr << #x << " = " << x << "\n"; }
#define debugv(x) { if (DEBU) { cerr << #x << " = "; FORE(it,(x)) cerr<< *it <<","; cerr<<"\n"; } }
#define fup(i,a,b) for(int i=(a);i<=(b);i++)
#define fdo(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset((x),0,sizeof (x))
#define abso(a) ((a)<0?(-(a)):(a))
#define maxi(a,b) ((a)>(b)?(a):(b))
#define mini(a,b) ((a)<(b)?(a):(b))
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define siz(a) ((int)a.size())
#define inf 1000000000
#define SQR(a) ((a)*(a))

using namespace std;
typedef long long lli;
typedef double ld;
#define maxn 205
int y[maxn];
int S = 0, n;

bool wystarczy(int idx, ld q) {
    ld score = y[idx] + S * q;
//    debug(score);
    ld su = 0;
    fup(i, 1, n) {
        if (i == idx) continue;
        if (y[i] >= score) continue;
        ld cos = (score - y[i]) / (ld)S;
        su += cos;
    }
    return su > (1.0 - q);
}

int main() {
    int cas;
    cin >> cas;
    fup(c, 1, cas) {
        cin >> n;
        S = 0;
        fup(i, 1, n) { cin >> y[i]; S += y[i]; }
        printf("Case #%d:", c);
        fup(i, 1, n) {
            ld s, e;
            s = 0;
            e = 1;
            ld best = 1;
            fup(j, 1, 200) {
                ld q = (s + e) / 2;
                if (wystarczy(i, q)) {
                    e = q;
                    best = q;
                } else s = q;
            }
            printf(" %.7lf", best * 100);
        }
        cout << endl;
    }
    return 0;
}

