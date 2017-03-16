#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    freopen("D-small-attempt1.in","r",stdin);
    freopen("D-small-attempt1.out","w",stdout);
    int T;
    long long k , c , s;
    scanf( "%d" , &T );
    for( int cas = 1 ; cas <= T ; cas++ )
    {
        scanf( "%I64d %I64d %I64d" , &k , &c , &s );
        long long t = min( k , c );
        long long num = ( k / t + ( k % t != 0 ? 1 : 0 ) );
        printf( "Case #%d:" , cas );
        if( num > s ) printf( " IMPOSSIBLE\n" );
        else
        {
            for( long long i=0 ; i<num ; i++ )
            {
                long long pre = t * i , poi = ( t * i ) + 1;
                for( long long j=1 ; j<c ; j++ )
                {
                    pre = pre * k;
                    if( j < c && poi < k ) poi++;
                    pre += poi - 1;
                }
                printf( " %I64d" , pre + 1 );
            }
            printf( "\n" );
        }
    }
    return 0;
}




/*
#define M 1010
using namespace std;
long long num[M] , inum[M][9] , dv[M][9];
int ln[M] , p = 0;
int team[M*50][2] , lln[M*50];
long long mk[9] , imk[9];
int nm[33] , ll = 32;
long long gcd( long long a , long long b )
{
    if( b == 0 ) return a;
    return gcd( b , a%b );
}
long long checkprime( long long tt )
{
    long long tn = (long long)sqrt( (double)tt );
    if( tt % 2 == 0 ) return 2;
    for( long long i=3 ; i<=tn ; i+=2 )
    {
        if( tt % i == 0 ) return i;
    }
    return -1;
}
int init()
{
    long long x = 1;
    int now = 0;
    p = 0;
    int ck14 = 0;
    while( 1 )
    {
        x += 2;
        long long y = x;
        int mln = 0;
        for( int i=0 ; i<ll ; i++ )
        {
            if( y != 0 ) mln++;
            nm[i] = y % 2;
            y /= 2;
        }
        if( y ) break;
        if( mln > 13 ) break;
        bool ck = true;
        for( int i=2 ; i<=10 ; i++ )
        {
            y = 0;
            for( int j=ll-1 ; j>=0 ; j-- )
            {
                y = y * i + nm[j];
                if( y < 0 ) return -1;
            }
            imk[i-2] = y;
            mk[i-2] = checkprime( y );
            if( mk[i-2] < 0 )
            {
                ck = false;
                break;
            }
        }
        if( ck )
        {
            num[p] = x;
            ln[p] = mln;
            for( int i=0 ; i<=8 ; i++ )
            {
                inum[p][i] = imk[i];
                dv[p][i] = mk[i];
            }
            if( ck14 < 500 )
            {
                for( int i=0 ; i<=p ; i++ )
                {
                    int sum = 0;
                    for( int j=0 ; j<=8 ; j++ )
                    {
                        if( gcd( inum[i][j] , inum[p][j] ) > 1 ) sum++;
                        else break;
                    }
                    if( sum >= 9 )
                    {
                        team[now][0] = i; team[now][1] = p;
                        lln[now] = ln[i] + ln[p];
                        if( lln[now] <= 14 ) ck14++;
                        now++;
                    }
                }
            }
            p++;
        }
    }
    //cout << p << " " << ln[p-1] << endl;
    return now;
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int kt = init();
    //cout << kt << " " << p << endl;
    int T , n , jj;
    scanf( "%d" , &T );
    for( int cas = 1 ; cas <= T ; cas++ )
    {
        scanf( "%d %d" , &n , &jj );
        printf( "Case #%d:\n" , cas );
        if( n <= 13 )
        {
            for( int i=0 ; i<p ; i++ )
            {
                if( jj <= 0 ) break;
                if( ln[i] != n ) continue;
                long long z[30];
                long long x = num[i];
                for( int j=0 ; j<n ; j++ )
                {
                    z[j] = x % 2;
                    x /= 2;
                }
                for( int j=n-1 ; j>=0 ; j-- ) printf( "%I64d" , z[j] );
                for( int j=0 ; j<9 ; j++ ) printf( " %I64d" , dv[i][j] );
                printf( "\n" );
                jj--;
            }
        }
        else
        {
            for( int i=0 ; i<kt ; i++ )
            {
                if( jj <= 0 ) break;
                if( lln[i] > n ) continue;
                int a = team[i][0] , b = team[i][1];
                long long z[30] , x;
                x = num[a];
                for( int j=0 ; j<ln[a] ; j++ )
                {
                    z[j] = x % 2;
                    x /= 2;
                }
                for( int j=ln[a]-1 ; j>=0 ; j-- ) printf( "%I64d" , z[j] );
                for( int j=0 ; j<n-ln[a]-ln[b] ; j++ ) printf( "0" );
                x = num[b];
                for( int j=0 ; j<ln[b] ; j++ )
                {
                    z[j] = x % 2;
                    x /= 2;
                }
                for( int j=ln[b]-1 ; j>=0 ; j-- ) printf( "%I64d" , z[j] );
                for( int j=0 ; j<9 ; j++ ) printf( " %I64d" , gcd( inum[a][j] , inum[b][j] ) );
                printf( "\n" );
                jj--;
            }
        }
    }
    return 0;
}
*/
