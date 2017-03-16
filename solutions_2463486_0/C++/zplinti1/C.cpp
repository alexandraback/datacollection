#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn=10000000+2;
int num[maxn];
int a[30];

bool check(long long x)
{
    int k=0;
    while(x>0)
    {
        a[k++]=x%10;
        x/=10;
    }
    for(int i=0;i<k/2;i++)
     if (a[i]!=a[k-1-i]) return 0;
    return 1;
}

int main()
{
    int cas;
    long long L,R;

    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    num[0]=0;
    for(int i=1;i<maxn;i++)
    {
        num[i]=num[i-1];
        if (check(i)&&check(1LL*i*i)) num[i]++;
    }
    scanf("%d",&cas);
    for(int ii=1;ii<=cas;ii++)
    {
        scanf("%lld%lld",&L,&R);
        long long l=(long long) sqrt(L*1.0);
        while (l*l<L) l++;
        long long r=(long long) sqrt(R*1.0);
        while(r*r>R) r--;
        long long ans=0;
        if (l>r) ans=0;
        else ans=num[r]-num[l-1];
        printf("Case #%d: %lld\n",ii,ans);
    }
    return 0;
}

