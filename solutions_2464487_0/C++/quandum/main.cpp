#include <cstdio>
#include <cmath>
#include <math.h>
using namespace std;
long long r,t,res;
long long outr(long long r){
    return (2*r)-1;
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int test,ntest;    scanf("%d",&ntest);
    long long req;
    for (test=1;test<=ntest;test++){
        res=0;  scanf("%lld %lld",&r,&t);
        r++;
        while (true){
            req=outr(r);
            if (req>t) break;
            t-=req;     res++;
            r+=2;
        }
        if (test>1) printf("\n");
        printf("Case #%d: %lld",test,res);
    }
    return 0;
}
