#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),__tzg_##i=(b);i<__tzg_##i;++i)
#define urp(i,a,b) for(int i=(a),__tzg_##i=(b);i>=__tzg_##i;--i)
#define rp(i,b) rep(i,0,b)
#define repd(i,a,b) rep(i,a,(b)+1)
#define mst(a,b) memset(a,b,sizeof(a))
#define vrp(it,v) for(auto it(v.begin());(it)!=(v.end());++it)
#define vtr(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define pb(a) push_back(a)
#define _0(x) (!(x))
#define _1(x) (x)
#define bit(x,y) (((x)>>(y))&1)
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;

const int N = 550;


int n;
int da[N*2][N];
int cal(int x) {
    int c = 0;
    while (x) {
        c++;
        x &= x-1;
    }
    return c;
}
int mmp[2550];
void solve() {
    cin>>n;
    int m = 2*n-1;
    mst(mmp, 0);
    rp(i, m) {
        rp(j, n) cin>>da[i][j], ++mmp[ da[i][j] ];
    }
    VI s;
    rp(i, 2550) if (mmp[i] & 1) {
        s.pb(i);
    }
    sort(vtr(s));
    rp(i, s.size()) {
        if (i) printf(" ");
        printf("%d", s[i]);
    }
    puts("");
}

int main() {
#ifdef _TZG_DEBUG_
    freopen("in.txt", "r", stdin);
#else
    freopen("B-large.in", "r", stdin);
    freopen("out_b.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    repd(_, 1 , t) {
        printf("Case #%d: ", _);
        solve();
    }
    return 0;
}

