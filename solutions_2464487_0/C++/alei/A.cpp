#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
typedef unsigned long long int uli;
int main(){
    freopen("asmall.in","r",stdin);
    freopen("asmall.out","w",stdout);
    int T;
    uli r,t;
    scanf("%d",&T);
    for(int c=0;c<T;c++){
        scanf("%lld %lld",&r,&t);
        long double dr = r;
        long double dt = t;
        long double dans = (sqrt((2*dr-1)*(2*dr-1) + 8*dt) - 2*dr + 1)/4;
        uli ans = dans;
        if(ans<0) ans = 0;
        printf("Case #%d: %lld\n",c+1, ans);
    }
    return 0;
}
