#include <bits/stdc++.h>

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin(); i!=(n).end(); i++)

#define sz(x) (int) x.size()
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x));

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define eps 1e-9
#define OK printf("ok\n")
#define DB(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pii;

inline int setBit(int N, int pos) { return N=N | (1<<pos); }
inline int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


LL n, m, p;
bool ans[55][55];

inline bool check() {
    LL i;
    p=1;
    rep(i, n-2) p *= 2;
    if(p < m) return false;
    else return true;
}

inline void solve() {
    LL i, j;
    mem(ans, 0);
    repl(i, n) {
        for(j=1; j<=i; j++)
        ans[i][j]=0;
        for(j=i+1; j<n; j++)
        ans[i][j]=1;
    }
    if(m==p) for(i=1; i<n; i++) ans[i][n]=1;
    else {
        ans[1][n] = 0;
        for(i=2; i<n; i++) {
            if(m%2) ans[i][n] = 1;
            else ans[i][n] = 0;
            m/=2;
        }
    }
    repl(i, n) {
        repl(j, n) {
            printf("%d", (int)ans[i][j]);
        }
        puts("");
    }
}

int main() {
    freopen("B-small.in","r",stdin);
    freopen("B-small.out","w",stdout);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    LL test, kase=1;

    sdl(test);
    while(test--) {
        sdll(n, m);
//        pfll(n, m);
        printf("Case #%lld: ", kase++);
        if(!check()) {
            puts("IMPOSSIBLE");
            continue;
        }
        puts("POSSIBLE");
        solve();
    }

    return 0;
}
