#include <cstdio>
using namespace std;
int n , m ;
int a[150][150] ;
int visit[150][150] ;

bool judge( int x , int y , int key)
{
    bool res1 = true , res2 = true;
    
    for ( int i = 1 ; i <= n ; ++i )
        if ( a[i][y] != key && visit[i][y] == 0 )
            res1 = false ;
    if ( res1 )
    {
        for ( int i = 1 ; i <= n ; ++i )
            visit[i][y] = 1 ;
    }
    for ( int j = 1 ; j <= m ; ++j )
        if ( a[x][j] != key && visit[x][j] == 0 )
            res2 = false ;
    if ( res2 )
    {
        for ( int j = 1 ; j <= m ; ++j )
            visit[x][j] = 1 ;
    }
    return res1 || res2 ;
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
        
        for ( int k = 1 ; k <= 100 ; ++k )
            for ( int i = 1 ; i <= n ; ++i )
                for ( int j = 1 ; j <= m ; ++j )
                    if ( a[i][j] == k )
                        if ( judge(i,j,k) == false )
                            ans = false ;
        
        printf("Case #%d: ",++ttt);
        if ( ans )
            printf("YES\n");
        else
            printf("NO\n");
        
    }
    return 0;
}
