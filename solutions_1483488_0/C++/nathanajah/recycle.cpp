#include <stdio.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
using namespace std;

int i;
int lol;
int n,m;
int t,aaaa;
int p10[9];
int pjg;
long long hit;

int panjang(int x)
{
    int ret=-1;
    while (x>0)
    {
        ++ret;
        x/=10;
    }
    return ret;
}
int main()
{
    scanf("%d",&t);
    p10[0]=1;
    for (i=1;i<9;++i)
        p10[i]=p10[i-1]*10;
//    t=50;
    for (aaaa=0;aaaa<t;++aaaa)
    {
        hit=0;
        scanf("%d %d",&n,&m);
//        n=1;
//        m=2000000;
        for (i=n;i<=m;++i)
        {
            lol=i;
            pjg=panjang(lol);
            lol=(lol/10)+(lol%10)*p10[pjg];
            while (lol!=i)
            {
                if (panjang(lol)==pjg && lol>=n && lol<=m && i<lol)
                {
                    ++hit;
                }
                lol=(lol/10)+(lol%10)*p10[pjg];
            }
        }
        printf("Case #%d: %lld\n",aaaa+1,hit);
    }
}
