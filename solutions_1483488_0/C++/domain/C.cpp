#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C.out","w",stdout);
    int T;
    scanf( "%d", &T );
    int a, b;
    for ( int ca = 1; ca <= T; ++ca )
    {
        scanf( "%d%d", &a, &b);
        int digit = 1;
        int ta = a;
        while ( ta > 0 )
        {
            ta /= 10;
            digit *= 10;
        }
        digit /= 10;
        int ans = 0;
        for ( int i = a; i <= b; ++i )
        {
            int t = i;
            do
            {
                t = (t%10)*digit + t/10;
                if ( t <=b && t > i ) ans++;
            }while( t != i );
        }
        printf( "Case #%d: %d\n", ca, ans);
    }
}
                

