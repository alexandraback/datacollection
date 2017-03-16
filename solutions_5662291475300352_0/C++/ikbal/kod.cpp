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

const long double eps = 1e-10;

int calc(long double x1,long double t1,long double x2,long double t2){
    long double v1 = 360 / t1;
    long double v2 = 360 / t2;
    if(v1 > v2){
        long double dx = x1 + 360 - x2;
        long double dt = dx / (v1 - v2);
        if(dt * v1 + x1 > 360){
            return 0;
        }else{
            return calc(x2 + dt * v2, t2, x1 + dt * v1, t1);
        }
    }else{
        long double dx = x1 + 360 - x2;
        long double dt = dx / (v2 - v1);
        if(dt * v1 + x1 > 360){
            return 0;
        }else{
            return 1;
        }
    }
}

void solve(){
    int n = read();
    vector<ii> hs;
    for(int i = 1; i <= n; i++){
        int d = read();
        int h = read();
        int m = read();
        for(int v = m; v <= m + h - 1; v++){
            hs.push_back({d, v});
        }
    }
    if(hs.size() == 1){
        puts("0");
        return;
    }
    assert(hs.size() == 2);
    int x1 = hs[0].first;
    int t1 = hs[0].second;
    int x2 = hs[1].first;
    int t2 = hs[1].second;
    if(x1 > x2){
        swap(x1, x2);
        swap(t1, t2);
    }
    if(t1 == t2){
        puts("0");
        return;
    }
    printf("%d\n",calc(x1, t1, x2, t2));
}

int main(){

#ifdef KAZAR
    freopen("f.input","r",stdin);
    freopen("f.output","w",stdout);
    freopen("error","w",stderr);
#endif

    srand(time(0));
    int tc = read();

    for(int i = 1; i <= tc; i++){
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
