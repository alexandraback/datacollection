#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main()
{
    freopen( "B-small-attempt0.in", "r", stdin );
    freopen( "B-small-attempt0.out", "w", stdout );
    
    int t, x, y;
    
    cin >> t;
    
    for ( int i = 0; i < t; i++ )
    {
        cin >> x >> y;
        
        string xc, yc;
        
        if ( x >= 0 ) xc = "WE";
        else xc = "EW";
        
        if ( y >= 0 ) yc = "SN";
		else yc = "NS";

		cout << "Case #" << i + 1 << ": ";

		x = abs( x );
		y = abs( y );

		for (int i = 0; i < x; i++)
		{
			cout << xc;
		}

		for (int i = 0; i < y; i++)
		{
			cout << yc;
		}

		cout << endl;
    }
    
    
    //system("pause");
    return 0;
}