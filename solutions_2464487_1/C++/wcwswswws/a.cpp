#include<stdio.h>
#include<math.h>
double pi=acos(-1);
long long two=2,one=1,four=4;
bool check(long long mid,long long r,long long t)
{
    if (t/(r*two)+one<mid) return false;
    t-=mid*r*two;if (t<0) return false;
    if (two*t/mid+one<(two+four*(mid-one))) return false;
    t-=(two+four*(mid-one))*mid/two;if (t<0) return false;
    return true;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        long long n,m;scanf("%I64d%I64d",&n,&m);
        long long l=0,r=m;r++;
        while (l!=r)
        {
            long long mid=((l+r)>>1);mid++;
            if (check(mid,n,m)) l=mid; else r=--mid;
        }
        printf("Case #%d: %I64d\n",t,l);
    }
    return 0;
}
