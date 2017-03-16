#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int T;
int x,y;
int xx,yy;

int main()
{
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d %d",&x,&y);
        printf("Case #%d: ",i);
        xx=x;yy=y;
        if(xx<0) xx=-x;
        if(yy<0) yy=-y;
        for(int j=1;j<=xx;j++)
        {
            if(x<0) printf("EW"); else printf("WE");
        }
        for(int j=1;j<=yy;j++)
        {
            if(y>0) printf("SN"); else printf("NS");
        }
        printf("\n");
    }
    return 0;
}
