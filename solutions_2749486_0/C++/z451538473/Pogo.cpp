#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int abs(int k)
{
    return k>0?k:-k;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        printf("Case #%d: ",cas);
        int x,y;
        scanf("%d%d",&x,&y);
        int step=1;
        if(x<0)
        {
            for(int i=0;i<abs(x);i++)
                printf("EW");
        }
        else
        {
            for(int i=0;i<abs(x);i++)
                printf("WE");
        }
        if(y<0)
            for(int i=0;i<abs(y);i++)
                printf("NS");
        else
            for(int i=0;i<abs(y);i++)
                printf("SN");
        printf("\n");
    }
}
