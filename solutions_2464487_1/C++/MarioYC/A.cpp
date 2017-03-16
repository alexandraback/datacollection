#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int T;
    long long r,t;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%lld %lld",&r,&t);
        
        long long lo = 1,hi = 1000000000,mi;
        
        while(lo < hi){
            mi = (lo + hi + 1) >> 1;
            
            if(2 * r + 2 * mi - 1 <= t / mi) lo = mi;
            else hi = mi - 1;
        }
        
        printf("Case #%d: %lld\n",tc,lo);
    }
    
    return 0;
}
