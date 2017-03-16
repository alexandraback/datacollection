#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
    int p,cnt,i,j,k;
    int r,t;
    double d,x;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    scanf("%d",&p);
    for(cnt=1;cnt<=p;cnt++)
    {
        scanf("%d %d",&r,&t);
        d=sqrt((2*r-1)*(2*r-1)+8*t);
        x=(d+1-2*r)/4;
        printf("Case #%d: %d\n",cnt,(int)x);
    }
}
