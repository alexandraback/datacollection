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

string s[100][2];
int num[100][2];
int cal(int x) {
    int r = 0;
    while (x) {
        ++r;
        x &= x-1;
    }
    return r;
}
void solve() {
    int n;
    cin>>n;
    rp(i, n) {
        cin>>s[i][0]>>s[i][1];
    }
    unordered_map<string,int> mmp;
    int o = 0;
    rp(i, n) rp(j, 2) {
        string & ps = s[i][j];
        if (mmp.find(ps) == mmp.end()) {
            mmp[ps] = o++;
        }
    }
    rp(i, n) rp(j, 2) {
        string & ps = s[i][j];
        num[i][j] = mmp[ps];
    }
    int res = 0;
    int sn[300];
    rp(mask, 1<<n) {
        int cnt = n-cal(mask);
        if (cnt <= res) continue;
        mst(sn, 0);
        rp(i, n) {
            if (bit(mask, i)) {
                sn[num[i][0]] |= 1;
                sn[num[i][1]] |= 2;
            }
        }
        int ok = 1;
        rp(i, n) {
            if (! bit(mask, i)) {
                if (!(sn[num[i][0]] & 1) || !(sn[num[i][1]] & 2)) {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok) {
            res = max(res, cnt);
        }
    }
    cout<<res<<endl;
}

int main() {
#ifdef _TZG_DEBUG
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("out_c.txt", "w", stdout);
#endif // __TZG_DEBUG
    int t;
    cin>>t;
    repd(_, 1, t) {
        printf("Case #%d: ", _);
        solve();
    }
    return 0;
}
