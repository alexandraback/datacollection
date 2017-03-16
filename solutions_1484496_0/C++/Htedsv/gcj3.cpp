#include <cstdio>
#include <cstring>
#include <iostream>
#define N 4000000
#define M 2000000
#define TT 500
using namespace std;

bool bl[N];
int que[N], opt[N];
int que1[TT], que2[TT];
int T;
int n, a[TT];
int main()
{
    scanf( "%d", &T );
    for ( int ca = 1; ca <= T; ++ca )
    {
        scanf( "%d", &n );
        memset( bl, 0, sizeof(bl));
        memset( opt, 0, sizeof(opt));
        int tail = 0;
        que[0] = 0; bl[0] = true;
        for ( int i = 0; i < n; ++i )
            scanf( "%d", &a[i] );
        for ( int i = 0; i < n; ++i )
        {
            if ( bl[a[i] + M])
            {
                opt[M] = -a[i];
                break;
            }
            else if ( bl[M-a[i]])
            {
                opt[M] = a[i];
                break;
            }
            else
            {
                int ttail = tail;
                for ( int j = 0; j <= tail; ++j )
                {
                    if ( !bl[que[j]+a[i]+M] )
                    {
                        bl[que[j]+a[i]+M] = true;
                        opt[que[j]+a[i]+M] = a[i];
                        que[++ttail] = que[j]+a[i];
                    }
                    if ( !bl[que[j]-a[i]+M] )
                    {
                        bl[que[j]-a[i]+M] = true;
                        opt[que[j]-a[i]+M] = -a[i];
                        que[++ttail] = que[j]-a[i];
                    }
                }
                tail = ttail;
            }
        }
        int ans = 0;
        bool fi = true;
        int len1 = 0, len2 = 0;
        while ( fi || ans != 0  )
        {
            fi = false;
            if ( opt[ans+M] > 0) 
            {
                que1[len1++] = opt[ans+M];
                ans -= opt[ans+M];
            }
            else
            {
                que2[len2++] = -opt[ans+M];
                ans -= opt[ans+M];
            }
        }
        printf( "Case #%d:\n", ca);
        for ( int i = 0; i < len1; ++i )
            printf( "%d ", que1[i]);
        printf( "\n");
        for ( int i = 0; i < len2; ++i )
            printf( "%d ", que2[i]);
        printf( "\n");

    }
}
            




                
            
