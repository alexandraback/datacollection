#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define sz size()
#define pb push_back
#define _(x,a) memset(x,a,sizeof(x))
#define LET(x,a) typeof(a) x(a)
#define GFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define EACH(i,v) GFOR(i,(v).begin(),(v).end())
#define LL long long
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define maxval 2000010
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;} 
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;} 
using namespace std;

int mark, vis[maxval];

int main (int argc, char const* argv[]) {
    
    int t = GI, kase = 1;
    while(t--) {
        int a = GI, b = GI, ans = 0;
        FOR(x,a,b) {
            mark++;
            int end = 1, rx = 0, xx = x, cnt = 0, now = x;
            while(xx) rx *= 10, rx += xx%10, xx /= 10, end *= 10, cnt++;
            REP(i,cnt) {
                if(now>=a&&now<=b&&now>x&&now<maxval&&vis[now]<mark) ans++, vis[now] = mark;
                now = (now*10)%end + rx%10; rx /= 10;
            }
        }
        printf("Case #%d: %d\n",kase++,ans);
    }
    
    return 0;
}

