#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define red(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define RED true
#define BLACK false
#define pb push_back
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ii, int> iii;
typedef vector<int> vi;
const int N = 1e6 + 7;
const int M = 1e9;
const int inf = 1e9 + 7;
const int base = 1e9 + 9;
const double pi = acos(-1);
const double ep = 1e-9;

int dp[N];
int pa[N];

ll rev(ll x){
    ll tmp = 0;
    while (x > 0){
        tmp = tmp * 10 + x % 10;
        x /= 10;
    }
    return tmp;
}

ll cnt(ll x){
    //cout<<x<<endl;
    if (x < 15000) return dp[(int)x];
    int tol = 0;
    ll ss = x;
    //cout<<ss<<endl;
    while (x > 0){
        x/=10;
        tol++;
    }
    ll tmp = 1;
    rep(t, 0, tol/2) tmp *= 10;
    //cout<<tmp<<" "<<ss<<endl;
    ll mod = ss % tmp;
    if (mod == 1 && rev(ss) < ss) return cnt(rev(ss)) + 1;
    else if (mod > 1) return cnt(ss-mod+1) + (mod-1);
    else return cnt(ss-1) + 1;

}

int main(){
    freopen("A-large (1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    rep(i, 0, N) dp[i] = inf;
    dp[1] = 1;
    pa[1] = -1;
    for(int i = 1; i < N - 3; i++){
        //dp[i+1] = min(dp[i+1], dp[i] + 1);
        if (dp[i+1] > dp[i] + 1){
            dp[i+1] = dp[i] + 1;
            pa[i+1] = pa[i];
         }
        int c = rev(i);
        if (c < N && dp[c] > dp[i] + 1){
            dp[c] = dp[i] + 1;
            pa[c] = c;
        }
    }
    int test;
    cin >> test;
    rep(ii, 1, test + 1){
        ll u;
        cin >> u;
        printf("Case #%d: %lld\n", ii, cnt(u));
    }
}

// 1 2 3 4 5 6
// 6 5 4 3 2 1

