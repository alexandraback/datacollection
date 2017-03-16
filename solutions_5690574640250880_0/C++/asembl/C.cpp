#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
int n , m , c ;
int a[50][50] = {0};
int b[50][50] = {0};
int dir[8][2] = { 0,1,0,-1,1,0,-1,0,1,1,-1,1,-1,-1,1,-1 };

bool blank( int x , int y )
{
    for ( int l = 0 ; l < 8 ; ++l )
        if ( x+dir[l][0] >= 0 && x + dir[l][0] < n )
            if ( y+dir[l][1] >= 0 && y + dir[l][1] < m )
                if ( a[x+dir[l][0]][y+dir[l][1]] != 0 )
                    return false ;
    return true ;
}

int cc( int x , int y )
{
    if ( x < 0 || x >= n || y < 0 || y >= m ) return 0;
    if ( a[x][y] != 0 )
        return 0;
    if (b[x][y] == 1 )
        return 0 ;
    b[x][y] = 1 ;

    int res = 1 ;
    if ( blank(x,y) )
    for ( int i = 0 ; i < 8 ; ++i )
        res += cc( x+dir[i][0] , y+dir[i][1] );
    return res ;
}

bool dfs( int row , int col , int cnt )
{
    if (cnt < 0) return false ;

    if ( row == n  )
    {
        if ( cnt == 0 )
        for ( int i = 0 ; i < n ; ++i )
            for ( int j = 0 ; j < m ; ++j )
            if ( a[i][j] == 0 )
            {
                memset( b , 0 , sizeof b );
                if (cc(i,j) == n*m-c)
                {
                    a[i][j] = 2 ;
                    return true ;
                }
            }
        return false;
    }
    int rown , coln ;

    if ( col == m-1 )
        rown = row+1 , coln = 0 ;
    else
        rown = row , coln = col+1 ;

    if ( dfs( rown , coln , cnt ) )
        return true ;

    a[row][col] = 1 ;
    if ( dfs( rown , coln , cnt-1) ) {

        return true ;
    }
    a[row][col] = 0 ;

    return false ;
}

int main()
{
    int T , test = 0 ;;

    cin >> T ;
    while ( T-- )
    {
        test ++ ;
        cin >> n>> m >> c ;

        printf("Case #%d:\n",test);
        memset( a , 0 , sizeof a ) ;
        if ( dfs(0,0,c) )
        {
            for ( int i = 0 ; i < n ; ++i )
            {
                for ( int j = 0 ; j < m ; ++j )
                {
                    if ( a[i][j] == 1 )
                        cout << '*' ;
                    else if ( a[i][j] == 2 )
                        cout << 'c' ;
                    else
                        cout << '.' ;
                }
                cout << '\n' ;
            }
        }
        else
            cout << "Impossible\n";
    }

    return 0;
}
