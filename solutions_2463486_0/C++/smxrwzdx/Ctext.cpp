#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int A[210];
long long sav[210];
int o;
bool ispra(long long a)
{
    int i,j,k;
    i=0;
    while(a)
    {
        A[++i]=a%10;
        a/=10;
    }
    bool jud=true;
    for(j=1;j<=i/2;j++) if(A[j]!=A[i+1-j]) jud=false;
    return jud;
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int i,j,k;
    o=0;
    long long a,b;
    for(i=1;i<=10000000;i++)
    {
        a=(long long)i*(long long)i;
        if(ispra((long long)i)&&ispra(a))
        {
            //printf("%d %lld\n",i,a);
            sav[o++]=a;
        }
    }

    int T;
    scanf("%d",&T);
    int tt=0;
    while(T--)
    {
        tt++;
        scanf("%lld%lld",&a,&b);
        int s=0;
        for(i=0;i<o;i++)
        {
            if(sav[i]>=a&&sav[i]<=b) s++;
        }
        printf("Case #%d: %d\n",tt,s);
    }
    return 0;
}
