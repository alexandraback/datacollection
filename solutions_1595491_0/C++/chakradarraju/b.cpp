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
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;} 
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;} 
using namespace std;

int main (int argc, char const* argv[]) {
    
    int t = GI, kase = 1;
    while(t--) {
        int n = GI, s = GI, p = GI, ans = 0;
        REP(i,n) {
            int tt = GI;
            if(tt+2>=3*p) ans++;
            else if(s>0&&tt+4>=3*p&&tt>=p) ans++, s--;
        }
        printf("Case #%d: %d\n",kase++,ans);
    }
    
    return 0;
}

