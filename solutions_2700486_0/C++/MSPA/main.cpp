#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <assert.h>

#define file_name ""

typedef long long ll;

const int N = 1e5+5;

using namespace std;

int k,d,m,c,must;
int b[11];
inline void rec(int i)
{
    if (i==m)
    {
        k++;
        if (b[0]>=must) c++;
        return;
    }
    if (b[0]<d)
    {
        b[0]++;
        rec(i+1);
        b[0]--;
    }
    if (b[1]<d)
    {
        b[1]++;
        rec(i+1);
        b[1]--;
    }
}

inline void f(int t, double x)
{
    printf("Case #%d: %.6lf\n",t,x);
}
int a[25][2];
int main()
{
    // freopen(file_name".in","r",stdin);
    // freopen(file_name".out","w",stdout);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int Test;
    int n,x,y;
    a[0][0] = 0; a[0][1] = 0;
    a[1][0] = 2; a[1][1] = 0;
    a[2][0] = 1; a[2][1] = 1;
    a[3][0] = 0; a[3][1] = 2;
    a[4][0] = 4; a[4][1] = 0;
    a[5][0] = 3; a[5][1] = 1;
    a[6][0] = 2; a[6][1] = 2;
    a[7][0] = 1; a[7][1] = 3;
    a[8][0] = 0; a[8][1] = 4;
    a[9][0] = 6; a[9][1] = 0;
    a[10][0] = 5; a[10][1] = 1;
    a[11][0] = 4; a[11][1] = 2;
    a[12][0] = 3; a[12][1] = 3;
    a[13][0] = 2; a[13][1] = 4;
    scanf("%d",&Test);
    for(int t=1;t<=Test;++t)
    {
        scanf("%d%d%d",&n,&x,&y);
        x=abs(x);
        if (n<7)
        {
            if (x+y==0)
            {
                f(t,1.0);
            }
            else if (x==2 && y==0)
            {
                if (n==1) f(t,0.0);
                if (n==2) f(t,0.5);
                if (n==3) f(t,0.75);
                if (n==4) f(t,1.0);
                if (n==5) f(t,1.0);
                if (n==6) f(t,1.0);
            }
            else if (x==1 && y==1)
            {
                if (n==1) f(t,0.0);
                if (n==2) f(t,0.0);
                if (n==3) f(t,0.25);
                if (n==4) f(t,0.5);
                if (n==5) f(t,1.0);
                if (n==6) f(t,1.0);
            }
            else if (x==0 && y==2)
            {
                if (n==6) f(t,1.0);
                else f(t,0.0);
            }
            else f(t,0.0);
            continue;
        }
        int i=0;
        for(i=0;i<14;++i)
            if (a[i][0]==x && a[i][1]==y) break;
        if (i==14)
        {
            f(t,0.0);
            continue;
        }

        c=0;
        k=0;
        b[0]=b[1]=0;
        //int col=6;
        if (i<4)
        {
            f(t,1.0);
            continue;
        }
        else if (i<9)
        {
            d=4;
            must=i-3;
            if (n>=15)
            {
                f(t,1.0);
                continue;
            }
            m = n-6;
            rec(0);

            f(t,1.0*c/k);

        }
        else
        {
            d=5;
            m=n-15;
            if (m<=0)
            {
                f(t,0);
                continue;
            }
            must=i-8;
            rec(0);
            f(t,1.0*c/k);

        }
    }
    return 0;
}
