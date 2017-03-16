#include <cstdio>
#include <iostream>
using namespace std ;
int n , x , y ;
double ans ;
double c[2001][2001] ;

int main()
{
    int test , testnum = 0 ;
    int T , sum ;
    
    c[0][0] = 1 ;
    for ( int i = 1 ; i < 2001 ; ++i )
    {
        c[0][i] = c[i][i] = c[0][i-1] / 2 ;
        for ( int j = 1 ; j < i ; ++j )
        {
            c[j][i] = c[j][i-1] + c[j-1][i-1] ;
            c[j][i] /= 2 ;
        }
    }
    
    cin >> test ;
    while ( test -- )
    {
        cin >> n >> x >> y ;
        if ( x < 0 )
            x = -x ;
        
        for ( T = 0 ; ; ++T )
        {
            sum = T * ( 2*T-1 );
            if ( sum > n )
                break;
        }
        --T ;
        sum = T * ( 2*T-1 ) ;
        
        if ( (x+y) % 2 != 0 )
            ans = 0 ;
        else
        {
            int s = (x+y) / 2 ;
            
            if ( s <= T-1 )
                ans = 1 ;
            else if ( s >= T+1 )
                ans = 0 ;
            else
            {
                int left = n - sum ;
                ans = 0 ;
                
                if ( x == 0 )
                    ans = 1 ;
                else
                {
                    for ( int i = 0 ; i <= left && i <= y ; ++i )
                    if ( left-i <= T*2 || left-y <= T*2 )
                    {
                //        cout << c[i][left] << '\n' ;
                        ans += c[i][left] ;
                    }
                }
                ans = 1-ans ;
            }
        }
        
        printf("Case #%d: %.10f\n",++testnum,ans);
    }
    
    return 0;
}
