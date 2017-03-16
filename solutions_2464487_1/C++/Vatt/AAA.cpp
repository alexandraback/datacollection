#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
unsigned long long r,t;
int T;
long long binary(unsigned long long h1,long long h2)
{
        if(h1==h2) return h1;
        long long mid =(h1+h2+1)/2;
        if(2*r+2*mid-1>t/mid)
        {
                return binary(h1,mid-1);
        }
        return binary(mid,h2);
}
main()
{
        freopen("A-large.in","r",stdin);
        freopen("outAAA.txt","w",stdout);
        scanf("%d",&T);
        for(int rr=1;rr<=T;rr++)
        {
                scanf("%I64d %I64d",&r,&t);
                printf("Case #%d: %I64d\n",rr,binary(0,1000000000));
        }
        //system("pause");
}
