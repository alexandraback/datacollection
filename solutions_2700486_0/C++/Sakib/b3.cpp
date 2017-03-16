#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#define inf 1000000000

using namespace std;

int n,X,Y,h[300000],M;
double tot,ok;

void work(int p,double d)
{
    int a,b,i,j,k,nx,ny,x,y,px,py;

    x=M;

    if(p==n)
    {
        //tot+=d;;

        if(h[X]>=Y) ok+=d;
    }

    else
    {
        k=h[x];
        j=k+1;

        nx=x;
        ny=j+1;

        if(h[x-1]>=j-1 && h[x+1]>=j-1)
        {
            px=h[x];
            h[x]+=2;
            work(p+1,d);
            h[x]=px;
        }

        else if(h[x-1]<j-1 && h[x+1]>=j-1)
        {
            while(h[nx-1]<ny-2)
            {
                nx--;
                ny--;
            }

            px=h[nx];
            h[nx]=ny;
            work(p+1,d);
            h[nx]=px;


        }

        else if(h[x-1]>=j-1 && h[x+1]<j-1)
        {
            while(h[nx+1]<ny-2)
            {
                nx++;
                ny--;
            }

            px=h[nx];
            h[nx]=ny;
            work(p+1,d);
            h[nx]=px;
        }

        else if(h[x-1]<j-1 && h[x+1]<j-1)
        {
            while(h[nx-1]<ny-2)
            {
                nx--;
                ny--;
            }

            px=h[nx];
            h[nx]=ny;
            work(p+1,d/2.0);
            h[nx]=px;

            nx=x;
            ny=j+1;

            while(h[nx+1]<ny-2)
            {
                nx++;
                ny--;
            }

            px=h[nx];
            h[nx]=ny;
            work(p+1,d/2.0);
            h[nx]=px;
        }



    }
}

int main()
{
    int i,j,k,t,T;

    M=10500;

    //freopen("in.txt","r",stdin);
    freopen("B-small-attempt2.in","r",stdin);
    freopen("b-smallNEW.txt","w",stdout);

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d",&n,&X,&Y);

        tot=ok=0;

        for(i=M-200;i<=M+200;i++)
        {
            if(i%2) h[i]=-1;
            else h[i]=-2;
        }


        X+=M;

        for(i=X-200;i<=X+200;i++)
        {
            if(i%2) h[i]=-1;
            else h[i]=-2;
        }
        work(0,1.0);

        printf("Case #%d: %.8lf\n",t,ok);


    }

    return 0;
}
