//Coder: Balajiganapathi
#ifndef ONLINE_JUDGE
#   define DEBUG
#   define TRACE
#else
//#   define NDEBUG
#endif

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

// Basic macros
#define fi          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fo(i,n)     re(i,0,n)
#define rev(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define repv(i,n,s) for(int i=(n);i>=s;--i)
#define fov(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define si(x)       (int)(x.size())

#ifdef TRACE
    #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
    #define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
    #define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
    #define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
#else
    #define trace(x)
    #define trace1(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
    #define trace4(a,b,c,d)
    #define trace5(a,b,c,d,e)
    #define trace6(a,b,c,d,e,f)
#endif

const int oo = 1000000009;
const double eps = 1e-6;
const int mod = 1000000007;
const int mx_l = 10004;
const int mx_x = 100;
const int mx = mx_l * (mx_x + 1);


// 0  1  2  3  4  5  6  7
// 1  i  j  k  -1 -i -j -k
int mult[4][4] = {
    {0, 1, 2, 3},
    {1, 4, 3, 6},
    {2, 7, 4, 1},
    {3, 2, 5, 4}
};

int get(int a, int b) {
    int sign = 1;
    if(a >= 4) {
        sign *= -1;
        a -= 4;
    }
    if(b >= 4) {
        sign *= -1;
        b -= 4;
    }
    int c = mult[a][b];
    if(c >= 4) {
        sign *= -1;
        c -= 4;
    }
    if(sign == -1) c += 4;
    return c;
}

int get_idx(char c) {
    return c - 'i' + 1;
}

int product[8][8];

void init() {
    fo(i, 8) fo(j, 8) product[i][j] = get(i, j);
}

int l, n;
ll x;
char inp[mx];
char vis[mx][8][3], mark;
char dp[mx][8][3];
int seq[mx];
int suffix[mx];

char solve(int i, int cur, int nxt) {
    if(nxt == 4) return i == n || suffix[i] == 0;
    if(i == n) return 0;

    char &ret = dp[i][cur][nxt-1];
    if(vis[i][cur][nxt-1] == mark) return ret;
    vis[i][cur][nxt-1] = mark;
    ret = 0;

    if(product[cur][seq[i]] == nxt) ret = solve(i + 1, 0, nxt + 1);
    if(!ret) {
        ret = solve(i + 1, product[cur][seq[i]], nxt);
    }
    //trace4(i, cur, nxt, int(ret));

    return ret;
}

void dosolve() {
    for(int i = n - 1; i >= 0; --i) {
        fo(cur, 8) rep(nxt, 1, 3) solve(i, cur, nxt);
    }
}

int main() {
    //freopen("sample.txt", "r", stdin);
    //freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-large.in", "r", stdin);

    //freopen("output.txt", "w", stdout);
    //freopen("small2.txt", "w", stdout);
    freopen("large.txt", "w", stdout);

    init();
    
    int kases;
    scanf("%d", &kases);
    for(int kase = 1; kase <= kases; ++kase) {
        scanf("%d %lld %s", &l, &x, inp);
        fo(i, l) inp[i] = get_idx(inp[i]);

        int cur = 0;
        for(int i = l - 1; i >= 0; --i) {
            cur = product[inp[i]][cur];
            suffix[i] = cur;
        }

        int once = cur;
        int for1 = 1;
        for(; cur != 0; cur = product[cur][once]) ++for1;
        assert(for1 <= 4);

        int save = min(1ll * mx_x, x);
        if(save == mx_x) {
            for(; save % for1 != x % for1; --save);
        }
        //save = x;

        n = save * l;
        assert(n < mx);

        cur = 0;
        suffix[n] = 0;
        for(int i = n - 1; i >= 0; --i) {
            seq[i] = inp[i % l];
            cur = product[seq[i]][cur];
            suffix[i] = cur;
        }

        trace6(kase, l, x, for1, save, n);
        ++mark;
        dosolve();
        char ans = solve(0, 0, 1);

        printf("Case #%d: %s\n", kase, (ans? "YES": "NO"));
    }
    
	return 0;
}
