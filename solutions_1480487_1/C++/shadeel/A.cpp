#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define EPS 1e-8

int main(void){
    
    freopen("AB.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, c=0, n;
    double s[200], tol, low, up, now;
    bool no[200];
    
    scanf("%d", &cas);
    while(cas--){
        
        scanf("%d", &n);
        tol = 0;
        for(int i=0; i<n; ++i){
            scanf("%lf", &s[i]);
            tol += s[i];
        }
        
        low = 0;
        up = tol*2;
        double sum;
        while( up-low > EPS ){
            now = (low+up)/2;
            double sum = 0;
            for(int i=0; i<n; ++i){
                sum += ((now-s[i])/tol);
            }
            if( sum > 1.0 )   up = now;
            else                low = now;
        }
        
        memset(no,0,sizeof(no));
        for(int i=0; i<n; ++i){
            double tmp = ((now-s[i])/tol)*100.0;
            if( tmp<-EPS ) no[i] = true;
        }
        
        low = 0;
        up = tol*2;
        while( up-low > EPS ){
            now = (low+up)/2;
            double sum = 0;
            for(int i=0; i<n; ++i)
            if( !no[i] ){
                sum += ((now-s[i])/tol);
            }
            if( sum > 1.0 )   up = now;
            else              low = now;
        }
        
        printf("Case #%d:", ++c);
        for(int i=0; i<n; ++i)
        if( no[i] ) printf(" 0.000000");
        else        printf(" %lf", ((now-s[i])/tol)*100.0);
        putchar('\n');
    }
    
    return 0;
}
