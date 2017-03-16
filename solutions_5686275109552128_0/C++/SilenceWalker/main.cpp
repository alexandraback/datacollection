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
const int maxn = 1000000 + 5;
int n;
int a[maxn],b[maxn];

int Cal(int limit)
{
    int cost = 0;
    rep(i,0,n) if (a[i] > limit) {
        int diff = a[i] - limit;
        cost += diff / limit;
        if (diff % limit) ++cost;
    }
    return cost + limit;
}

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
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",a+i);
        sort(a,a+n);
        reverse(a,a+n);
        int ans = 1e9;
        rep(i,1,a[0]+1) ans = min(ans, Cal(i));
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}



