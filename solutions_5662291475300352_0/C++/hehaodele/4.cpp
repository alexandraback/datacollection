#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cmath"
#include "cstring"
#include "cstdlib"
#include "climits"
#include "cassert"
#include "bitset"
#include "complex"
#include "queue"
#include "vector"
#include "queue"
#include "set"
#include "map"
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define rep(i, n) for(int i=0; i<n; i++)
#define repp(i, a, b) for(int i=a; i<a+b; i++)
using namespace std;
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MK make_pair
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ITR iterator
#define LB lower_bound
#define UB upper_bound
#define PII pair<int, int>
#define CLR(a) memset(a, 0, sizeof(a))
int getint(){
    int s = 0, o = 1;
    char c;
    for(c = getchar(); c<'0'||c>'9';c = getchar()) if(c=='-') o = -1;
    for(;c>='0'&&c<='9'; c = getchar()) s *=10, s+=c-'0';
    return s*o;
}
  
const int maxn = 10010;
int d[maxn], c[maxn], tot;
int sol(){
    // printf("%d\n", tot);
    if(tot==1) return 0;
    if(d[0] < d[1]) swap(d[0], d[1]), swap(c[0], c[1]);
    double x0 = (360. - d[0]) / 360 * c[0], x1 = (360. - d[1]) / 360 * c[1];
    double x00 = x0 + c[0], x11 = x1 + c[1];
    if(x1 >= x00 || x11 <= x0) return 1;
    return 0;
}
int main(int argc, char const *argv[])
{   
    int cas = getint();
    rep(ca,cas){
        int n = getint();
        tot = 0;
        rep(i,n){
            int D = getint();
            int m = getint();
            int mm = getint();
            rep(j,m){
                d[tot] = D, c[tot] = mm++;
                ++tot;
            }
        }
        printf("Case #%d: %d\n", ca+1, sol());
    }
    return 0;
}