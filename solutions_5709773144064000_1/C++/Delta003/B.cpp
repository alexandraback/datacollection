#include <cstdio>
#include <algorithm>

using namespace std;

int cases;
double for_farm, add, goal, curr, get, sol;

int main()
{
    freopen( "Blarge.in", "r", stdin );
    freopen( "sol.out", "w", stdout );
    scanf( "%d", &cases );
    for ( int k = 1; k <= cases; k++ )
    {
        scanf( "%lf %lf %lf", &for_farm, &add, &goal );
        curr = 0; get = 2; sol = 0;
        while ( true )
        {
            if ( curr < for_farm )
            {
                sol += ( for_farm - curr ) / get;
                curr = for_farm;
            }
            if ( goal / ( get + add ) < ( goal - curr ) / get )
            {
                curr = 0;
                get += add;
            }
            else
            {
                sol += ( goal - curr ) / get;
                break;
            }
        }
        printf( "Case #%d: %.7lf\n", k, sol );
    }
}
