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
long long rev(long long x){
    long long y = 0;
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

long long sol(long long n){
    if(n<1) return 0;
    // printf("n %lld\n", n);
    long long r = n;
    int len = 0;
    for(long long x = n; x; ++len, x/=10);
    ll mi = 1;
    rep(i,(len+1)/2) mi *= 10;
    long long m = n / mi * mi + 1;
    // printf("m %lld\n", m);
    // if(m==n+1){
        // ll rr = sol(n-1) + 1;
        // r = min(rr, r);
    // }else
    if(m<=n && rev(m)<n){
        // printf("?\n");
        long long rr = sol(rev(m)) + (m!=rev(m)) + n - m;
        r = min(rr, r);
    }else{
        // ll m2 = 1;
        // rep(i,len-1) m2 *= 10;
        // m2--;
        // ll rr = sol(m2) + n - m2;
        // r = min(rr, r);
        r = min(r, sol(n-1) + 1);
    }
    return r;
}

int main(int argc, char const *argv[])
{   
    int cas = getint();
    long long n;
    rep(ca,cas){
        cin >> n;
        printf("Case #%d: %lld\n", ca+1, sol(n));
    }
    return 0;
}