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

int n;
string ms[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int mmp[300];
int res[100];
void solve() {
    string s;
    string o = "ZWXGTSVIFO";
    int num[] = {0,2,6,8,3,7,5,9,4,1};
    cin>>s;
    mst(mmp, 0);
    rp(i, s.size()) mmp[s[i]]++;
    VI r;
    rp(i, 10) {
        int p = mmp[o[i]];
        if (p == 0) continue;
        string & q = ms[num[i]];
        for (char c : q) {
            mmp[c] -= p;
        }
        rp(j, p) r.pb(num[i]);
    }
    sort(vtr(r));
    rp(i, r.size()) cout<<r[i];
    cout<<endl;
}

int main() {
#ifdef _TZG_DEBUG
    freopen("A-large.in", "r", stdin);
    freopen("out_a.txt", "w", stdout);
#endif // __TZG_DEBUG
    int t;
    cin>>t;
    repd(_, 1, t) {
        printf("Case #%d: ", _);
        solve();
    }
    return 0;
}
