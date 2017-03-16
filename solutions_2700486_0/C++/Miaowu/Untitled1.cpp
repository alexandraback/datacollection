#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int cnt;

void P(double t)
{
    printf("Case #%d: %lf\n",cnt++,t);
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int i,j,n,T,x,y;
    scanf("%d",&T);
    cnt=1;
    while(T--)
    {
        scanf("%d%d%d",&n,&x,&y);
        if (x==0 && y==0)
        {
            P(1);
            continue;
        }
        if (x==-2 && y==0 || x==2 && y==0)
        {
            if (n>=4) P(1);
            if (n==1) P(0);
            if (n==2) P(0.5);
            if (n==3) P(3.0/4);
            continue;
        }
        if (x==1 && y==1 || x==-1 && y==1)
        {
            if (n>=5) P(1);
            if (n<=2) P(0);
            if (n==3) P(1.0/4);
            if (n==4) P(1.0/2);
            continue;
        }
        if (x==0 && y==2)
        {
            if (n>=6) P(1);
            if (n<6) P(0);
            continue;
        }
        if (x==-4 && y==0 || x==4 && y==0)
        {
            if (n>=11) P(1);
            if (n<=6) P(0);
            if (n==7) P(1.0/2);
            if (n==8) P(3.0/4);
            if (n==9) P(7.0/8);
            if (n==10) P(15.0/16);
            continue;
        }
        if (x==-3 && y==1 || x==3 && y==1)
        {
            if (n>=12) P(1);
            if (n<=7) P(0);
            if (n==8) P(1.0/4);
            if (n==9) P(4.0/8);
            if (n==10) P(11.0/16);
            if (n==11) P(26.0/(32-2));
            continue;
        }
        if (x==-2 && y==2 || x==2 && y==2)
        {
            if (n>=13) P(1);
            if (n<=8) P(0);
            if (n==9) P(1.0/8);
            if (n==10) P(5.0/16);
            if (n==11) P(15.0/(32-2));
            if (n==12) P(35.0/(64-14));
            continue;
        }
        if (x==-1 && y==3 || x==1 && y==3)
        {
            if (n>=14) P(1);
            if (n<=9) P(0);
            if (n==10) P(1.0/16);
            if (n==11) P(5.0/(32-2));
            if (n==12) P(15.0/(64-14));
            if (n==13) P(1/2);
            continue;
        }
        if (x==0 && y==4)
        {
            if (n>=15) P(1);
            else P(0);
            continue;
        }
        if (x==-6 && y==0 || x==6 && y==0)
        {
            if (n<=15) P(0);
            if (n>=21) P(1);
            if (n==16) P(1.0/2);
            if (n==17) P(3.0/4);
            if (n==18) P(7.0/8);
            if (n==19) P(15.0/16);
            if (n==20) P(31.0/32);
            continue;
        }
        if (x==-5 && y==1 || x==5 && y==1)
        {
            if (n<=16) P(0);
            if (n>=22) P(1);
            if (n==17) P(1.0/4);
            if (n==18) P(4.0/8);
            if (n==19) P(11.0/16);
            if (n==20) P(26.0/32);
            continue;
        }
        if (x==-4 && y==2 || x==4 && y==2)
        {
            if (n<=17) P(0);
            if (n>=23) P(1);
            if (n==18) P(1.0/8);
            if (n==19) P(5.0/16);
            if (n==20) P(15.0/32);
            continue;
        }
        if (x==-3 && y==3 || x==3 && y==3)
        {
            if (n<=18) P(0);
            if (n==19) P(1.0/16);
            if (n==20) P(5.0/32);
            continue;
        }
        if (x==-2 && y==4 || x==2 && y==4)
        {
            if (n<=19) P(0);
            if (n<=20) P(1.0/32);
            continue;
        }
        P(0);
    }
    return 0;
}
