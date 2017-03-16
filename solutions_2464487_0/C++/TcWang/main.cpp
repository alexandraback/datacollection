#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

long long r,t,ans,sum,last;

int main()
{
    int T;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++) {
        scanf("%lld%lld",&r,&t);
        sum=2*r+1;
        last=2*r+5;
        ans=1;
        for (;sum<=t-last;ans++) {
            sum+=last;
            last+=4;
        }
        printf("Case #%d: %lld\n",cases,ans);
    }
    return 0;
}
