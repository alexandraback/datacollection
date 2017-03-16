#include <cstdio>
using namespace std;
int n , m ;
int a[15][15] ;
int visit[15][15] ;

bool judge( int x , int y )
{
    bool res = true ;
    
    for ( int i = 1 ; i <= n ; ++i )
        if ( a[i][y] != 1 )
            res = false ;
    if ( res )
        return res ;
    res = true ;
    for ( int j = 1 ; j <= m ; ++j )
        if ( a[x][j] != 1 )
            res = false ;
    return res ;
}

int main()
{
    int test ;
    int ttt=0;
    
    scanf("%d",&test);
    for ( int T = 1 ; T <= test ; ++T )
    {
        scanf("%d%d",&n,&m);
        for ( int i = 1 ; i <= n ; ++i )
            for ( int j = 1 ; j <= m ; ++j )
            {
                scanf("%d",&a[i][j]);
                visit[i][j] = 0 ;
            }
        
        bool ans = true ;
        
        for ( int i = 1 ; i <= n ; ++i )
            for ( int j = 1 ; j <= m ; ++j )
                if ( a[i][j] == 1 )
                    if ( judge(i,j) == false )
                        ans = false ;
        /*
        for ( int i = 2 ; i < n ; ++i )
            if ( a[i][1] == 1 || a[i][m] == 1 )
                for ( int j = 1 ; j <= m ; ++j )
                {
                    if ( a[i][j] != 1 )
                        ans = false ;
                    visit[i][j] = 1 ;
                }
        for ( int j = 2 ; j < m ; ++j )
            if ( a[1][j] == 1 || a[n][j] == 1 )
                for ( int i = 1 ; i <= n ; ++i )
                {
                    if ( a[i][j] != 1 )
                        ans = false ;
                    visit[i][j] = 1 ;
                }
        if ( a[1][1] == 1 )
            if ( !judge(1,1) )
                ans = false ;
        if ( a[1][m] == 1 )
            if ( !judge(1,m) )
                ans = false ;
        if ( a[n][1] == 1 )
            if ( !judge(n,1) )
                ans = false ;
        if ( a[n][m] == 1 )
            if ( !judge(n,m) )
                ans = false ;
        
        for ( int i = 2 ; i < n ; ++i )
            for ( int j = 2 ; j < m ; ++j )
                if ( a[i][j] == 1 && visit[i][j] != 1 )
                    ans = false ;
        */
        printf("Case #%d: ",++ttt);
        if ( ans )
            printf("YES\n");
        else
            printf("NO\n");
        
    }
    return 0;
}
