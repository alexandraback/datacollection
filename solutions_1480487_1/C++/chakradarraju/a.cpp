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

const double eps = 1e-10;
double a[220];

int main (int argc, char const* argv[]) {
    
    int t = GI, kase = 1;
    while(t--) {
        int n = GI;
        double x = 0;
        REP(i,n) x += a[i] = GI;
        printf("Case #%d: ",kase++);
        REP(sel,n) {
            double lo = 0, hi = 1.0;
            while(lo+eps<hi) {
                double md = (lo+hi)/2, top = a[sel]+md*x, tot = 0.0;
                REP(i,n) if(a[i]<top) tot += top-a[i];
                if(tot<x) lo = md;
                else hi = md;
            }
            lo *= 100.0;
            printf("%.7lf ",lo);
        }
        printf("\n");
    }
    
    return 0;
}

