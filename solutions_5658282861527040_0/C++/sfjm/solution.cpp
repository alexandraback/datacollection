#include<cstdio>
#include<cstring>
#include<vector>
using namespace std ;

int main()
{
     freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    long long a,b,k;
    long long ans ;
    int _,ca=1;
    scanf ("%d",&_);
    while(_--)
    {
        scanf ("%lld%lld%lld",&a,&b,&k);
        ans= 0 ;
        for ( int i = 0 ; i < a ; i++)
            for ( int j = 0 ; j < b ; j++ )
        {
            if ( (i&j)<k)
                ans++;
        }
        printf("Case #%d: %lld\n",ca++,ans);
    }
    return  0 ;
}
