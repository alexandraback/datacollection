#include <iostream>
#include <math.h>
#include <cmath>
#include <map>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int n , m;
int mas[ 110 ][ 110 ];

string solve()
{
    for( int i = 0 ; i < n ; ++i )
        for( int j = 0 ; j < m ; ++j )
        {
            bool f1 , f2;
            f1 = f2 = 1;

            for( int k = 0 ; k < m && f1 ; ++k )
            if( mas[i][j] < mas[i][k] )
                f1 = false;

            for( int k = 0 ; k < n && f2 ; ++k )
            if( mas[i][j] < mas[k][j] )
                f2 = false;

            if( !f1 && !f2 )
                return "NO";
        }
    return "YES";
}

int main()
{
    ios::sync_with_stdio(0);
    freopen( "input.txt" , "r" , stdin );freopen( "output.txt" , "w" , stdout );
    int G;
    cin >> G;
    for( int g = 0 ; g < G ; ++g )
    {
        cout << "Case #" << 1+g << ": ";
        cin >> n >> m;
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0 ; j < m ; ++j )
            cin >> mas[i][j];
        cout << solve() << "\n";
    }
    return 0;
}
