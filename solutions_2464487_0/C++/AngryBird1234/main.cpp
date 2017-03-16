#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
//#include <pair>
#include <algorithm>

using namespace std;
typedef long long LL;
int fk;
int main()
{
    freopen( "A-small-attempt0.in", "r", stdin );
    freopen( "A-small-attempt0.out", "w", stdout );
    int cas, t, r;
    scanf( "%d", &cas );
    while ( cas-- )
    {
        int cnt = 0;
        scanf( "%d %d", &r, &t );
        //while (  )
        for ( LL i = 1; ; i++ )
        {
            LL val = 2 * i * i + ( 2 * r - 1 ) * i;
            if ( val > t )
            {
                cout << "Case #" << ++fk << ": "<< i - 1 <<"\n";
                break;
            }
        }
    }
    return 0;
}
