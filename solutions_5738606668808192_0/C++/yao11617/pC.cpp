#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1024

void pri(int k,int n)
{
    putchar('1');
    for(int i=n-2;i>=0;--i)
        putchar('0'+(k>>i&1));
}

int _pow(int a,int b,int m)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%m;
        a=a*a%m;
        b>>=1;
    }
    return ans;
}

int check(int k,int b,int n)
{
    int t=b&1;
    for(int j=0,d=1,e=std::min(n,32);j<e;++j,d=d*b&1)if(k>>j&1)t+=d;
    if(!(t&1))return 2;
    for(int i=3;i<N;i+=2)
    {
        t=_pow(b,n-1,i);
        for(int j=0,d=1,e=std::min(n,32);j<e;++j,d=d*b%i)if(k>>j&1)t+=d;
        if(t%i==0)return i;
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;++tc)
    {
        int n,j,cnt=1,i,a[16];
        scanf("%d%d",&n,&j);
        printf("Case #%d:\n",tc);
        while(j)
        {
            for(i=2;i<11;++i)
                if(!(a[i]=check(cnt,i,n)))break;
            if(i==11)
            {
                pri(cnt,n);
                for(int i=2;i<11;++i)printf(" %d",a[i]);
                printf("\n");
                --j;
            }
            cnt+=2;
        }
    }
    return 0;
}
