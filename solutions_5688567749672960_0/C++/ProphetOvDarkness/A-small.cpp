/*
*Sourav Sen Tonmoy
*University of Dhaka
*/

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

#define OK printf("ok\n")
#define DB(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pii;

int setBit(int N, int pos) { return N=N | (1<<pos); }
int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


int dp[1000010];

int rev(int x) {
    if(x%10 == 0) return INT_MAX;
    char str[10] = {0};
    int key = 0;
    while(x) {
        str[key++] = x%10 + '0';
        x/=10;
    }
    return atoi(str);
}

int DP(int n) {
    if(n == 1) return 1;
    if(n < 1) return 1000000000;

    if(dp[n] != 0) return dp[n];

    int ret1=INT_MAX, ret2=INT_MAX;
    ret1 = 1 + DP(n-1);
    int x = rev(n);
    if(x < n) ret2 = 1 + DP(x);
    return dp[n] = min(ret1, ret2);
}

int main() {
    freopen("A-small.in","r",stdin);
    freopen("A-small-out.out","w",stdout);

    int test, kase=1, n;

    for(int i=1000; i<=1000000; i+=1000) DP(i);

    sdi(test);
    while(test--) {
        sdi(n);
        printf("Case #%d: %d\n", kase++, DP(n));
    }

    return 0;
}
