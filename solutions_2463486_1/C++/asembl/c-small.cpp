#include <iostream>
#include <cstdio>
using namespace std ;
const int MAXN = 1000000;

long long l , r ;
long long a[MAXN] , top = 0 ;

bool judge( long long x )
{
    long long a = x , b = 0 ;
    while ( x )
    {
        b = b * 10 + x % 10 ;
        x /= 10 ;
    }
    return a == b ;
}

int main()
{
    int test , T = 0 ;
    
    for ( long long i = 0 ; i <= 10000000 ; ++i )
        if ( judge(i) && judge( i*i ) )
        {
            a[top++] = i*i;
        }
    
    cin >> test ;
    while ( test-- )
    {
        cin >> l >> r ;
        --l ;
        
        printf("Case #%d: ",++T);
        printf("%d\n",upper_bound(a,a+top,r)-upper_bound(a,a+top,l));
    }
    return 0;
}
