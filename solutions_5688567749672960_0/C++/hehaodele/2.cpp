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
  
const int maxn = 1000010;
priority_queue<pair<int,int> > Q;
int d[maxn];
int rev(int x){
    int y = 0;
    while(x){
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}

void run(){
    rep(i,maxn) d[i] = i+1;
    d[1] = 1;
    Q.push(MK(-1,1));
    while(!Q.empty()){
        int u = Q.top().Y;
        // printf("%d %d\n", );
        Q.pop();
        int v = u+1;
        if(v >= maxn) continue;
        if(d[v] > d[u] + 1){
            d[v] = d[u] + 1;
            Q.push(MK(-d[v],v));
        }
        v = rev(u);
        if(v >= maxn) continue;
        if(d[v] > d[u] + 1){
            d[v] = d[u] + 1;
            Q.push(MK(-d[v],v));
        }
    }
    // repp(i,1,maxn-1) if(d[i]!=d[i-1]+1) printf("%d %d\n", i, d[i]);
}
int main(int argc, char const *argv[])
{   
    run();
    int cas = getint();
    rep(ca,cas){
        int n = getint();
        printf("Case #%d: %d\n", ca+1, d[n]);
    }
    return 0;
}