#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int i,j;
    int x,y;
    int tcase=1;
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&x,&y);
        printf("Case #%d: ",tcase++);
        if(x<0)
        {
            for(j=0;j<-x;j++)
            {
                printf("EW");
            }
        }
        else
        {
            for(j=0;j<x;j++)
            {
                printf("WE");
            }
        }
        if(y<0)
        {
            for(j=0;j<-y;j++)
            {
                printf("NS");
            }
        }
        else
        {
            for(j=0;j<y;j++)
            {
                printf("SN");
            }
        }
        printf("\n");
    }
}
