#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>


using namespace std;

typedef long long ll;
const int INF=0x3f3f3f3f;

const int N=200;
const int prime=1000000007;
int a[N],b[N],c[N];
ll dp0[N];
ll dp1[N];
ll dp2[N];
ll dp3[N];
ll d0[N];
ll d1[N];
ll d2[N];
ll d3[N];
int main()
{
    //freopen("data.txt","r",stdin);
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin>>T;
    for(int ca=1; ca<=T; ++ca)
    {
        printf("Case #%d: ",ca);
        ll A,B,C;
        cin>>A>>B>>C;
        A-=1;
        B-=1;
        C-=1;
        int la=0,lb=0,lc=0;
        ll tmp=A;
        while(tmp)
        {
            a[la++]=(tmp&0x01);
            tmp=tmp>>1;
        }
        tmp=B;
        while(tmp)
        {
            b[lb++]=(tmp&0x01);
            tmp=tmp>>1;
        }
        tmp=C;
        while(tmp)
        {
            c[lc++]=(tmp&0x01);
            tmp=tmp>>1;
        }
        memset(dp0,0,sizeof(dp0));
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        memset(dp3,0,sizeof(dp3));
        memset(d0,0,sizeof(dp0));
        memset(d1,0,sizeof(dp1));
        memset(d2,0,sizeof(dp2));
        memset(d3,0,sizeof(dp3));
        int n=max(la,max(lb,lc));
        d3[n]=1;
        for(int l=n; l>0; --l)
        {
            for(int i=0; i<=a[l-1]; ++i)
                for(int j=0; j<=b[l-1]; ++j)
                {
                    if(i==a[l-1]&&j==b[l-1])
                    {
                        if((i&j)<c[l-1])
                            dp3[l-1]+=d3[l];
                        else if((i&j)==c[l-1])
                            d3[l-1]+=d3[l];
                    }
                    if(i==a[l-1]&&j!=b[l-1])
                    {
                        if((i&j)<c[l-1])
                            dp2[l-1]+=d3[l];
                        else if((i&j)==c[l-1])
                            d2[l-1]+=d3[l];
                    }
                    if(i!=a[l-1]&&j==b[l-1])
                    {
                        if((i&j)<c[l-1])
                            dp1[l-1]+=d3[l];
                        else if((i&j)==c[l-1])
                            d1[l-1]+=d3[l];
                    }
                    if(i!=a[l-1]&&j!=b[l-1])
                    {
                        if((i&j)<c[l-1])
                            dp0[l-1]+=d3[l];
                        else if((i&j)==c[l-1])
                            d0[l-1]+=d3[l];
                    }
                }
            for(int i=0; i<=a[l-1]; ++i)
                for(int j=0; j<=1; ++j)
                {
                    if(i==a[l-1])
                    {
                        if((i&j)<c[l-1])
                            dp2[l-1]+=d2[l];
                        else if((i&j)==c[l-1])
                            d2[l-1]+=d2[l];
                    }
                    if(i!=a[l-1])
                    {
                        if((i&j)<c[l-1])
                            dp0[l-1]+=d2[l];
                        else if((i&j)==c[l-1])
                            d0[l-1]+=d2[l];
                    }
                }
            for(int i=0; i<=1; ++i)
                for(int j=0; j<=b[l-1]; ++j)
                {
                    if(j==b[l-1])
                    {
                        if((i&j)<c[l-1])
                            dp1[l-1]+=d1[l];
                        else if((i&j)==c[l-1])
                            d1[l-1]+=d1[l];
                    }
                    if(j!=b[l-1])
                    {
                        if((i&j)<c[l-1])
                            dp0[l-1]+=d1[l];
                        else if((i&j)==c[l-1])
                            d0[l-1]+=d1[l];
                    }
                }
            for(int i=0; i<=1; ++i)
                for(int j=0; j<=1; ++j)
                {
                    if((i&j)<c[l-1])
                        dp0[l-1]+=d0[l];
                    else if((i&j)==c[l-1])
                        d0[l-1]+=d0[l];
                }


            for(int i=0; i<=a[l-1]; ++i)
                for(int j=0; j<=b[l-1]; ++j)
                {
                    if(i==a[l-1]&&j==b[l-1])
                    {
                        dp3[l-1]+=dp3[l];
                    }
                    if(i==a[l-1]&&j!=b[l-1])
                    {
                        dp2[l-1]+=dp3[l];
                    }
                    if(i!=a[l-1]&&j==b[l-1])
                    {
                        dp1[l-1]+=dp3[l];
                    }
                    if(i!=a[l-1]&&j!=b[l-1])
                    {
                        dp0[l-1]+=dp3[l];
                    }
                }
            for(int i=0; i<=a[l-1]; ++i)
                for(int j=0; j<=1; ++j)
                {
                    if(i==a[l-1])
                    {
                        dp2[l-1]+=dp2[l];
                    }
                    if(i!=a[l-1])
                    {
                        dp0[l-1]+=dp2[l];
                    }
                }
            for(int i=0; i<=1; ++i)
                for(int j=0; j<=b[l-1]; ++j)
                {
                    if(j==b[l-1])
                    {
                        dp1[l-1]+=dp1[l];
                    }
                    if(j!=b[l-1])
                    {
                        dp0[l-1]+=dp1[l];
                    }
                }
            for(int i=0; i<=1; ++i)
                for(int j=0; j<=1; ++j)
                {
                    dp0[l-1]+=dp0[l];
                }
        }
        cout<<(dp0[0]+dp1[0]+dp2[0]+dp3[0]+d0[0]+d1[0]+d2[0]+d3[0])<<endl;

    }
    return 0;
}
