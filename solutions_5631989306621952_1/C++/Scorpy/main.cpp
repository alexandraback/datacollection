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

const int MXN = 1010;

char s [MXN];

void solve(){
    deque<char> ans;
    scanf("%s", s);
    int n = strlen(s);

    ans.push_back(s[0]);
    forn(i,1,n){
        if(s[i]<ans.front()){
            ans.push_back(s[i]);
        }
        else{
            ans.push_front(s[i]);
        }
    }
    rep(i,n){
        printf("%c", ans.front());
        ans.pop_front();
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
