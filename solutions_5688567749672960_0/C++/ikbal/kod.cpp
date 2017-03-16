#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <complex>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>

#define all(x) (x).begin(), (x).end()

#ifdef KAZAR
    #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

using namespace std;

template<class T> inline void umax(T &a,T b){if(a<b) a = b ; }
template<class T> inline void umin(T &a,T b){if(a>b) a = b ; }
template<class T> inline T abs(T a){return a>0 ? a : -a;}
template<class T> inline T gcd(T a,T b){return __gcd(a, b);}
template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}

typedef long long ll;
typedef pair<int, int> ii;

const int inf = 1e9 + 143;
const ll longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

const int N = 1e6 + 100;

int f[N];

int rev(int x){
    int res = 0;
    while(x > 0){
        int v = x % 10;
        res *= 10;
        res += v;
        x /= 10;
    }
    return res;
}

void solve(){
    int n = read();
    f[1] = 1;
    for(int i = 2; i <= n; i++){
        f[i] = f[i - 1] + 1;
    //    eprintf("i = %d, rev = %d, f = %d\n", i, rev(i), f[i]);
        if(i % 10 != 0 && rev(i) < i)
            umin(f[i], f[rev(i)] + 1);
    }
    printf("%d\n", f[n]);
}

int main(){

#ifdef KAZAR
    freopen("f.input","r",stdin);
    freopen("f.output","w",stdout);
    freopen("error","w",stderr);
#endif

    int tc = read();

    for(int i = 1; i <= tc; i++){
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
