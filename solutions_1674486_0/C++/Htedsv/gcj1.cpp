#include <iostream>
#include <cstdio>
#define N 1003
using namespace std;
bool sum[N][N];
bool f[N][N];
int num[N], out[N];
bool res;
int n;

void deep( int i, int ori )
{
    if ( out[i] == 0 )
    {
        if (sum[ori][i] )
            res = true;
        sum[ori][i] = true;
        return;
    }
    else
    {
        for ( int j = 1; j <= n; ++j )
            if (f[i][j] )
            {
                deep(j, ori);
                if (res) return;
            }
    }
}


int main()
{
    int T;
    scanf( "%d", &T );
    for ( int ca = 1; ca <= T; ++ca )
    {
        memset( f, 0, sizeof(f));
        memset( sum, 0, sizeof(sum));
        memset( num, 0, sizeof(num));
        memset( out, 0, sizeof(out));
        res = false;
        scanf( "%d", &n);
        for ( int i = 1; i <= n; ++i )
        {
            int k;
            scanf( "%d", &k );
            for ( int j = 1; j <= k; ++j )
            {
                int t;
                scanf( "%d", &t );
                f[i][t] = true;
                num[t]++;
                out[i]++;
            }
        }
        for ( int i = 1; i <= n; ++i )
        {
            if (num[i] == 0)
                deep(i, i);
            if ( res )
                break;
        }
        if (res)
            printf( "Case #%d: Yes\n", ca );
        else
            printf( "Case #%d: No\n", ca );


    }
}

