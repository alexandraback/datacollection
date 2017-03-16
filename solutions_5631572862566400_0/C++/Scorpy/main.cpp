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

const int MXN = 2510;

int cnt [MXN];

bool used [MXN];
int to [MXN];

vector<int> ed [MXN];

int dfs(int v){
    used[v] = 1;
    if(!used[to[v]])
        return 1 + dfs(to[v]);
    else
        return 1;
}
int dfs1( int v ){
    int res = 0;
    int sz = ed[v].size();
    rep(i,sz){
        int to = ed[v][i];
        res = max(res, dfs1(to));
    }
    return res + 1;
}

void solve(){
    int n;
    scanf("%d", &n);
    rep(i,n){
        cnt[i] = used[i] = 0;
        ed[i].clear();
    }

    rep(i,n){
        scanf("%d", &to[i]);
        to[i]--;
        cnt[to[i]]++;
        ed[to[i]].pb(i);
    }

    int res = 0;
    rep(i,n){
        if( to[to[i]]==i ){
            int mx1 = 0, mx2 = 0;
            int sz = ed[i].size();
            rep(j,sz){
                if(ed[i][j]!=to[i]){
                    int t = dfs1(ed[i][j]);
                    if(t > mx1)
                        mx1 = t;
                }
            }
            sz = ed[to[i]].size();
            rep(j,sz){
                if(ed[to[i]][j]!=i){
                    int t = dfs1(ed[to[i]][j]);
                    if(t>mx2)
                        mx2 = t;
                }
            }
            res += 2+mx1+mx2;
        }
    }
    res /= 2;

    rep(i,n){
        rep(i,n){
            if(cnt[i]==0){
                cnt[to[i]]--;
                cnt[i] = -1;
            }
        }
    }

    rep(i,n){
        if(cnt[i]>0){
            res = max(res, dfs(i));
        }
    }

    printf("%d", res);
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
