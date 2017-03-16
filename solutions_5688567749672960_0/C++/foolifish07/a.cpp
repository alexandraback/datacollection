#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>

#define LL long long 
using namespace std;

LL n;
int d[30] , dn;
LL gao(LL n){
    if ( n<10 ) return n-1;

    LL x = n; dn = 0;
    while ( x>0 ){
        d[++dn] = x%10;
        x /= 10;
    }
    LL res = n, y1,y2;
    for(int i=0;i<=dn;i++){
        y1 = y2 = 0;
        for(int j=i+1;j<=dn;j++)
            y1 = y1*10+d[j];
        for(int j=i;j>=1;j--)
            y2 = y2*10+d[j];
        res = min(res, y1+y2);
    }
    LL xx = 1;
    for(int i=1;i<dn;i++) xx *= 10;
    
    return min(n-xx,res);
}

int main(){

    int t;  scanf("%d",&t);
    for(int it=1;it<=t;it++){
        scanf("%lld" , &n);
        printf("Case #%d: ",it );
        LL x = 9 , ans = 1;
        while(x<n){
            ans += gao(x)+1;
            x = x*10+9;
        }
        if ( x+1!=n ) ans += gao(n);
        printf("%lld\n" , ans);
    }

    return 0;
}