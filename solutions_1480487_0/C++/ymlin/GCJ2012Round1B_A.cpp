// GCJ2012Round1B_A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
    freopen("c:/txt/GCJ2012R1B-A-small.txt","r",stdin);
//    freopen("c:/txt/1B-a-result.txt","w",stdout);

    int i, j, t, n, a;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int s[200]={0};
        scanf("%d",&n);
        int x=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&a);
            s[j]=a;
            x+=a;
        }
        double d=((double)x*2)/n;
        printf("Case #%d: ", i+1);
        for(j=0;j<n;j++)
        {
            double y=(d-s[j])*100/x;
            printf("%.6f ", y);
        }
        printf("\n");
    }

    printf("Hello World!\n");
    return 0;
}

