#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define forn(i,a,b) for( int i = (a); i < (b); i++ )
#define rep(i,n) forn(i,0,n)
#define repe(i,n) for( i = 0; i < (n); i++ )
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>

const int MXH = 2510;

int cnt [MXH];

void solve(){
    rep(i,MXH) cnt[i] = 0;
    int n;
    scanf("%d", &n);

    rep(i,2*n-1){
        rep(j,n){
            int t;
            scanf("%d", &t);
            cnt[t]++;
        }
    }
    rep(i,MXH){
        if(cnt[i]&1){
            printf("%d ", i);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    rep(i,T){
        printf("Case #%d: ", i+1);
        solve();
        printf("\n");
    }

    return 0;
}
