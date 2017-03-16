#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
typedef long long ll;
#define SZ(v) ((int)(v).size())
const int inf = 0x3f3f3f3f;
#define For(i,n) for(int i=0;i<n;i++)
#define SZ(v) ((int)(v).size())
#define pb push_back
#define ALL(v) (v).begin(), (v).end()
#define Fill(a,b) memset(a,b,sizeof(a))
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
int n, m;
bool dp[55];
        int a[66];
int main()
{
  //  prt(5*30*(1ll<<29)*100);
    int re ,ca=1; cin>>re;
    while (re--) {
        int C, D, V;
        cin>>C>>D>>V;
        vector<int> tmp;
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        for (int i =0;i<D;i++) cin>>a[i], tmp.pb(a[i]);//, dp[a[i]] = 1;;
        int n = D;
        printf("Case #%d: ", ca++ );
        vector<int> b = tmp;
        vector<int > v;

        for (int i=0;i<SZ(b);i++)
            for (int j=V; j>=b[i]; j--)
            dp[j] |= dp[j-b[i]];
        for (int i=1;i<=V;i++) if (!dp[i]) v.push_back(i);
        int m = SZ(v);
        int ans = inf;

        for (int s=0;s<(1<<m);s++) {
            int t = __builtin_popcount(s);
            if (t>=ans) continue;
            b.clear();
            bool f[55];
            for (int i=0;i<=V;i++) f[i] = dp[i];
            for (int i=0;i<m;i++) if(s>>i&1)
                b.pb(v[i]);

            for (int x : b)
            {

                for (int j=V; j>=x; j--)
                    f[j] |= f[j-x];
            }
            bool ok = 1;
            for (int i=1;i<=V;i++) if (!f[i])
            {
                ok = false;
                break;
            }
            if (ok) ans = t;
        }
        cout<<ans<<endl;
    }
}
