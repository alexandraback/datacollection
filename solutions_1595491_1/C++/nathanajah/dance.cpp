#include <stdio.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
using namespace std;

int t,aaaa;
int n,s;
int p;
int tt[400];
int i,j;
int bbaw;
int ret;

int main()
{
    scanf("%d",&t);
    for (aaaa=0;aaaa<t;++aaaa)
    {
        ret=0;
        scanf("%d %d %d",&n,&s,&p);
        bbaw=p+2*max(p-2,0);
        for (i=0;i<n;++i)
            scanf("%d",&tt[i]);
        sort(tt,tt+n);
        for (i=0;i<n;++i)
        {
            if ((tt[i]+2)/3>=p)
                ++ret;
            else if (tt[i]>=bbaw && s>0)
            {
                ++ret;
                --s;
            }
        }
        printf("Case #%d: %d\n",aaaa+1,ret);
    }
}
