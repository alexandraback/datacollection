#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cassert>
#include <limits.h>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))
#define S(t,i) scanf("%" ## t, &i)
#define SI(i) scanf("%d", &i)

int t;
long double c,f,x;

int main() {
    //ios_base::sync_with_stdio(0);
    
    SI(t);
    
    FOR(ti, 1,t) {
        scanf("%Lf %Lf %Lf",&c,&f,&x);
        
        LD rate=2;
        LD totaltime=0;
        
        
        while (true) {
            LD time1=totaltime+x/rate;
            LD time2=totaltime+(c/rate)+(x/(rate+f));
            if (time1>time2) {
                totaltime+=(c/rate);
                rate+=f;
                
            } else {
                printf("Case #%d: %.7Lf\n",ti,time1);
                break;
            }
            
        }
    }
    
    
    
	return 0;
}

