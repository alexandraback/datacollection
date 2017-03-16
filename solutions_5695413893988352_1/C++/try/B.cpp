#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define INF 1000000000000000000LL
using namespace std;

char sx[1<<6],sy[1<<6],tx[1<<6],ty[1<<6];
long long mind,minx,miny,valx,valy;
int n;

void greedy1(int k)
{
    int i;
    strcpy(tx,sx);
    strcpy(ty,sy);
    for(i=k+1;i<n;i++)
    {
        if(tx[i]=='?')
        {
            tx[i]='9';
        }
        if(ty[i]=='?')
        {
            ty[i]='0';
        }
    }
    valx=atoll(tx);
    valy=atoll(ty);
    if((mind>abs(valx-valy))||((mind==abs(valx-valy))&&(minx>valx))||((mind==abs(valx-valy))&&(minx==valx)&&(miny>valy)))
    {
        mind=abs(valx-valy);
        minx=valx;
        miny=valy;
    }
}

void backtrack1(int k)
{
    if(k==n)
    {
        greedy1(k);
        return;
    }
    if((sx[k]=='?')&&(sy[k]=='?'))
    {
        sx[k]='0';
        sy[k]='1';
        greedy1(k);
        sx[k]='0';
        sy[k]='0';
        backtrack1(k+1);
        sx[k]='?';
        sy[k]='?';
    }
    else if((sx[k]=='?')&&(sy[k]=='0'))
    {
        sx[k]='0';
        backtrack1(k+1);
        sx[k]='?';
    }
    else if((sx[k]=='?')&&(sy[k]>='1')&&(sy[k]<='9'))
    {
        sx[k]=sy[k]-1;
        greedy1(k);
        sx[k]=sy[k];
        backtrack1(k+1);
        sx[k]='?';
    }
    else if((sx[k]=='9')&&(sy[k]=='?'))
    {
        sy[k]='9';
        backtrack1(k+1);
        sy[k]='?';
    }
    else if((sx[k]>='0')&&(sx[k]<='8')&&(sy[k]=='?'))
    {
        sy[k]=sx[k]+1;
        greedy1(k);
        sy[k]=sx[k];
        backtrack1(k+1);
        sy[k]='?';
    }
    else if(sx[k]==sy[k])
    {
        backtrack1(k+1);
    }
    else if(sx[k]<sy[k])
    {
        greedy1(k);
    }
    else
    {
        return;
    }
}

void greedy2(int k)
{
    int i;
    strcpy(tx,sx);
    strcpy(ty,sy);
    for(i=k+1;i<n;i++)
    {
        if(tx[i]=='?')
        {
            tx[i]='0';
        }
        if(ty[i]=='?')
        {
            ty[i]='9';
        }
    }
    valx=atoll(tx);
    valy=atoll(ty);
    if((mind>abs(valx-valy))||((mind==abs(valx-valy))&&(minx>valx))||((mind==abs(valx-valy))&&(minx==valx)&&(miny>valy)))
    {
        mind=abs(valx-valy);
        minx=valx;
        miny=valy;
    }
}

void backtrack2(int k)
{
    if(k==n)
    {
        greedy2(k);
        return;
    }
    if((sx[k]=='?')&&(sy[k]=='?'))
    {
        sx[k]='1';
        sy[k]='0';
        greedy2(k);
        sx[k]='0';
        sy[k]='0';
        backtrack2(k+1);
        sx[k]='?';
        sy[k]='?';
    }
    else if((sx[k]=='?')&&(sy[k]=='9'))
    {
        sx[k]='9';
        backtrack2(k+1);
        sx[k]='?';
    }
    else if((sx[k]=='?')&&(sy[k]>='0')&&(sy[k]<='8'))
    {
        sx[k]=sy[k]+1;
        greedy2(k);
        sx[k]=sy[k];
        backtrack2(k+1);
        sx[k]='?';
    }
    else if((sx[k]=='0')&&(sy[k]=='?'))
    {
        sy[k]='0';
        backtrack2(k+1);
        sy[k]='?';
    }
    else if((sx[k]>='1')&&(sx[k]<='9')&&(sy[k]=='?'))
    {
        sy[k]=sx[k]-1;
        greedy2(k);
        sy[k]=sx[k];
        backtrack2(k+1);
        sy[k]='?';
    }
    else if(sx[k]==sy[k])
    {
        backtrack2(k+1);
    }
    else if(sx[k]>sy[k])
    {
        greedy2(k);
    }
    else
    {
        return;
    }
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int c,t;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        scanf("%s %s",sx,sy);
        n=strlen(sx);
        mind=INF;
        minx=INF;
        miny=INF;
        backtrack1(0);
        backtrack2(0);
        printf("Case #%d: %0.*I64d %0.*I64d\n",c+1,n,minx,n,miny);
    }
    return 0;
}
