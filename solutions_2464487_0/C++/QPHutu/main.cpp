#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
long long check(long long r,long long M,long long n)
{
    long long tp=M-(2*r-1)*n;
    long long h=sqrt(tp/2);
    if(h<n)return 0;
    return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,T=0;
    scanf("%d",&t);
    while(t--)
    {
        long long r,M;
        scanf("%lld%lld",&r,&M);
        long long L=1,R=M/(2*r);
        while(L<R)
        {
            long long mid=(L+R+1)/2;
            if(!check(r,M,mid))R=mid-1;
            else L=mid;
        }
        printf("Case #%d: ",++T);
        printf("%lld\n",L);
    }
    return 0;
}
