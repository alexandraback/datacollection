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

const int N = 55;
ll num[N];
VI cal(ll x) {
    VI res;
    rp(i, 63) {
        ll tp = 1ll<<i;
        if (tp & x) {
            res.pb(i);
        }
    }
    return res;
}
int mmp[55][55];
int n;
int solve() {
    ll m;
    cin>>n>>m;
    num[0] = 1;
    num[1] = 1;
    repd(i, 2, n-1) {
        num[i] = num[i-1]<<1;
    }
    if (num[n-1] < m) {
        puts("IMPOSSIBLE");
        return 0;
    }
    puts("POSSIBLE");
    mst(mmp, 0);
    int t;
    rep(i, 1, n) {
        if (num[i] <= m) {
            t = i;
        } else break;
    }
    repd(i, 1, t) {
        rp(j, i) mmp[j][i] = 1;
    }
    if (n-1 == t) return 1;
    VI v = cal(m);
    rp(i, v.size()) {
        int o = v[i];
        int t = o+1;
        mmp[t][n-1] = 1;
    }
    return 1;
}

int main() {
#ifdef _TZG_DEBUG
    freopen("B-large.in", "r", stdin);
    freopen("out_b.txt", "w", stdout);
#endif // _TZG_DEBUG
    int t;
    cin>>t;
    repd(_, 1, t) {
        printf("Case #%d: ", _);
        if (solve()) {
            rp(i, n) {
                rp(j, n)
                    cout<<mmp[i][j];
                cout<<endl;
            }
        }
    }
    return 0;
}
