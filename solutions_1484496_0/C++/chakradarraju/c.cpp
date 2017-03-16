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

int reach[maxval];
set<int> st[maxval];
int a[22];

int main (int argc, char const* argv[]) {
    
    int t = GI, kase = 1;
    while(t--) {
        int n = GI;
        REP(i,n) a[i] = GI;
        printf("Case #%d:\n",kase++);
        bool found = false;
        REP(i,(1<<n)) {
            int sum = 0;
            REP(j,n) if((i>>j)&1) sum += a[j];
            if(reach[sum]==kase) {
                found = true;
                REP(j,n) if((i>>j)&1) printf("%d ",a[j]); printf("\n");
                EACH(it,st[sum]) printf("%d ",*it); printf("\n");
                break;
            }
            reach[sum] = kase;
            set<int> ss;
            REP(j,n) if((i>>j)&1) ss.insert(a[j]);
            st[sum] = ss;
        }
        if(!found) printf("Impossible\n");
    }
    
    return 0;
}

