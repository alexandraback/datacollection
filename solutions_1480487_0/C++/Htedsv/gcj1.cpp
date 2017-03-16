#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 1000
int f[N];
double g[N], tg[N];
using namespace std;
int main()
{
    int T;
    scanf( "%d", &T );
    int n, sum;
    for ( int ca = 1; ca <= T; ++ca )
    {
        scanf( "%d", &n );
        sum = 0;
        for (int j = 0; j < n; ++j )
        {
            scanf( "%d", &f[j]);
            sum += f[j];
        }
        double mm = 0;
        for (int j = 0; j < n; ++j )
        {
            g[j] = double(f[j]) / sum *100;
            if ( g[j] > mm ) mm = g[j];
            tg[j] = g[j];
        }
        sort(tg, tg+n);
        double aa = 0, ll = 0;
        for ( int j = 1; j < n; ++j )
        {
            double tmp = aa+j*(tg[j]-tg[j-1]);
            if ( tmp <= 100 )
                aa = tmp;
            else
            {
                ll = tg[j-1] + (100-aa)/j;
                aa = 0;
                break;
            }
        }
        if ( ll == 0 )
            ll = tg[n-1] + (100-aa)/n;

       // printf( "%lf!", ll);


        printf( "Case #%d:", ca);
        for ( int j = 0; j < n; ++j )
        {
            if  ( g[j] < ll )
                printf( " %lf", ll - g[j]);
            else
                printf( " %lf", 0.0);
        }
            
        printf( "\n");


    }
}
