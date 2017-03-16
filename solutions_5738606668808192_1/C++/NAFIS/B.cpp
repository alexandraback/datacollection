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


int isp(LL p){
    for(LL i = 2; i * i <= p; i++){
        if(p % i == 0) return 0;
    }
    return 1;
}

vector < pair < LL, vector < int > > > res;

int main() {
//    freopen("a.in", "r", stdin);
    freopen("a2.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    set < LL > S;
    int n = 32;
    cout << "Case #1: " << endl;
    REP(i, 500){
        while(1){
            LL v = rand() % (1<<(n-2));
            v |= 1<<(n-2);
            v = (v * 2ll) + 1;
            if(S.count(v)) continue;
            vector < int > vc;
            for(LL j = 2; j <= 10; j++){
                int fl = 0;
                for(LL k = 2; k <= 10000; k++){
                    LL p = 1, s = 0;
                    REP(l, n){
                        if(v & 1ll<<l) s = (s + p) % k;
                        p = (p * j) % k;
                    }
                    if(s == 0){
                        vc.pb(k);
                        fl = 1;
                        break;
                    }
                }

                if(fl == 0) break;
            }
            if(vc.size() != 9) continue;
            S.insert(v);

            string out = "";
            REP(j, n) if(v & 1ll<<j) out += "1";
            else out += "0";
            reverse(out.begin(), out.end());
            cout << out;

            REP(j, vc.size()) cout << " " << vc[j];
            cout << endl;
            cerr << v << " " << i << endl;
            break;
        }
    }
}
