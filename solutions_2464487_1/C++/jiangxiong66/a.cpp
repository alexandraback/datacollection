#include<cstdio>

long long int limit,a;

long long int cal(long long int k)
{
     double temp=((2.0*a+k-1.0)*k/2.0);
     if(temp>(limit+0.000000000001)) return limit+1;
     return (long long int)temp;
}

long long int bs(long long int s,long long e)
{
    if(s==e) return s;
    long long int mid=(s+e)/2;
    long long int temp=cal(mid);
    if(temp==limit) return mid;
    if(temp<limit) {
         if(cal(mid+1)>limit) return mid;
         else return bs(mid+1,e);
    }
    else return bs(s,mid-1);
}

int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    int cas=1;
    long long int ub=2;
    for(int i=0;i<9;i++) ub*=10;
    while(t--) {
        scanf("%lld%lld",&a,&limit);
        printf("Case #%d: %lld\n",cas++,bs(1,ub)/2);
    }
    return 0;
}
