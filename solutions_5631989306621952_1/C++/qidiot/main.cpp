#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
char str[1010];
struct node
{
    int num;
    int id;
    bool operator < ( node x ) const
    {
        return id < x.id;
    }
}tp[1010];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T , n;
    scanf( "%d" , &T );
    for( int cas = 1 ; cas <= T ; cas++ )
    {
        scanf( "%s" , str );
        int ln = strlen(str);
        for( int i=0 ; i<ln ; i++ )
        {
            tp[i].num = str[i] - 'A';
            tp[i].id = 0;
        }
        int top = 0 , now = 0 , mx = tp[0].num;
        for( int i=1 ; i<ln ; i++ )
        {
            if( tp[i].num >= mx )
            {
                tp[i].id = ( --top );
                mx = tp[i].num;
            }
            else
            {
                tp[i].id = ( ++now );
            }
        }
        sort( tp , tp + ln );
        printf( "Case #%d: " , cas );
        for( int i=0 ; i<ln ; i++ ) printf( "%c" , char( 'A' + tp[i].num ) );
        printf( "\n" );
    }
    return 0;
}
