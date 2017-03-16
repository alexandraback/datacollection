/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
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

int ar[1005];
int go(int m, int D){
    for(int i = 1; i <= m; i++){
        int cnt = 0;
        FOR(j, 1, D+1){
            if(ar[j] <= i) continue;
            int v = ar[j] - i;
            cnt += (v + i - 1) / i;
        }
        if(cnt + i <= m) return 1;
    }
    return 0;
}
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    FOR(ts, 1, T+1){
        int D; cin >> D;
        FOR(i, 1, D+1) cin >> ar[i];

        int lo = 1, hi = 10000, mid = (lo + hi) / 2;
        while(lo < mid){
            if(go(mid, D)) hi = mid;
            else lo = mid + 1;
            mid = (lo + hi) / 2;
        }

        int res = 0;
        for(int i = max(1, mid - 5); i <= mid + 5; i++){
            if(go(i, D)){
                res = i;
                break;
            }
        }

        cout << "Case #" << ts << ": " << res << endl;
        cerr << "Case #" << ts << ": " << res << endl;
    }
}


