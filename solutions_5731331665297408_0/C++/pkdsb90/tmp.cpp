#pragma  comment(linker, "/STACK:36777216")
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define  lc(x) (x<<1)
#define  rc(x) (lc(x)+1)
#define  PI    (acos(-1))
#define  EPS   1e-8
#define  MAXN  222222
#define  MAXM  888888
#define  LL    long long
#define  ULL   unsigned long long
#define  INF   0x7fffffff
#define  pb    push_back
#define  mp    make_pair
#define  mod   1000000007
#define  lowbit(x) (x&(-x))

using namespace std;

string ans, hh[55];
int d[55], flag[55], n;
vector <int> e[55];

void gao(int x, int num, string now){
    if(d[x] == 0){
        now += hh[x];
        num ++;
    }
    if(num == n){
        ans = min(ans, now);
        return;
    }
    d[x] ++;
    for(int i = 0; i < e[x].size(); i ++){
        if(flag[e[x][i]] == 0){
            flag[e[x][i]] = x;
            gao(e[x][i], num, now);
            flag[e[x][i]] = 0;
        }
        else if(flag[x] == e[x][i]){
            flag[x] = -1;
            gao(e[x][i], num, now);
            flag[x] = e[x][i];
        }
    }
    d[x] --;
}

void init(){
    memset(flag, 0, sizeof(flag));
    for(int i = 1; i <= n; i ++) e[i].clear();
}

int t, m, u, v;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    for (int cas = 1; cas <= t; cas ++){
        scanf("%d%d", &n, &m);
        init();
        for(int i = 1; i <= n; i ++) cin >> hh[i];
        for(int i = 1; i <= m; i ++){
            scanf("%d%d", &u, &v);
            e[u].pb(v), e[v].pb(u);
        }
        ans = "";
        for(int i = 1; i <= n; i ++) ans += "99999";
        for(int i = 1; i <= n; i ++){
            flag[i] = -1;
            gao(i, 0, "");
            flag[i] = 0;
        }
        printf("Case #%d: ", cas);
        cout << ans << endl;
    }
}
