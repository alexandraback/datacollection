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

bool pal( long long x )
{
    string s = "";
    while( x != 0 )
    {
        s += (char)(x%10+'0');
        x /= 10;
    }
    for( int i = 0 ; 2*i < s.length() ; ++i )
        if( s[i] != s[s.length()-1-i] )
        return false;
    return true;
}

bool chk( long long x )
{
    while( x != 0 )
    {
        if( x % 10 > 3 )
            return false;
        x /= 10;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    freopen( "input.txt" , "r" , stdin );freopen( "output1.txt" , "w" , stdout );

    int n;
    cin >> n;
    for( int d = 0 ; d < n ; ++d )
    {
        cout << "Case #" << d+1 << ": ";
        int ans = 0;

        long long a , b;
        cin >> a >> b;

        for( long long i = sqrt(a) ; i <= sqrt(b+1) ; ++i )
        if( i*i >= a && i*i <= b )
        if( chk(i) )
        if( pal(i) )
        if( pal(i*i) )
        {
            //cout << i << " " << i*i << "\n";
            ++ans;
        }

        cout << ans << endl;
    }

    return 0;
}
