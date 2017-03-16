#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#define LL long long
using namespace std;

int aa[50], bb[50], cc[50];
int a, b, c, na, nb, nc, k;
LL f[50][2][2][2];
LL dfs(int n, bool ea, bool eb, bool ec){
    if(n == 0) return !ea&&!eb&&!ec;
    if(~f[n][ea][eb][ec]) return f[n][ea][eb][ec];
    LL ans = 0;
    int ua = (ea ? aa[n] : 1);
    int ub = (eb ? bb[n] : 1);
    int uc = (ec ? cc[n] : 1);
    for(int i = 0; i <= ua; ++i) for(int j = 0; j <= ub; ++j){
        int kk = (i & j);
        if(kk > uc) continue;
        ans += dfs(n - 1, ea && i == aa[n], eb && j == bb[n], ec && kk == cc[n]);
    }
    //cout<<n<<"  "<<ea<<"  "<<eb<<"  "<<ec<<"   "<<ans<<"  "<<endl;
    return f[n][ea][eb][ec] = ans;
}

void solve(){
    na = 0, nb = 0, nc = 0;
    memset(aa, 0, sizeof(aa));
    memset(bb, 0, sizeof(bb));
    memset(cc, 0, sizeof(cc));
    while(a){
        aa[++na] = a&1;
        a >>= 1;
    }
    while(b){
        bb[++nb] = b & 1;
        b >>= 1;
    }
    while(c){
        cc[++nc] = c & 1;
        c >>= 1;
    }
    //cout<<" === "<<na<<"  "<<nb<<"  "<<nc<<endl;
    k = max(na, nb);
    k = max(k, nc);
    memset(f, -1, sizeof(f));
    //cout<<k<<endl;
    LL ans = dfs(k, 1, 1, 1);
    cout<<ans<<endl;
}

int main (){
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int t, tt = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &a, &b, &c);
        printf("Case #%d: ", ++tt);
        solve();
    }
    return 0;
}
