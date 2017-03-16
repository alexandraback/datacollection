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

int len;
string C, J;
string rc, rj;
int nc, nj;
int diff;
void dfs(int idx) {
    if (idx == len) {
        int tc = 0;
        rp(i, len) {
            tc = tc * 10 + rc[i]-'0';
        }
        int tj = 0;
        rp(i, len) {
            tj = tj * 10 + rj[i]-'0';
        }
        int d = abs(tc-tj);
        if (diff > d) {
            diff = d;
            nc = tc;
            nj = tj;
        } else if (diff == d) {
            if (nc > tc) {
                nc = tc;
                nj = tj;
            } else if (nc == tc) {
                if (nj > tj) {
                    nj = tj;
                }
            }
        }
        return ;
    }
    rp(i, 10) if ( (C[idx] != '?' && C[idx]-'0'==i) || (C[idx] == '?') ) {
        rp(j, 10) if ( (J[idx] != '?' && J[idx]-'0'==j) || (J[idx] == '?') ){
            rc[idx] = '0'+i;
            rj[idx] = '0'+j;
            dfs(idx+1);
        }
    }
}

void solve() {
    cin>>C>>J;
    len = C.size();
    rc = string(len, ' ');
    rj = rc;
    diff = 1e9;
    dfs(0);
    VI oc(len, 0);
    VI oj(len, 0);
    {
        int x = nc;
        int p = len-1;
        while (x) {
            oc[p] = x % 10;
            --p;
            x /= 10;
        }
    }
    {
        int x = nj;
        int p = len-1;
        while (x) {
            oj[p] = x % 10;
            --p;
            x /= 10;
        }
    }
    rp(i, len) cout<<oc[i];
    printf(" ");
    rp(i, len) cout<<oj[i];
    cout<<endl;
}

int main() {
#ifdef _TZG_DEBUG
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out_b.txt", "w", stdout);
#endif // __TZG_DEBUG
    int t;
    cin>>t;
    repd(_, 1, t) {
        printf("Case #%d: ", _);
        solve();
    }
    return 0;
}
