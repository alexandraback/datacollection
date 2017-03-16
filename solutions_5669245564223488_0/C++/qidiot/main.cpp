#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#define MOD 1000000007
using namespace std;
char ch[110][110];
bool ck[30];
int a[110] , b[110];
int p1[30] , p2[30] , sa[30];
long long n1( int pp )
{
    long long ans = 1;
    long long p = (long long)pp;
    while( p > 1 )
    {
        ans = ans * p % MOD;
        p--;
    }
    return ans;
}
long long solve( int n , int now , int t )
{
    ck[now] = 1;
    long long ans = 1;
    ans = ans * n1( sa[now] ) % MOD;
    for( int i=0 ; i<n ; i++ )
        if( a[i] == now && a[i] != b[i] )
        {
            return ans * solve( n , b[i] , t ) % MOD;
        }
    for( int i=0 ; i<26 ; i++ )
        if( !ck[i] && p1[i] == 1 && p2[i] == 0 )
        {
            return ans * solve( n , i , t+1 ) % MOD;
        }
    int p = t;
    for( int i=0 ; i<26 ; i++ )
    {
        if( !ck[i] && sa[i] > 0 )
        {
            ans = ans * n1( sa[i] ) % MOD;
            p++;
        }
    }
    return ans * n1( p ) % MOD;
}
int main()
{
    freopen("B-small-attempt5.in" , "r", stdin);
    freopen("out.txt", "w", stdout);
    int T , n;
    scanf( "%d" , &T );
    for( int cas=1 ; cas<=T ; cas++ )
    {
        scanf( "%d" , &n );
        for( int i=0 ; i<n ; i++ ) scanf( "%s" , ch[i] );

        memset( ck , 0 , sizeof( ck ) );
        bool q = 1;
        for( int i=0 ; i<n ; i++ )
        {
            int ln = strlen( ch[i] );
            int ll = 0;
            while( ll < ln && ch[i][ll] == ch[i][ll+1] ) ll++;
            int rr = ln - 1;
            while( rr > 0 && ch[i][rr] == ch[i][rr-1] ) rr--;
            for( int j=ll+1 ; j<rr ; j++ )
                if( ch[i][j] != ch[i][j-1] )
                {
                    if( ck[ ch[i][j] - 'a' ] ) q = 0;
                    ck[ ch[i][j] - 'a' ] = 1;
                }
        }
        for( int i=0 ; i<n ; i++ )
        {
            int ln = strlen( ch[i] );
            if( ck[ ch[i][0] - 'a' ] ) q = 0;
            if( ck[ ch[i][ln-1] - 'a' ] ) q = 0;
            ch[i][1] = ch[i][ln-1];
        }
        if( !q ) printf( "Case #%d: 0\n" , cas );
        else
        {
            for( int i=0 ; i<n ; i++ )
            {
                a[i] = ch[i][0] - 'a';
                b[i] = ch[i][1] - 'a';
            }
            memset( p1 , 0 , sizeof( p1 ) );
            memset( p2 , 0 , sizeof( p2 ) );
            memset( sa , 0 , sizeof( sa ) );
            for( int i=0 ; i<n ; i++ )
            {
                if( a[i] == b[i] ) sa[ a[i] ]++;
                else
                {
                    p1[ a[i] ]++; p2[ b[i] ]++;
                }
            }
            int qq = 1;
            for( int i=0 ; i<26 ; i++ )
            {
                if( p1[i] > 1 || p2[i] > 1 ) qq = 0;
            }
            if( !qq ) printf( "Case #%d: 0\n" , cas );
            else
            {
                long long ans = 0;
                bool pp = 0 , qp = 0;
                for( int i=0 ; i<26 ; i++ )
                {
                    if( p1[i] == 1 && p2[i] == 0 )
                    {
                        pp = 1;
                        memset( ck , 0 , sizeof( ck ) );
                        ans = solve( n , i , 1 );
                        break;
                    }
                }
                if( !pp )
                {
                    for( int i=0 ; i<26 ; i++ )
                        if( p1[i] > 0 ) qp = 1;
                    if( qp ) ans = 0;
                    else
                    {
                        for( int i=0 ; i<26 ; i++ )
                            if( sa[i] > 0 )
                            {
                                memset( ck , 0 , sizeof( ck ) );
                                ans = solve( n , i , 1 );
                            }
                    }

                }
                printf( "Case #%d: %I64d\n" , cas , ans );
            }

        }
    }
    return 0;
}
