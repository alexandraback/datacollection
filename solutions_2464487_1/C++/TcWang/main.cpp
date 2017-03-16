#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

long long ans,sum,last;
double r,t;

int main()
{
    int T;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++) {
        scanf("%lf%lf",&r,&t);
        /*sum=2*r+1;
        last=2*r+5;
        ans=1;
        for (;sum<=t-last;ans++) {
            sum+=last;
            last+=4;
        }*/
        double delta=sqrt(4*r*r-4*r+1+8*t);
        delta-=2*r;
        delta+=1;
        delta/=4;
        long long ans=(long long)delta;
        //printf("%d\n",((int)delta));
                printf("Case #%d: %lld\n",cases,ans);
          //if ((int)delta==ans) printf("yes\n");else printf("fuck!!!!\n");
    }
    return 0;
}
