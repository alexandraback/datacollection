#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        100000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


LL go(LL r, LL l, LL K, LL C){
//    cout << l << " " << r << endl;
    LL ret = r, len = 1;
    for(LL i = r-1; i >= l; i--){
        len *= K;
        ret += (i-1)*len;
    }
    return ret;
}


int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    FOR(ts, 1, T+1){
        LL K, C, S; cin >> K >> C >> S;
        cout << "Case #" << ts << ":";

        if(S < ((K+C-1)/C)){
            cout << " IMPOSSIBLE" << endl;
            continue;
        }

        vector < LL > res;
        if(C > K){
            res.pb(go(K, 1, K, C));
        }

        for(int i = K-C+1; i >= 1; i -= C){
            res.pb(go(i+C-1, i, K, C));
            if(i != 1 && i-C < 1) i = C+1;
        }

        REP(i, res.size()) cout << " " << res[i];
        cout << endl;
    }


}
/*
LLLG
LLLGLLLGLLLGGGGG
LLLGLLLGLLLGGGGGLLLGLLLGLLLGGGGGLLLGLLLGLLLGGGGGGGGGGGGGGGGGGGGG

LLGL
LLGLLLGLGGGGLLGL
LLGLLLGLGGGGLLGLLLGLLLGLGGGGLLGLGGGGGGGGGGGGGGGGLLGLLLGLGGGGLLGL
LGLL
LGLLGGGGLGLLLGLL
LGLLGGGGLGLLLGLLGGGGGGGGGGGGGGGGLGLLGGGGLGLLLGLLLGLLGGGGLGLLLGLL

GLLL
GGGGGLLLGLLLGLLL
GGGGGGGGGGGGGGGGGGGGGLLLGLLLGLLLGGGGGLLLGLLLGLLLGGGGGLLLGLLLGLLL
*/
