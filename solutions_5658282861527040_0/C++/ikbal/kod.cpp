#include <algorithm>
#include <iostream>
#include <cstring>
#include <limits>
#include <complex>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#include <set>

#define type(x) __typeof((x).begin())
#define foreach(it,x) for(__typeof(x.begin()) it = x.begin() ; it!=x.end() ; it++ )

#ifdef KAZAR
    #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

using namespace std;

template<class T> inline void umax(T &a,T b){if(a<b) a = b ; }
template<class T> inline void umin(T &a,T b){if(a>b) a = b ; }
template<class T> inline T abs(T a){return a>0 ? a : -a;}
template<class T> inline T gcd(T a,T b){return __gcd(a,b);}
template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}

const int inf = 1e9 + 143;
const long long longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

int main(){

#ifdef KAZAR
	freopen("f.input","r",stdin);
	freopen("f.output","w",stdout);
	freopen("error","w",stderr);
#endif

    int tc = read();

    for(int it = 1; it <= tc; it++){
        printf("Case #%d: ",it);
        int a = read();
        int b = read();
        int k = read();
        int res = 0;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                if((i & j) < k)
                    res++;
            }
        }
        printf("%d\n",res);
    }

    return 0;
}
