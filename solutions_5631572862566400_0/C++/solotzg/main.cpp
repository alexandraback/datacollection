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

const int N = 15;
int bf[N];
int cal(int x) {
    int c = 0;
    while (x) {
        c++;
        x &= x-1;
    }
    return c;
}
int mmp[N][N];
int p[N], n;
void solve() {
    cin>>n;
    repd(i, 1, n) cin>>bf[i];
    repd(i, 1, n) bf[i-1] = bf[i]-1;
    int res = 1;
    rp(mask, 1<<n) {
        int m = cal(mask);
        if (m <= res) continue;
        mst(mmp, 0);
        rp(i, n) {
            int u = i, v = bf[i];
            if (bit(mask, u) && bit(mask, v) ) {
                mmp[u][v] = 1;
            }
        }
        int o = 0;
        rp(i, n) {
            if (bit(mask, i) ) p[o++] = i;
        }
        do{
            int f = 1;
            rp(i, o) {
                int ii = (i+1)%o;
                int jj = (i+o-1)%o;
                if ( (!mmp[ p[i] ][ p[ii] ]) && (!mmp[ p[i] ][ p[jj] ]) ) {
                    f = 0;
                    break;
                }
            }
            if (f == 1) {
                res = max(res, m);
                break;
            }
        }while (next_permutation(p, p+o));
    }
    cout<<res<<endl;
}

int main() {
#ifdef _TZG_DEBUG_
    freopen("in.txt", "r", stdin);
#else
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("out_c.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    repd(_, 1 , t) {
        printf("Case #%d: ", _);
        solve();
    }
    return 0;
}

