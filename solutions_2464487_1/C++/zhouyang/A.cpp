#include <stdio.h>
long long r,t,m;
long double abs(long double t){return (t>0)?t:-t;}
int cmp(long long n,long long k)
{
    long long t1=2*n-1+2*r;
    long double t3=((long double)k)/(long double)n;
    if (abs((long double)t1-t3)<1e-12) return 0;
    if ((long double)t1-t3>1e-12) return 1;
    return -1;
}
inline long long gets(long long n)
{
    return (long long)2*n*n-n+2*n*r;
}
long long findp(long long i,long long j,long long k)
{
    if (i>j) return m-1;
    if (i==j) return i;
    long long mid=(i+j)/2;
    if (cmp(mid,k)==0) return mid;
    if (cmp(mid,k)==-1) return findp(mid+1,j,k);
    return findp(i,mid,k);
}
int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%I64d%I64d",&r,&t);
        long long ans=findp(1,3707106780,t);
        if (cmp(ans,t)!=0) --ans;
        printf("Case #%d: %I64d\n",++cas,ans);
    }
}
