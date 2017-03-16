#include <iostream>
#include <sstream>
#include <math.h>
#include <cmath>
#include <map>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int sq(int x1 , int y1 , int x2 , int y2 , int x3 , int y3)
{
    return abs(x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2));
}

bool in(int x1,int y1 , int x2 , int y2 , int x3 , int y3 , int x , int y)
{
    if(sq(x1,y1,x2,y2,x3,y3) == sq(x,y,x2,y2,x3,y3)+sq(x1,y1,x,y,x3,y3)+sq(x1,y1,x2,y2,x,y))
        return true;
    return false;
}

double C (double n, double k)
{
	double res = 1.0;
	for(double i = 1.0 ; i < k+1.0 ; ++i)
		res = (res * (n-k+i)) / (2.0*i);
    for( int i = k+1 ; i <= n ; ++i )
        res /= 2.0;
	return res;
}

int main()
{
    //ios::sync_with_stdio(0);
    freopen( "input.txt" , "r" , stdin );freopen( "output.txt" , "w" , stdout );

    long long t;
    cin >> t;
    for(long long F = 0 ; F < t ; ++F)
    {
        cout << "Case #" << F+1 << ": ";
        int n , x , y;
        cin >> n >> x >> y;
        int c = 0;
        for( int i = 1 ; ; i += 2 )
        {
            if( 2*n < i*(i+1) )
            {
                --i;--i;
                n -= (i*(i+1))/2;
                break;
            }

            ++c;
        }

        int x1 , y1 , x2 , y2 , x3 , y3;
        int h = 2*(c);
        x1 = y1 = 0;
        x2 = -(2*c-1);y2 = 0;
        x3 = 0; y3 = 2*c-1;
        if( in(x1,y1,x2,y2,x3,y3,x,y) || in(x1,y1,-x2,y2,x3,y3,x,y) )
            printf( "%.10lf\n" , 1.0 );
        else
        {
            x2 = -(2*(c+1)-1);y2 = 0;
            x3 = 0; y3 = 2*(c+1)-1;
            if( in(x1,y1,x2,y2,x3,y3,x,y) || in(x1,y1,-x2,y2,x3,y3,x,y) )
            {
                double d = 1.0;
                if( y == h )
                {
                    d = 1.0;
                }
                else
                {
                    ++y;
                    if( y > n )
                        d = 1.0;
                    else
                    if( h+y<=n )
                        d = 0;
                    else
                    {
                        d = 0.0;
                        for( int i = y ; i <= n ; ++i )
                            d += C(n,i);
                        d = 1.0-d;
                    }
                }
                printf( "%.10lf\n" , 1.0-d );
            }
            else
                printf( "%.10lf\n" , 0.0 );
        }

    }
    return 0;
}
