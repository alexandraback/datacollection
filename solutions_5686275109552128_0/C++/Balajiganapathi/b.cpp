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
const int mx = 1003;

int p[mx], n;

int brute() {
    const int till = 20;
    int ans = oo;
    fo(mask, (1 << till)) {
        vi tmp1, tmp;
        fo(i, n) tmp.pu(p[i]);

        fo(t, till) {
            sort(all(tmp));
            tmp1.clear();
            if(((mask >> t) & 1) && tmp.back() != 1) {
                fo(i, si(tmp) - 1) tmp1.pu(tmp[i]);
                int x = tmp.back();
                tmp1.pu(x / 2);
                tmp1.pu(x - x / 2);
            } else {
                fo(i, si(tmp)) if(tmp[i] != 1) tmp1.pu(tmp[i] - 1);
            }
            tmp = tmp1;
            if(si(tmp) == 0) {
                ans = min(ans, t + 1);
                break;
            }
        }

        int cur = till;
        while(si(tmp)) {
            tmp1.clear();
            fo(i, si(tmp)) if(tmp[i] != 1) tmp1.pu(tmp[i] - 1);
            tmp = tmp1;
            ++cur;
        }
        if(cur > till) ans = min(ans, cur);

        assert(si(tmp) == 0);
    }

    return ans;
}

int main() {
    //freopen("sample.txt", "r", stdin);
    freopen("B-small-attempt1.in", "r", stdin);
    //freopen("B-large.in", "r", stdin);

    //freopen("output.txt", "w", stdout);
    freopen("small1.txt", "w", stdout);
    //freopen("large.txt", "w", stdout);
    
    int kases;
    scanf("%d", &kases);
    for(int kase = 1; kase <= kases; ++kase) {
        scanf("%d", &n);
        fo(i, n) scanf("%d", p + i);
        sort(p, p + n);
        reverse(p, p + n);

        int ans = oo;
        rep(k, 1, p[0]) {
            int cur = 0;
            fo(i, n) {
                if(p[i] > k) {
                    cur += p[i] / k;
                    if(p[i] % k == 0) --cur;
                }
            }
            ans = min(ans, cur + k);
        }


        //int bans = brute();
        //trace3(kase, ans, bans);
        //assert(ans == bans);
        printf("Case #%d: %d\n", kase, ans);
    }
    
	return 0;
}
