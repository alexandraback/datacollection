/**************************************
Author  : Htedsv
Time    :日  5/ 5 01:24:09 2013
FileName:B.cpp
Desc    :
*************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#define N 50
using namespace std;
bool bl[100][100];
int T, n, x, y;
double ans;
double deal(int nn, int xx, int yy, int x, int y)
{
    if (y < 0)
    {
        y = 0;
        while ( bl[0+N][y] ) y += 2;
    }
    if ( y == 0 || (bl[x-1+N][y-1] && bl[x+1+N][y-1]))
    {
        if ( x == xx && y == yy ) 
        {
            return 1.0;
        }
        else if (n == nn) return 0;
        else
        {
            int tx = x, ty = y;
            bl[tx+N][ty] = true;
            double tans =  deal(nn+1, xx, yy, 0, -1);
            bl[tx+N][ty] = false;
            return tans;
        }
    }
    else
    {
        if (bl[x-1+N][y-1])
        {
            double ans = deal(nn, xx, yy, x+1, y-1);
            return ans;
        }
        else if (bl[x+1+N][y-1])
        {
            double ans = deal(nn, xx, yy, x-1, y-1);
            return ans;
        }
        else{
            double ans = 0.5*deal(nn, xx, yy, x+1, y-1)+0.5*deal(nn, xx, yy, x-1, y-1);
            return ans;
        }
    }
}




int main()
{
    scanf( "%d", &T );
    for ( int I = 1; I <= T; ++I )
    {
        scanf( "%d%d%d", &n, &x, &y);
        memset(bl, 0, sizeof(bl));
        double ans = deal(1, x, y, 0, -1);
        printf( "Case #%d: %lf\n", I, ans);
    }

}
