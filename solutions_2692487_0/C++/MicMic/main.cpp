#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
using namespace std;
int motes[MAXN];
int getsum(int r[],int t)
{
    int res=0;
    for(int i=0;i<t;i++)
    {
        res+=r[i];
    }
    return res;
}
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int testcas;
    scanf("%d",&testcas);
    for(int z=1; z<=testcas; z++)
    {
        long long ar,n;
        scanf("%lld %lld",&ar,&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&motes[i]);
        }
        int res[MAXN]={0};
        if(ar==1)
        {
            printf("Case #%d: %lld\n",z,n);
            continue;
        }
        sort(motes,motes+n);
        for(int i=0; i<n; i++)
        {
            if(ar==motes[i])
            {
                ar=ar+ar-1;
                res[i]++;
                ar+=motes[i];
            }
            else if(ar<motes[i])
            {
                while(ar<=motes[i])
                {
                    ar=ar+ar-1;
                    res[i]++;
                }
                ar+=motes[i];
            }
            else
            {
                ar+=motes[i];
            }
        }
        long long ans=1000000000000;
        for(int i=0;i<=n;i++)
        {
            ans=min(ans,getsum(res,i)+n-i);
        }
        printf("Case #%d: %lld\n",z,ans);
    }
    return 0;
}
