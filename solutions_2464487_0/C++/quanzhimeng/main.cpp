#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
//    freopen("C:\Users\asus\Desktop\download\A-small-attempt0.in","r",stdin);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cases,cases1;
    long long r,t,ans;
    double tmp;
    scanf("%d",&cases);
    cases1=1;
    while(cases--)
    {
        printf("Case #%d: ",cases1);
        cases1++;
        scanf("%lld%lld",&r,&t);
        tmp=sqrt((2*r-1)*(2*r-1)+8*t);
        tmp=((1-2*r)+tmp)/4;
        ans=tmp;
        printf("%lld\n",ans);
    }
    return 0;
}

//2r+2n-1  *n  <=t
