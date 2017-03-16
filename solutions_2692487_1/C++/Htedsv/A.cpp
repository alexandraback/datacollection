/**************************************
Author  : Htedsv
Time    :日  5/ 5 00:07:44 2013
FileName:A.cpp
Desc    :
*************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#define MIN -10000000
using namespace std;
int T, a[103], n, A;
int main()
{
    scanf( "%d", &T );
    for ( int I = 1; I <= T; ++I )
    {
        scanf( "%d%d", &A, &n );
        for ( int i = 0; i < n; ++i )
            scanf( "%d", &a[i] );
        sort( a, a+n);
        int ans = n, ti = 0;
        if ( A > 1)
        for ( int i = 0; i < n; ++i )
        {
            while( A <= a[i] )
                {
                    ti++;
                    A += A-1;
                }

            A += a[i];
            if ( ti + n-i-1 < ans )
                ans = ti + n-i-1;
        }
        printf( "Case #%d: %d\n", I, ans);
    }
}

            
