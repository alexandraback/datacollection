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
const int mx = 103;

char target[mx], key[mx];
int k, l, s;

int fa[mx][30];

void pre() {
    ini(fa, 0);
    fo(i, l + 1) {
        fo(nxt, 26) {
            fo(start, i + 1) {
                bool match = true;
                fo(j, i - start) if(target[start + j] != target[j]) {
                    match = false;
                    break;
                }
                if(match && target[i - start] - 'A' == nxt) {
                    fa[i][nxt] = i - start + 1;
                    break;
                }
            }
            //trace3(i, nxt, fa[i][nxt]);
        }
    }
}

double dp[mx][mx];
int vis[mx][mx];
double solve(int i, int a) {
    double &ret = dp[i][a];
    if(vis[i][a]) return ret;
    vis[i][a] = 1;

    ret = 0;
    if(a == l) ret = 1;
    if(i == s) return ret;

    double tmp = 0;

    fo(j, k) tmp += solve(i + 1, fa[a][key[j] - 'A']);
    ret += tmp / k;

    //trace3(i, a, ret);
    return ret;
}

int max_dp[mx][mx];

int max_solve(int i, int a) {
    int &ret = max_dp[i][a];
    if(ret != -1) return ret;
    ret = 0;
    if(a == l) ret = 1;
    if(i == s) return ret;

    int tmp = 0;
    fo(j, k) tmp = max(tmp, max_solve(i + 1, fa[a][key[j] - 'A']));

    ret += tmp;

    return ret;
}


int main() {
    //freopen("sample.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("small0.txt", "w", stdout);

    //freopen("B-large.in", "r", stdin);
    //freopen("large.txt", "w", stdout);
    
    int kases;
    scanf("%d", &kases);
    for(int kase = 1; kase <= kases; ++kase) {
        trace1(kase);
        scanf("%d %d %d", &k, &l, &s);
        scanf("%s %s", key, target);

        pre();
        ini(vis, 0);
        ini(max_dp, -1);

        printf("Case #%d: ", kase);
        printf("%.07lf\n", max_solve(0, 0) - solve(0, 0));
    }
    
	return 0;
}
