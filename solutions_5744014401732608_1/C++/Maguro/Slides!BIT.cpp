#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;
long long n,m;
int main()
{
    long long t,T,i,j,k,lv;
    vector<long long> v;
//    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld %lld",&n,&m);
        printf("Case #%lld: ",t);
        if(m<=1)
        {
            printf("POSSIBLE\n");
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(m==1&&i==1&&j==n)
                        printf("1");
                    else
                        printf("0");
                }
                printf("\n");
            }
            continue;
        }
        if(m==2)
        {
            printf("POSSIBLE\n");
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(i==1&&j==n)
                        printf("1");
                    else if(i==1&&j==n-1)
                        printf("1");
                    else if(i==n-1&&j==n)
                        printf("1");
                    else
                        printf("0");
                }
                printf("\n");
            }
            continue;
        }
        m-=2;
        j=1;
        lv=0;
        while(135)
        {
            m-=j;
            if(m<0)
            {
                m+=j;
                break;
            }
            j*=2;
            lv++;
        }
        v.clear();
        k=0;
        while(m>0)
        {
            v.emplace_back(m%2);
            m/=2;
            k++;
        }
        while(k<lv)
            v.emplace_back(0),k++;
        if(n-lv-1<=1)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        else
        {
            printf("POSSIBLE\n");
        }
        for(i=1;i<n-lv-1;i++)printf("0");
        printf("1");
        for(i=v.size()-1;i>=0;i--)
        {
            printf("%lld",v[i]);
        }
        printf("1\n");
        for(i=2;i<=n-lv-2;i++)
        {
            for(j=1;j<=n;j++)
                printf("0");
            printf("\n");
        }
        for(i=n-lv-1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(j>i)
                    printf("1");
                else
                    printf("0");
            }
            printf("\n");
        }
    }
}


