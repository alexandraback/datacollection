#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>

using namespace std;

int ok,tot,n,x,y;

bool g[200][200];

void tryy(int k,int ltx,int lty,int rtx,int rty)
{
    if(k==n)
    {
        tot++;
        if(g[x][y])ok++;
        return;
    }
    if(ltx!=100)
    {
        g[ltx][lty]=true;
        tryy(k+1,ltx+1,lty+1,rtx,rty);
        g[ltx][lty]=false;
    }
    if(rtx!=100)
    {
        g[rtx][rty]=true;
        tryy(k+1,ltx,lty,rtx-1,rty+1);
        g[rtx][rty]=false;
    }
    if(ltx==100 && rtx==100)
    {
        g[ltx][lty]=true;
        tryy(k+1,100-lty-2,0,100+rty+2,0);
        g[ltx][lty]=false;
    }
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("x.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int K=1;K<=T;K++)
    {
        scanf("%d%d%d",&n,&x,&y);
        if(x>=50 || x<=-50 || y>=190)
        {
            printf("Case #%d: 0.0\n",K);
            continue;
        }
        x+=100;
        memset(g,false,sizeof(g));
        g[100][0]=true;
        tot=0;
        ok=0;
        tryy(1,98,0,102,0);
        double ans=(double)ok/(double)tot;
        printf("Case #%d: %lf\n",K,ans);
    }
    return 0;
}
