#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int n,m,i,j,k,l,T,tt;
    freopen("B.out","w",stdout);
    tt=0;
    scanf("%d",&T);
    while(T--){
        double t,c,f,x,inc,ans=100000000;
        scanf("%lf%lf%lf",&c,&f,&x);
        inc=2;t=0;
        for(i=0;i<=100000;i++){
            ans=min(ans,t+x/inc);
            t+=c/inc;
            inc+=f;
        }
        tt++;
        printf("Case #%d: %.7f\n",tt,ans);
    }
    return 0;
}
