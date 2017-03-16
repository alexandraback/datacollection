#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

LL ai[205],an[205];
LL bi[205],bn[205];
LL tb[205],ta[205];
int main()
{
    freopen("small.in","r",stdin);
    freopen("small.out","w",stdout);
    LL cn,cas,n,m,i,j,k,ans;
    scanf("%I64d",&cas);
    for(cn = 1;cn <= cas;cn ++)
    {
        scanf("%I64d%I64d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%I64d%I64d",&an[i],&ai[i]);
        for(i=0;i<m;i++)
            scanf("%I64d%I64d",&bn[i],&bi[i]);
        for(i=0;i<n;i++)
            ta[i] = an[i];
        for(i=0;i<m;i++)
            tb[i] = bn[i];
        ans = 0;
        if(n == 1)
        {
            LL tmp = 0;
            for(i=0;i<m;i++)
            {
                if(bi[i] == ai[0]) tmp += bn[i];
            }
            ans = tmp;
        }
        else if(i == 2)
        {
            for(i = 0;i<=m;i++)
            {
                LL t0,t1;
                t0 = t1 = 0;
                for(k=0;k<n;k++)
                    an[k] = ta[k];
                for(k=0;k<m;k++)
                    bn[k] = tb[k];
                for(k=0;k<m;k++)
                {
                    if(k < i && k >= 0)
                    {
                        if(bi[k] == ai[0])
                        {
                            LL tx = min(an[0],bn[k]);
                            bn[k] -= tx;
                            an[0] -= tx;
                            t0 += tx;
                        }
                    }
                    if(k < j && k >= i-1)
                    {
                        if(bi[k] == ai[1])
                        {
                            LL tx = min(an[1],bn[k]);
                            bn[k] -= tx;
                            an[1] -= tx;
                            t1 += tx;
                        }
                    }
                }
                ans = max(ans,t0 + t1);
            }
        }
        else if(n == 3)
        {
            for(i = 0;i<=m;i++)
            {
                for(j=i;j<=m;j++)
                {
                    LL t0,t1,t2;
                    t0 = t1 = t2 = 0;
                    for(k=0;k<n;k++)
                        an[k] = ta[k];
                    for(k=0;k<m;k++)
                        bn[k] = tb[k];
                    for(k=0;k<m;k++)
                    {
                        if(k < i && k >= 0)
                        {
                            if(bi[k] == ai[0])
                            {
                                LL tx = min(an[0],bn[k]);
                                bn[k] -= tx;
                                an[0] -= tx;
                                t0 += tx;
                            }
                        }
                        if(k < j && k >= i-1)
                        {
                            if(bi[k] == ai[1])
                            {
                                LL tx = min(an[1],bn[k]);
                                bn[k] -= tx;
                                an[1] -= tx;
                                t1 += tx;
                            }
                        }
                        if(k < m && k >= j - 1)
                        {
                            if(bi[k] == ai[2])
                            {
                                LL tx = min(an[2],bn[k]);
                                bn[k] -= tx;
                                an[2] -= tx;
                                t2 += tx;
                            }
                        }
                    }
                    ans = max(ans,t0 + t1 + t2);
                }
            }
        }
        printf("Case #%I64d: %I64d\n",cn,ans);
    }
    return 0;
}
