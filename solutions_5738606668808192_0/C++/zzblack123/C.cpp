/***************************************
      zzblack                         **
      2016-04-09                      **
      Orz                             **
****************************************/
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define ls id<<1,l,mid
#define rs id<<1|1,mid+1,r
#define OFF(x) memset(x,-1,sizeof x)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(x) memset(x,0x3f,sizeof x)
typedef long long ll ;
typedef pair<int,int> pii ;
const int maxn = 1e5 + 50 ;
const int maxm = 1e6 + 50;
const double eps = 1e-10;
const int max_index = 62;
const int inf = 0x3f3f3f3f ;
const int MOD = 1e9+7 ;

inline int read(){
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    int x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int n, j;
ll p[11];

ll solve(ll base, ll x) {
    ll y = 0, res = 0;
    while (x) {
        y <<= 1;
        if (x & 1) y++;
        x >>= 1;
    }
    x = y;
    while (x) {
        res = res * base;
        if (x & 1) res++;
        x >>= 1;
    }
    return res;
}

ll judge(ll x) {
    for (ll i = 2; i * i <= x; i++) {
        if (x % i) continue;
        return i;
    }
    return x;
}

void print(ll x) {
    if (x > 1) print(x >> 1);
    printf("%I64d", x & 1);
}

int main () {
#ifdef LOCAL
	freopen("C:\\Users\\zzblack\\Desktop\\C-small-attempt1.in","r",stdin);
      freopen("C:\\Users\\zzblack\\Desktop\\out.txt","w",stdout);
#endif
    int T = read();
    while (T--) {
        n = read(), j = read();
        int ans = 0;
        printf("Case #%d:\n", 1);
        for (int i = 0; i < 1 << n - 2; i++) {
            ll x = (1 << n - 1) + (i << 1) + 1;
            bool flag = 1;
            for (int k = 2; k <= 10; k++) {
                if (flag == 0) break;
                ll num = solve(k, x);
                p[k] = judge(num);
                if (p[k] == num) flag = 0;
            }
            if (flag) {
                ans++;
                print(x);
                for (int k = 2; k <= 10; k++) {
                    printf(" %I64d", p[k]);
//                    printf(" %I64d\n", solve(k, x));
                }
                puts("");
            }
            if (ans == j) break;
        }
    }


	return 0;
}
