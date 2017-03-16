#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repf(i, f, l) for(int i = f; i < (int)l; ++i)
#define repit(it, t) for(__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++)

#define endl "\n"

#ifdef ONLINE_JUDGE
#define DEBUG false
#else
#define DEBUG true
#endif

#define pb emplace_back
#define lb lower_bound
#define ul unsigned long
#define ull unsigned long long
#define ll long long
#define INF 1000000007
#define MOD 1000000007
#define fs first
#define sd second
#define DBG0(x) if(DEBUG){ cout << #x << ": " << x << "\t"; }
#define DBG(x) if(DEBUG){DBG0(x); cout << endl;}
#define DBG2(x, y) if(DEBUG){DBG0(x); DBG(y);}
#define DBG3(x, y, z) if(DEBUG){DBG0(x); DBG2(y, z);}
#define DBG4(w, x, y, z) if(DEBUG){DBG0(w); DBG3(x, y, z);}

typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ul> vul;
typedef vector<ull> vull;
typedef vector<bool> vbl;
typedef pair<int, int> pii;

void solve(int tcnum){
    ll p, q;
    scanf("%lld/%lld\n", &p, &q);
    printf("Case #%d: ", tcnum);

    ll g = __gcd(p, q);
    p /= g;
    q /= g;

    ll q0 = q;
    while(q0 % 2 == 0) q0 /= 2;
    if(q0 != 1){
        printf("impossible\n");
        return;
    }
    int ret = 1;
    while(!(0 <= 2 * p - q && 2*p - q <= q)){
        ret++;
        q /= 2;
    }
    cout << ret << endl;
    return;
}
int main(void){
    int t;
    cin >> t;
    rep(i, t) solve(i + 1);
    return 0;
}
