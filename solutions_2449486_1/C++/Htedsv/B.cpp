/**************************************
Author  : Htedsv
Time    :六  4/13 10:15:15 2013
FileName:B.cpp
Desc    :
*************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int T, m, n, a[103][103];
bool mark[103][103];
int main()
{
    scanf( "%d", &T );
    for ( int I = 1; I <= T; ++I )
    {
        scanf( "%d%d", &m, &n );
        int mm = 0;
        for ( int i = 0; i < m; ++i )
            for ( int j = 0; j < n; ++j )
            {
                scanf( "%d",&a[i][j]);
                if (a[i][j] > mm ) mm = a[i][j];
            }
        bool error = false;
        
        for ( int k = 1; k <= mm; ++k )
        {
            memset( mark, 0, sizeof(mark));
            for ( int i = 0; i < m; ++i )
            {
                error = false;
                for ( int j = 0; j < n; ++j )
                    if (a[i][j] != k) { error = true; break; }
                if (!error)
                {
                    for ( int j = 0; j < n; ++j )
                        mark[i][j] = true;
                }
            }

            for ( int i = 0; i < n; ++i )
            {
                error = false;
                for ( int j = 0; j < m; ++j )
                    if (a[j][i] != k) { error = true; break; }
                if (!error)
                {
                    for ( int j = 0; j < m; ++j )
                        mark[j][i] = true;
                }
            }
            error = false;
            for ( int i = 0; i < m; ++i)
            {
                for ( int j = 0; j < n; ++j )
                {
                    if (a[i][j] == k && !mark[i][j])
                    {
                        error = true;
                        break;
                    }
                    if (a[i][j] == k) a[i][j]++;
                }
                if (error) break;
            }
                if (error) break;
        }
        if (error) printf( "Case #%d: NO\n", I);
        else printf( "Case #%d: YES\n", I);
    }
}


