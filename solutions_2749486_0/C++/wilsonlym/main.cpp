#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
    freopen("x.in","r",stdin);
    freopen("x.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int K=1;K<=T;K++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",K);
        if(x>=0)
        {
            for(int i=0;i<x;i++)
              printf("WE");
        }
        else
        {
            for(int i=0;i<-x;i++)
              printf("EW");
        }
        if(y>=0)
        {
            for(int i=0;i<y;i++)
              printf("SN");
        }
        else
        {
            for(int i=0;i<-y;i++)
              printf("NS");
        }
        puts("");
    }
    return 0;
}
