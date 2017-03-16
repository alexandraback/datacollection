#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <time.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,b,a) for(int i=(b);i>=(a);--i)
#define clr(a,x) memset(a,(x),sizeof(a))
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
const int maxn = 2000 + 5;
char S[maxn];

int main()
{
    //Getinput(); return 0;
    #ifdef ACM
        freopen("in.txt","r",stdin);
        //freopen("out.out","w",stdout);
       // freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif // ACM

    int T; cin >> T;
    rep(cas,1,T+1) {
        int n; scanf("%d",&n);
        scanf("%s",S);
        int clap = 0;
        int ans = 0;
        rep(i,0,n+1) if (S[i] > '0') {
            if (clap < i) ans += i - clap, clap = i;
            clap += S[i] - '0';
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}



