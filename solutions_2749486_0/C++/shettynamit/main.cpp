#include <iostream>
#include <cstdio>
using namespace std;

void go(int x,string D)
{
    int s;
    if(x<0)
    {
        s=0;
        x=-x;
    }
    else
        s=1;
    for(int i=0;i<(x<<1);i++)
    {
        printf("%c",D[s]);
        s=1-s;
    }
}

int main()
{
    freopen("B-small.in","r",stdin);
    freopen("B-small.out","w",stdout);
    int t,x,y;
    scanf("%d",&t);
    string NS="NS";
    string EW="EW";
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",i);
        go(x,EW);
        go(y,NS);
        printf("\n");
    }
    return 0;
}
