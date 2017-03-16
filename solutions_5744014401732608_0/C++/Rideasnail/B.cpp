#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#ifdef DEBUG
    #define cek(x) cout<<x
#else
    #define cek(x) if(false){}
#endif // DEBUG

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define PI acos(-1.0)
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define sci(x) scanf("%d",&x)
#define scs(x) scanf("%s",&x)

int main(void){
    freopen("D:/Code/B-small-attempt0.in","r",stdin);
    freopen("D:/Code/out.txt","w",stdout);

    int tc;
    sci(tc);

    int ans[60][60];

    FOR(i,tc)
    {
        reset(ans,0);
        int B;
        ll M;

        cin >> B;
        cin >> M;
        //Is it possible?
        ll maxno = 1;
        for(int ii=2;ii<B;ii++) maxno *=2;

        if(maxno >= M)
        {
            //Build Perfect
            FOR(ii,B){
                FOR(iii,B) {
                    if(ii<iii) {
                        ans[ii][iii] = 1;
                    }
                }
            }

            ll diff = maxno - M;
            ll mult = maxno/2;
            for(int ii=B-2;ii>=0;ii--) {

                if(ii==0) mult = 1;

                if(diff>=mult){
                    diff-= mult;
                    ans[ii][B-1] = 0;
                }
                mult/=2;
            }

            cout << "Case #" << i+1 << ": POSSIBLE" << endl;

            FOR(ii,B){
                FOR(iii,B) {
                    cout << ans[ii][iii];
                }
                cout << endl;
            }

        } else {
            cout << "Case #" << i+1 << ": IMPOSSIBLE" << endl;
        }

    }


    return 0;
}
