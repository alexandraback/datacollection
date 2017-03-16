#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstdlib>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)


int mod1 = int(1e9) + 7;

double prob[30];

double dp[110][110];    // len, bananas
double sprob[110];

int main(){
    cout.precision(12);

	int T;
	cin >> T;

    for1(cas,T) {
        cout << "Case #" << cas << ": ";

        int k,tl,s;
        string keyb, targ;
        cin >> k >> tl >> s;
        cin >> keyb >> targ;

        memset(prob, 0, sizeof(prob));

        forn(i,k)
            prob[keyb[i]-'A'] += 1.0 / (double) k;
        vi overl;
        for1(j,tl-1) {
            bool ok = true;
            for(int i=0;i+j<tl;i++) {
                if(targ[i]!=targ[j+i]) {
                    ok = false;
                    break;
                }
            }
            if(ok) overl.pb(j);
        }

        bool cantype = true;
        forn(i,tl) {
            if(prob[targ[i]-'A'] == 0)
                cantype = false;
        }
        if(!cantype) {
            cout << 0.0 << endl;
            continue;
        }

        double maxbanana;
        if(overl.size()>0)
            maxbanana= (s-tl) / overl[0] + 1;
        else
            maxbanana= s/tl;


        sprob[0] = 1.0;
        for1(i,tl)
            sprob[i] = sprob[i-1]*prob[targ[tl-i]-'A'];

        memset(dp, 0, sizeof(dp));
        forn(len,s+1) dp[len][0] = 1.0;
        for1(len,s) for1(minb,maxbanana) {
            //dp[len][minb] = dp[len-1][minb];
            forn(i,overl.size()) {
                int rem = tl-overl[i];
                if(len>=rem){
                    dp[len][minb] += (dp[len-rem][minb-1] - dp[len-rem][minb]) * sprob[rem];
                    dp[len][minb] += dp[len-rem][minb] * (1.0 - sprob[rem]);
                }
//                    dp[len][minb] += sprob[rem] * (1.0-dp[len-rem][minb]);
            }
            if(len>=tl) {
                dp[len][minb] += (dp[len-tl][minb-1] - dp[len-tl][minb]) * sprob[tl];
                dp[len][minb] += dp[len-tl][minb] * (1.0 - sprob[tl]);
            }
//                dp[len][minb] += (1.0-dp[len-tl][minb]) * sprob[tl];
//            if(tl==3)
//            cout << "dp[" << len << "][" << minb << "]: " << dp[len][minb] << endl;
        }

        double expban = 0;
        for1(minb,maxbanana) {
            expban += minb * dp[s][minb];
        }

        double ans = maxbanana-expban;

        cout << ans << endl;
	}

	return 0;
}
