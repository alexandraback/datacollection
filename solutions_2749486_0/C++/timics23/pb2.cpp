#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int T,X,Y;
int main()
{
    freopen("input.in","r",stdin);
    freopen("bla.out","w",stdout);
    scanf("%d",&T);
    for(int x=1;x<=T;++x)
    {
        scanf("%d%d",&X,&Y);
        printf("Case #%d: ",x);
        if(X>0)
            for(int i=1;i<=X;++i)
                printf("WE");
        if(X<0)
            for(int i=1;i<=-X;++i)
                printf("EW");

        if(Y>0)
            for(int i=1;i<=Y;++i)
                printf("SN");

        if(Y<0)
            for(int i=1;i<=-Y;++i)
                printf("NS");

        printf("\n");

    }
    return 0;
}

