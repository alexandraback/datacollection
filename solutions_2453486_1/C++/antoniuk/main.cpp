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

char mas[ 5 ][ 5 ];

string solve()
{
    for( int i = 0 ; i < 4 ; ++i )
    {
        int cx , co , ct;
        cx = co = ct = 0;
        for( int j = 0 ; j < 4 ; ++j )
        {
            if( mas[i][j] == 'X' )
                ++cx;
            if( mas[i][j] == 'O' )
                ++co;
            if( mas[i][j] == 'T' )
                ++ct;
        }
        if( (cx == 4) || (cx == 3 && ct == 1) )
            return "X won";
        if( (co == 4) || (co == 3 && ct == 1) )
            return "O won";
    }
    for( int i = 0 ; i < 4 ; ++i )
    {
        int cx , co , ct;
        cx = co = ct = 0;
        for( int j = 0 ; j < 4 ; ++j )
        {
            if( mas[j][i] == 'X' )
                ++cx;
            if( mas[j][i] == 'O' )
                ++co;
            if( mas[j][i] == 'T' )
                ++ct;
        }
        if( (cx == 4) || (cx == 3 && ct == 1) )
            return "X won";
        if( (co == 4) || (co == 3 && ct == 1) )
            return "O won";
    }
    int cx , co , ct , cp;
    cx = co = ct = cp = 0;
    int cx1 , co1 , ct1;
    cx1 = co1 = ct1 = 0;
    for( int i = 0 ; i < 4 ; ++i )
        for( int j = 0 ; j < 4 ; ++j )
        {
            cp += (mas[i][j] == '.');
            if( i == j )
            {
                if( mas[j][i] == 'X' )
                    ++cx;
                if( mas[j][i] == 'O' )
                    ++co;
                if( mas[j][i] == 'T' )
                    ++ct;
            }
            if( i == (3-j) )
            {
                if( mas[j][i] == 'X' )
                    ++cx1;
                if( mas[j][i] == 'O' )
                    ++co1;
                if( mas[j][i] == 'T' )
                    ++ct1;
            }
        }
    if( (cx == 4) || (cx == 3 && ct == 1) )
        return "X won";
    if( (co == 4) || (co == 3 && ct == 1) )
        return "O won";
    if( (cx1 == 4) || (cx1 == 3 && ct1 == 1) )
        return "X won";
    if( (co1 == 4) || (co1 == 3 && ct1 == 1) )
        return "O won";
    if( cp == 0 )
        return "Draw";
    return "Game has not completed";
}

int main()
{
    ios::sync_with_stdio(0);
    freopen( "input.txt" , "r" , stdin );freopen( "output.txt" , "w" , stdout );
    int n;
    cin >> n;
    for( int g = 0 ; g < n ; ++g )
    {
        cout << "Case #" << 1+g << ": ";
        for( int i = 0 ; i < 4 ; ++i )
            for( int j = 0 ; j < 4 ; ++j )
            cin >> mas[i][j];
        cout << solve() << "\n";
    }
    return 0;
}
