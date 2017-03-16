#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
       int T,cases,A,B,K,ans,x,y;
       freopen("B-small-attempt0.in","r",stdin);
       freopen("B-small-attempt0.out","w",stdout);
       scanf("%d",&T);
       for (cases=1;cases<=T;cases++)
       {
              scanf("%d%d%d",&A,&B,&K);
              ans=0;
              for (x=0;x<A;x++)
                 for (y=0;y<B;y++)
                    if ((x&y)<K) ans++;
              printf("Case #%d: %d\n",cases,ans);
       }
       return 0;
}
